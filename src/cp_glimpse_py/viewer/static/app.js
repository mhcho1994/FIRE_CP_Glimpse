"use strict";

const palette = ["#2775c9", "#d17724", "#17845a", "#8d5ac7", "#cc4355", "#2e9ba6", "#8b6b3f", "#526ed3"];
const state = {
  runId: null,
  detail: null,
  simulation: null,
  time: [],
  signals: [],
  selected: new Set(),
  cursor: 0,
  timer: null,
  axis: {xMin: null, xMax: null, yMin: null, yMax: null},
};

const elements = Object.fromEntries([
  "message", "viewer", "run-select", "refresh-runs", "summary-row", "signal-count",
  "signal-search", "select-outputs", "clear-signals", "signal-list", "legend", "chart",
  "chart-empty", "play", "time-slider", "cursor-readout", "values-body", "artifact-links",
  "axis-controls", "x-min", "x-max", "y-min", "y-max", "reset-axes",
].map(id => [id, document.getElementById(id)]));

async function fetchJSON(url) {
  const response = await fetch(url, {cache: "no-store"});
  if (!response.ok) {
    let message = `HTTP ${response.status}`;
    try { message = (await response.json()).error || message; } catch {}
    throw new Error(message);
  }
  return response.json();
}

function simulationResult(payload) {
  let value = payload;
  for (let depth = 0; depth < 4; depth += 1) {
    if (Array.isArray(value?.time)) return value;
    if (!value || typeof value.result !== "object") break;
    value = value.result;
  }
  throw new Error("result.json does not contain a simulation time series");
}

function numeric(value) {
  const number = typeof value === "number" ? value : Number(value);
  return Number.isFinite(number) ? number : null;
}

function formatValue(value) {
  const number = numeric(value);
  if (number === null) return value == null ? "—" : String(value);
  if (number === 0) return "0";
  if (Math.abs(number) >= 1e5 || Math.abs(number) < 1e-4) return number.toExponential(4);
  return Number(number.toPrecision(7)).toString();
}

function formatDuration(value) {
  const number = numeric(value);
  if (number === null) return "—";
  return number < 1 ? `${Math.round(number * 1000)} ms` : `${number.toFixed(2)} s`;
}

function signalStats(values) {
  const numbers = values.map(numeric).filter(value => value !== null);
  return {
    numeric: numbers.length > 0,
    min: numbers.length ? Math.min(...numbers) : null,
    max: numbers.length ? Math.max(...numbers) : null,
    final: values.at(-1),
  };
}

function buildSignals(simulation) {
  const signals = [];
  for (const [kind, values] of [["output", simulation.outputs], ["input", simulation.inputs]]) {
    if (!values || typeof values !== "object") continue;
    for (const [name, samples] of Object.entries(values)) {
      if (!Array.isArray(samples)) continue;
      signals.push({key: `${kind}:${name}`, name, kind, values: samples, stats: signalStats(samples)});
    }
  }
  return signals;
}

function metric(label, value, className = "") {
  const item = document.createElement("div");
  item.className = "metric";
  const caption = document.createElement("span");
  caption.textContent = label;
  const strong = document.createElement("strong");
  strong.textContent = value ?? "—";
  if (className) strong.className = className;
  item.append(caption, strong);
  return item;
}

function renderSummary() {
  const detail = state.detail;
  const sim = state.simulation;
  const summary = detail.summary || {};
  const metadata = sim.metadata || {};
  const topResult = detail.result || {};
  const status = String(sim.status || topResult.status || summary.status || "unknown");
  const backend = sim.backend || metadata.backend || summary.sim?.backend;
  const composition = sim.composition || topResult.composition || summary.composition;
  const fmuType = sim.fmu_type || summary.sim?.fmu_type;
  const t0 = state.time.at(0);
  const tf = state.time.at(-1);
  const duration = t0 == null || tf == null ? "—" : `${formatValue(t0)} – ${formatValue(tf)} s`;
  const wallTime = metadata.wall_time_sec ?? summary.wall_time_sec ?? topResult.metadata?.wall_time_sec;

  elements["summary-row"].replaceChildren(
    metric("Status", status.toUpperCase(), status.toLowerCase()),
    metric("Composition", composition),
    metric("Backend", backend),
    metric("FMU type", fmuType?.toUpperCase()),
    metric("Simulation", duration),
    metric("Samples / wall", `${state.time.length.toLocaleString()} / ${formatDuration(wallTime)}`),
  );
}

