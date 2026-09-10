"""Tests for scenario input-provider construction and time lookup."""

from __future__ import annotations

import pytest

from cp_glimpse_py.simulation.inputs import create_input_provider


def test_constant_input_shorthand() -> None:
    provider = create_input_provider(
        {"constant": {"u": 1.0}},
        t0=0.0,
        tf=5.0,
    )

    assert provider.value_at(0.0) == {"u": 1.0}
    assert provider.value_at(2.5) == {"u": 1.0}
    assert provider.signal_points() == (
        [0.0, 5.0],
        {"u": [1.0, 1.0]},
    )


def test_typed_constant_input() -> None:
    provider = create_input_provider(
        {"type": "constant", "values": {"u": 2.0}},
        t0=1.0,
        tf=3.0,
    )

    assert provider.value_at(2.0) == {"u": 2.0}
    assert provider.describe() == {
        "type": "constant",
        "values": {"u": 2.0},
    }


def test_linear_time_history_input() -> None:
    provider = create_input_provider(
        {
            "type": "time_history",
            "interpolation": "linear",
            "time": [0.0, 2.0, 5.0],
            "values": {"u": [0.0, 2.0, 2.0]},
        },
        t0=0.0,
        tf=5.0,
    )

    assert provider.value_at(-1.0) == {"u": 0.0}
    assert provider.value_at(1.0)["u"] == pytest.approx(1.0)
    assert provider.value_at(3.0)["u"] == pytest.approx(2.0)
    assert provider.value_at(6.0) == {"u": 2.0}


def test_zero_order_hold_time_history_expands_discontinuities() -> None:
    provider = create_input_provider(
        {
            "type": "time_history",
            "interpolation": "zero-order-hold",
            "time": [0.0, 2.0, 5.0],
            "values": {"u": [0.0, 1.0, 3.0]},
        },
        t0=0.0,
        tf=5.0,
    )

    assert provider.value_at(1.0) == {"u": 0.0}
    assert provider.value_at(2.0) == {"u": 1.0}
    assert provider.signal_points() == (
        [0.0, 2.0, 2.0, 5.0, 5.0],
        {"u": [0.0, 0.0, 1.0, 1.0, 3.0]},
    )
