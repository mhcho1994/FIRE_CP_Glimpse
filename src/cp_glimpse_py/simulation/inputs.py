"""Scenario-defined input providers for simulation executors."""

from __future__ import annotations

from abc import ABC, abstractmethod
from bisect import bisect_right
from dataclasses import dataclass
from numbers import Real
from typing import Any


class InputProvider(ABC):
    """Provide named external input values at a requested simulation time."""

    @property
    @abstractmethod
    def input_names(self) -> tuple[str, ...]:
        """Return the input variable names provided by this instance."""

    @abstractmethod
    def value_at(self, t: float) -> dict[str, Any]:
        """Return all external input values at time ``t``."""

    @abstractmethod
    def signal_points(self) -> tuple[list[float], dict[str, list[Any]]]:
        """Return time/value points, including duplicate times for discontinuities."""

    @abstractmethod
    def describe(self) -> dict[str, Any]:
        """Return a JSON-friendly description for result metadata."""


@dataclass(frozen=True)
class EmptyInputProvider(InputProvider):
    """Input provider used when a scenario defines no external inputs."""

    @property
    def input_names(self) -> tuple[str, ...]:
        return ()

    def value_at(self, t: float) -> dict[str, Any]:
        return {}

    def signal_points(self) -> tuple[list[float], dict[str, list[Any]]]:
        return [], {}

    def describe(self) -> dict[str, Any]:
        return {"type": "none", "values": {}}


@dataclass(frozen=True)
class ConstantInputProvider(InputProvider):
    """Provide constant named values throughout the simulation interval."""

    values: dict[str, Any]
    t0: float
    tf: float

    @property
    def input_names(self) -> tuple[str, ...]:
        return tuple(self.values)

    def value_at(self, t: float) -> dict[str, Any]:
        return dict(self.values)

    def signal_points(self) -> tuple[list[float], dict[str, list[Any]]]:
        times = [self.t0] if self.t0 == self.tf else [self.t0, self.tf]
        return times, {
            name: [value] * len(times) for name, value in self.values.items()
        }

    def describe(self) -> dict[str, Any]:
        return {"type": "constant", "values": dict(self.values)}


@dataclass(frozen=True)
class TimeHistoryInputProvider(InputProvider):
    """Provide inline time-history inputs using linear or zero-order-hold lookup."""

    time: tuple[float, ...]
    values: dict[str, tuple[Any, ...]]
    interpolation: str = "linear"

    @property
    def input_names(self) -> tuple[str, ...]:
        return tuple(self.values)

    def value_at(self, t: float) -> dict[str, Any]:
        if t <= self.time[0]:
            return {name: samples[0] for name, samples in self.values.items()}
        if t >= self.time[-1]:
            return {name: samples[-1] for name, samples in self.values.items()}

        right = bisect_right(self.time, float(t))
        left = right - 1
        if self.interpolation == "zero-order-hold":
            return {name: samples[left] for name, samples in self.values.items()}

        t_left = self.time[left]
        t_right = self.time[right]
        weight = (float(t) - t_left) / (t_right - t_left)
        return {
            name: samples[left] + weight * (samples[right] - samples[left])
            for name, samples in self.values.items()
        }

    def signal_points(self) -> tuple[list[float], dict[str, list[Any]]]:
        if self.interpolation == "linear":
            return list(self.time), {
                name: list(samples) for name, samples in self.values.items()
            }

        times = [self.time[0]]
        expanded = {name: [samples[0]] for name, samples in self.values.items()}
        for index in range(1, len(self.time)):
            times.extend((self.time[index], self.time[index]))
            for name, samples in self.values.items():
                expanded[name].extend((samples[index - 1], samples[index]))
        return times, expanded

    def describe(self) -> dict[str, Any]:
        return {
            "type": "time_history",
            "interpolation": self.interpolation,
            "time": list(self.time),
            "values": {name: list(samples) for name, samples in self.values.items()},
        }


def _validate_values_mapping(values: Any, *, section: str) -> dict[str, Any]:
    if not isinstance(values, dict) or not values:
        raise ValueError(f"'{section}' must be a non-empty dictionary.")

    normalized: dict[str, Any] = {}
    for raw_name, value in values.items():
        name = str(raw_name).strip()
        if not name:
            raise ValueError(f"Input names in '{section}' must not be empty.")
        normalized[name] = value
    return normalized


def _constant_provider(
    values: Any,
    *,
    t0: float,
    tf: float,
) -> ConstantInputProvider:
    normalized = _validate_values_mapping(values, section="inputs.values")
    return ConstantInputProvider(values=normalized, t0=float(t0), tf=float(tf))


def _time_history_provider(config: dict[str, Any]) -> TimeHistoryInputProvider:
    raw_time = config.get("time")
    if not isinstance(raw_time, list) or not raw_time:
        raise ValueError("'inputs.time' must be a non-empty list.")
    if any(isinstance(value, bool) or not isinstance(value, Real) for value in raw_time):
        raise ValueError("All values in 'inputs.time' must be Real numbers.")

    time = tuple(float(value) for value in raw_time)
    if any(right <= left for left, right in zip(time, time[1:])):
        raise ValueError("'inputs.time' values must be strictly increasing.")

    raw_values = _validate_values_mapping(
        config.get("values"),
        section="inputs.values",
    )
    values: dict[str, tuple[Any, ...]] = {}
    for name, samples in raw_values.items():
        if not isinstance(samples, list) or len(samples) != len(time):
            raise ValueError(
                f"Time-history input '{name}' must contain {len(time)} values."
            )
        values[name] = tuple(samples)

    interpolation = str(config.get("interpolation", "linear")).strip().lower()
    if interpolation not in {"linear", "zero-order-hold"}:
        raise ValueError(
            "'inputs.interpolation' must be 'linear' or 'zero-order-hold'."
        )
    if interpolation == "linear":
        for name, samples in values.items():
            if any(isinstance(value, bool) or not isinstance(value, Real) for value in samples):
                raise ValueError(
                    f"Linear time-history input '{name}' must contain Real values."
                )

    return TimeHistoryInputProvider(
        time=time,
        values=values,
        interpolation=interpolation,
    )


def create_input_provider(
    inputs: Any,
    *,
    t0: float,
    tf: float,
) -> InputProvider:
    """Create an input provider from the normalized scenario ``inputs`` section.

    Supported forms are the existing ``inputs.constant`` shorthand and typed
    ``constant`` or ``time_history`` configurations.
    """
    if inputs is None or inputs == {}:
        return EmptyInputProvider()
    if not isinstance(inputs, dict):
        raise ValueError("'inputs' must be a dictionary if provided.")

    if "constant" in inputs and "type" not in inputs:
        return _constant_provider(inputs["constant"], t0=t0, tf=tf)

    input_type = str(inputs.get("type", "")).strip().lower()
    if input_type == "constant":
        return _constant_provider(inputs.get("values"), t0=t0, tf=tf)
    if input_type in {"time_history", "history", "table"}:
        return _time_history_provider(inputs)

    raise ValueError(
        "Unsupported input type. Expected 'constant' or 'time_history'."
    )


__all__ = [
    "InputProvider",
    "EmptyInputProvider",
    "ConstantInputProvider",
    "TimeHistoryInputProvider",
    "create_input_provider",
]