function createSignalGroup(title, signals) {
  const section = document.createElement("section");
  section.className = "signal-group";
  const heading = document.createElement("h3");
  heading.textContent = `${title} (${signals.length})`;
  section.append(heading);
  for (const signal of signals) {
    const label = document.createElement("label");
    label.className = "signal-item";
    label.dataset.search = signal.name.toLowerCase();
    const checkbox = document.createElement("input");
    checkbox.type = "checkbox";
    checkbox.checked = state.selected.has(signal.key);
    checkbox.addEventListener("change", () => {
      if (checkbox.checked) state.selected.add(signal.key);
      else state.selected.delete(signal.key);
      renderSelection();
    });
    const dot = document.createElement("span");
    dot.className = `kind-dot ${signal.kind}`;
    const text = document.createElement("span");
    text.textContent = signal.name;
    label.append(checkbox, dot, text);
    section.append(label);
  }
  return section;
}

function renderSignalList() {
  const outputs = state.signals.filter(signal => signal.kind === "output");
  const inputs = state.signals.filter(signal => signal.kind === "input");
  const children = [];
  if (outputs.length) children.push(createSignalGroup("Outputs", outputs));
  if (inputs.length) children.push(createSignalGroup("Inputs", inputs));
  elements["signal-list"].replaceChildren(...children);
  elements["signal-count"].textContent = `${state.signals.length} available`;
  filterSignals();
}

function selectedSignals() {
  return state.signals.filter(signal => state.selected.has(signal.key));
}

function renderLegend(signals) {
  const items = signals.map((signal, index) => {
    const item = document.createElement("span");
    item.className = "legend-item";
    const line = document.createElement("span");
    line.className = `legend-line ${signal.kind}`;
    line.style.backgroundColor = signal.kind === "input" ? "transparent" : palette[index % palette.length];
    line.style.color = palette[index % palette.length];
    const text = document.createElement("span");
    text.textContent = signal.name;
    item.append(line, text);
    return item;
  });
  elements.legend.replaceChildren(...items);
}

