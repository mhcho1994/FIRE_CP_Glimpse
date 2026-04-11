model LinearHybridTwoTank
  /*
    Two-tank hybrid automaton
    # of variables = 2, # of modes = 4, # of jumps = 7
    
    Continuous states:
      x1 : liquid level in tank 1
      x2 : liquid level in tank 2

    Discrete states:
      valve1on : valve1 state (true=on, false=off)
      valve2on : valve2 state (true=on, false=off)

    Dynamics:
      if valve1 = off:
        der(x1) = -x1 - 2 + u
      if valve1 = on:
        der(x1) = -x1 + 3 + u

      if valve2 = off:
        der(x2) = x1 + u
      if valve2 = on:
        der(x2) = x1 - x2 - 5 + u

    Switching logic from the figure:
      valve1: off -> on  when x1 <= -1
              on  -> off when x1 >= 1

      valve2: off -> on  when x2 >= 1
              on  -> off when x2 <= 0

    This reproduces the four hybrid modes:
      off_off, on_off, off_on, on_on
  */

  input Real u "Input/disturbance (e.g. choose in [-0.1, 0.1])";

  parameter Real x1_0 = 2.0 "Initial level of tank 1";
  parameter Real x2_0 = 1.0 "Initial level of tank 2";

  Real x1(start=x1_0) "Tank 1 level";
  Real x2(start=x2_0) "Tank 2 level";

  discrete Boolean valve1on(start=false, fixed=true) "true = valve1 on";
  discrete Boolean valve2on(start=false, fixed=true) "true = valve2 on";

equation
  // Continuous dynamics
  der(x1) = if valve1on then (-x1 + 3 + u) else (-x1 - 2 + u);
  der(x2) = if valve2on then (x1 - x2 - 5 + u) else (x1 + u);

algorithm
  // hysteresis switching
  when x1 <= -1 and not pre(valve1on) and not pre(valve2on) then
    valve1on := true;
  end when;
  
  when x2 >= 1 and not pre(valve1on) and not pre(valve2on) then
    valve2on := true;
  end when;

  when x2 >= 1 and pre(valve1on) and not pre(valve2on) then
    valve1on := false;
    valve2on := true;
  end when;

  when x1 <= -1 and not pre(valve1on) and pre(valve2on) then
    valve1on := true;
  end when;
  
  when x2 <= 0 and not pre(valve1on) and pre(valve2on) then
    valve2on := false;
  end when;

  when x1 <= -1 and not pre(valve1on) and pre(valve2on) then
    valve1on := true;
  end when;

  when x2 <= 0 and pre(valve1on) and pre(valve2on) then
    valve2on := false;
  end when;

  when x1 >= 1 and pre(valve1on) and pre(valve2on) then
    valve1on := false;
  end when;

annotation (
  experiment(StartTime=0, StopTime=20, Tolerance=1e-8, Interval=0.001)
);
end LinearHybridTwoTank;
