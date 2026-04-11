model BouncingBall
  /*
    Classical bouncing ball hybrid model
    # of variables = 2, # of modes = 1, # of jumps = 1
    
    States:
      x : ball height [m]
      v : vertical velocity [m/s]

    Continuous dynamics:
      der(x) = v
      der(v) = -g

    Invariant:
      x >= 0

    Guard:
      x <= 0 and v <= 0

    Reset:
      v := -c * pre(v)
      
    Unsafe set:
      v >= 10.7
  */

  parameter Real g = 9.81 "Gravitational acceleration [m/s^2]";
  parameter Real c(min=0, max=1) = 0.75 "Coefficient of restitution";
  parameter Real x0 = 10.0 "Initial height [m]";
  parameter Real v0 = 0.0 "Initial velocity [m/s]";

  Real x(start=x0) "Height above ground [m]";
  Real v(start=v0) "Vertical velocity [m/s]";

equation
  // Continuous flow map
  der(x) = v;
  der(v) = -g;

  // Guard and reset map: impact with the ground while moving downward
  when x <= 0 and v <= 0 then
    reinit(x, 0);
    reinit(v, -c * pre(v));
  end when;

annotation (
  experiment(StartTime=0, StopTime=9.99, Tolerance=1e-8, Interval=0.001)
);
end BouncingBall;
