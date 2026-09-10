model SimpleIntegrator
  input Real u "Input";
  output Real y "Integrated output";

  parameter Real y0 = 0 "Initial value";

initial equation
  y = y0;

equation
  der(y) = u;

end SimpleIntegrator;