function drawChart() {
  const canvas = elements.chart;
  const ctx = canvas.getContext("2d");
  const width = Math.max(canvas.clientWidth, 300);
  const height = Math.max(canvas.clientHeight, 260);
  const ratio = window.devicePixelRatio || 1;
  if (canvas.width !== Math.round(width * ratio) || canvas.height !== Math.round(height * ratio)) {
    canvas.width = Math.round(width * ratio);
    canvas.height = Math.round(height * ratio);
  }
  ctx.setTransform(ratio, 0, 0, ratio, 0, 0);
  ctx.clearRect(0, 0, width, height);

  const signals = selectedSignals().filter(signal => signal.stats.numeric);
  elements["chart-empty"].hidden = signals.length > 0;
  if (!signals.length || !state.time.length) return;

  const margin = {left: 70, right: 24, top: 18, bottom: 45};
  const plotWidth = width - margin.left - margin.right;
  const plotHeight = height - margin.top - margin.bottom;
  const automaticTMin = numeric(state.time[0]) ?? 0;
  const automaticTMax = numeric(state.time.at(-1)) ?? automaticTMin + 1;
  const tMin = state.axis.xMin ?? automaticTMin;
  const tMax = state.axis.xMax ?? automaticTMax;
  let yMin = Math.min(...signals.map(signal => signal.stats.min));
  let yMax = Math.max(...signals.map(signal => signal.stats.max));
  if (yMin === yMax) {
    const padding = Math.abs(yMin || 1) * 0.1;
    yMin -= padding;
    yMax += padding;
  } else {
    const padding = (yMax - yMin) * 0.06;
    yMin -= padding;
    yMax += padding;
  }
  yMin = state.axis.yMin ?? yMin;
  yMax = state.axis.yMax ?? yMax;
  if (yMin >= yMax) {
    const padding = Math.max(Math.abs(yMin || yMax || 1) * 0.1, 1e-6);
    if (state.axis.yMin !== null && state.axis.yMax === null) yMax = yMin + padding;
    else if (state.axis.yMax !== null && state.axis.yMin === null) yMin = yMax - padding;
  }
  const xFor = time => margin.left + ((time - tMin) / (tMax - tMin || 1)) * plotWidth;
  const yFor = value => margin.top + (1 - (value - yMin) / (yMax - yMin)) * plotHeight;

  ctx.font = "12px system-ui, sans-serif";
  ctx.lineWidth = 1;
  ctx.textBaseline = "middle";
  for (let index = 0; index <= 5; index += 1) {
    const fraction = index / 5;
    const x = margin.left + fraction * plotWidth;
    const y = margin.top + fraction * plotHeight;
    ctx.strokeStyle = "#e4e9ef";
    ctx.beginPath(); ctx.moveTo(x, margin.top); ctx.lineTo(x, margin.top + plotHeight); ctx.stroke();
    ctx.beginPath(); ctx.moveTo(margin.left, y); ctx.lineTo(margin.left + plotWidth, y); ctx.stroke();
    ctx.fillStyle = "#6a788b";
    ctx.textAlign = "center";
    ctx.fillText(formatValue(tMin + fraction * (tMax - tMin)), x, height - 20);
    ctx.textAlign = "right";
    ctx.fillText(formatValue(yMax - fraction * (yMax - yMin)), margin.left - 10, y);
  }
  ctx.fillStyle = "#6a788b";
  ctx.textAlign = "center";
  ctx.fillText("simulation time (s)", margin.left + plotWidth / 2, height - 4);

  ctx.save();
  ctx.beginPath();
  ctx.rect(margin.left, margin.top, plotWidth, plotHeight);
  ctx.clip();

  const stride = Math.max(1, Math.ceil(state.time.length / Math.max(500, plotWidth * 2)));
  signals.forEach((signal, signalIndex) => {
    ctx.strokeStyle = palette[signalIndex % palette.length];
    ctx.lineWidth = 2;
    ctx.setLineDash(signal.kind === "input" ? [7, 5] : []);
    ctx.beginPath();
    let started = false;
    for (let index = 0; index < state.time.length; index += stride) {
      const value = numeric(signal.values[index]);
      const time = numeric(state.time[index]);
      if (value === null || time === null) { started = false; continue; }
      const x = xFor(time), y = yFor(value);
      if (started) ctx.lineTo(x, y); else { ctx.moveTo(x, y); started = true; }
    }
    const lastIndex = state.time.length - 1;
    if (lastIndex % stride !== 0) {
      const value = numeric(signal.values[lastIndex]);
      const time = numeric(state.time[lastIndex]);
      if (value !== null && time !== null) ctx.lineTo(xFor(time), yFor(value));
    }
    ctx.stroke();
  });
  ctx.setLineDash([]);

  const cursorTime = numeric(state.time[state.cursor]);
  if (cursorTime !== null && cursorTime >= tMin && cursorTime <= tMax) {
    const cursorX = xFor(cursorTime);
    ctx.strokeStyle = "#23364b";
    ctx.lineWidth = 1;
    ctx.beginPath(); ctx.moveTo(cursorX, margin.top); ctx.lineTo(cursorX, margin.top + plotHeight); ctx.stroke();
    signals.forEach((signal, signalIndex) => {
      const value = numeric(signal.values[state.cursor]);
      if (value === null) return;
      ctx.fillStyle = palette[signalIndex % palette.length];
      ctx.beginPath(); ctx.arc(cursorX, yFor(value), 4, 0, Math.PI * 2); ctx.fill();
    });
  }
  ctx.restore();
}

function resetAxes() {
  state.axis = {xMin: null, xMax: null, yMin: null, yMax: null};
  for (const id of ["x-min", "x-max", "y-min", "y-max"]) elements[id].value = "";
  drawChart();
}

function axisInput(id) {
  const value = elements[id].value.trim();
  if (value === "") return null;
  const number = Number(value);
  return Number.isFinite(number) ? number : null;
}

function applyAxes() {
  const next = {
    xMin: axisInput("x-min"),
    xMax: axisInput("x-max"),
    yMin: axisInput("y-min"),
    yMax: axisInput("y-max"),
  };
  for (const id of ["x-min", "x-max", "y-min", "y-max"]) elements[id].setCustomValidity("");
  const effectiveXMin = next.xMin ?? numeric(state.time[0]);
  const effectiveXMax = next.xMax ?? numeric(state.time.at(-1));
  if ((next.xMin !== null || next.xMax !== null) && effectiveXMin !== null && effectiveXMax !== null && effectiveXMin >= effectiveXMax) {
    elements["x-max"].setCustomValidity("X max must be greater than X min.");
    elements["x-max"].reportValidity();
    return;
  }
  const numericSignals = selectedSignals().filter(signal => signal.stats.numeric);
  const automaticYMin = numericSignals.length ? Math.min(...numericSignals.map(signal => signal.stats.min)) : null;
  const automaticYMax = numericSignals.length ? Math.max(...numericSignals.map(signal => signal.stats.max)) : null;
  const effectiveYMin = next.yMin ?? automaticYMin;
  const effectiveYMax = next.yMax ?? automaticYMax;
  if ((next.yMin !== null || next.yMax !== null) && effectiveYMin !== null && effectiveYMax !== null && effectiveYMin >= effectiveYMax) {
    elements["y-max"].setCustomValidity("Y max must be greater than Y min.");
    elements["y-max"].reportValidity();
    return;
  }
  state.axis = next;
  drawChart();
}

function renderValues() {
  const rows = selectedSignals().map(signal => {
    const row = document.createElement("tr");
    const name = document.createElement("td");
    name.textContent = signal.name;
    const kind = document.createElement("td");
    const pill = document.createElement("span");
    pill.className = `kind-pill ${signal.kind}`;
    pill.textContent = signal.kind;
    kind.append(pill);
    const values = [
      signal.values[state.cursor], signal.stats.min, signal.stats.max, signal.stats.final,
    ].map(value => {
      const cell = document.createElement("td");
      cell.textContent = formatValue(value);
      return cell;
    });
    row.append(name, kind, ...values);
    return row;
  });
  elements["values-body"].replaceChildren(...rows);
}

function updateCursor(index) {
  state.cursor = Math.max(0, Math.min(Number(index), state.time.length - 1));
  elements["time-slider"].value = String(state.cursor);
  const t = state.time[state.cursor];
  elements["cursor-readout"].textContent = t == null ? "—" : `t = ${formatValue(t)} s · sample ${state.cursor + 1}/${state.time.length}`;
  drawChart();
  renderValues();
}

function stopPlayback() {
  if (state.timer !== null) window.clearInterval(state.timer);
  state.timer = null;
  elements.play.textContent = "▶ Replay";
}

function renderSelection() {
  stopPlayback();
  const signals = selectedSignals();
  renderLegend(signals);
  renderValues();
  drawChart();
}

function renderArtifacts() {
  const links = (state.detail.artifacts || []).map(filename => {
    const link = document.createElement("a");
    link.href = `/api/runs/${encodeURIComponent(state.runId)}/artifacts/${encodeURIComponent(filename)}`;
    link.textContent = filename;
    link.download = filename;
    return link;
  });
  elements["artifact-links"].replaceChildren(...links);
}

function defaultSelection() {
  state.selected.clear();
  const outputs = state.signals.filter(signal => signal.kind === "output" && signal.stats.numeric).slice(0, 3);
  const inputs = state.signals.filter(signal => signal.kind === "input" && signal.stats.numeric).slice(0, 1);
  [...outputs, ...inputs].forEach(signal => state.selected.add(signal.key));
}

async function loadRun(runId) {
  stopPlayback();
  elements.message.hidden = false;
  elements.message.classList.remove("error");
  elements.message.textContent = `Loading ${runId}…`;
  elements.viewer.hidden = true;
  try {
    const detail = await fetchJSON(`/api/runs/${encodeURIComponent(runId)}`);
    state.runId = runId;
    state.detail = detail;
    state.simulation = simulationResult(detail.result);
    state.time = state.simulation.time;
    state.signals = buildSignals(state.simulation);
    state.cursor = Math.max(0, state.time.length - 1);
    resetAxes();
    defaultSelection();
    renderSummary();
    renderSignalList();
    renderArtifacts();
    elements["time-slider"].max = String(Math.max(0, state.time.length - 1));
    elements.message.hidden = true;
    elements.viewer.hidden = false;
    updateCursor(state.cursor);
    renderSelection();
  } catch (error) {
    elements.message.hidden = false;
    elements.message.classList.add("error");
    elements.message.textContent = `Cannot load ${runId}: ${error.message}`;
  }
}

async function loadRuns(keepSelection = true) {
  const previous = keepSelection ? state.runId : null;
  try {
    const {runs} = await fetchJSON("/api/runs");
    const options = runs.map(run => {
      const option = document.createElement("option");
      option.value = run.id;
      option.textContent = `${run.id} · ${String(run.status || "unknown").toUpperCase()}`;
      return option;
    });
    elements["run-select"].replaceChildren(...options);
    if (!runs.length) {
      stopPlayback();
      elements.viewer.hidden = true;
      elements.message.hidden = false;
      elements.message.textContent = "No result.json files were found under the selected results directory.";
      return;
    }
    const selected = runs.some(run => run.id === previous) ? previous : runs[0].id;
    elements["run-select"].value = selected;
    await loadRun(selected);
  } catch (error) {
    elements.viewer.hidden = true;
    elements.message.hidden = false;
    elements.message.classList.add("error");
    elements.message.textContent = `Cannot list results: ${error.message}`;
  }
}

function filterSignals() {
  const query = elements["signal-search"].value.trim().toLowerCase();
  document.querySelectorAll(".signal-item").forEach(item => {
    item.hidden = Boolean(query) && !item.dataset.search.includes(query);
  });
}

elements["run-select"].addEventListener("change", event => loadRun(event.target.value));
elements["refresh-runs"].addEventListener("click", () => loadRuns(true));
elements["signal-search"].addEventListener("input", filterSignals);
elements["clear-signals"].addEventListener("click", () => {
  state.selected.clear(); renderSignalList(); renderSelection();
});
elements["select-outputs"].addEventListener("click", () => {
  state.selected = new Set(state.signals.filter(signal => signal.kind === "output" && signal.stats.numeric).map(signal => signal.key));
  renderSignalList(); renderSelection();
});
elements["time-slider"].addEventListener("input", event => {
  stopPlayback(); updateCursor(event.target.value);
});
elements["axis-controls"].addEventListener("submit", event => {
  event.preventDefault();
  applyAxes();
});
elements["reset-axes"].addEventListener("click", resetAxes);
elements.play.addEventListener("click", () => {
  if (state.timer !== null) { stopPlayback(); return; }
  if (state.cursor >= state.time.length - 1) updateCursor(0);
  elements.play.textContent = "Ⅱ Pause";
  const advance = Math.max(1, Math.ceil(state.time.length / 300));
  state.timer = window.setInterval(() => {
    updateCursor(Math.min(state.cursor + advance, state.time.length - 1));
    if (state.cursor >= state.time.length - 1) stopPlayback();
  }, 50);
});

new ResizeObserver(drawChart).observe(elements.chart);
loadRuns(false);
