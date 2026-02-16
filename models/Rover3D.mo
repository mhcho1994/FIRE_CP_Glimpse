model Rover3D
  // Standalone low-fidelity rover kinematics (3D-ish: x,y,psi + derived signals)
  // No custom connectors: uses plain Modelica input/output for FMU friendliness.
  
  // --------------------------
  // Constants
  // --------------------------
  constant Real PI = 3.14159265;
  constant Real g = 9.80665 "Gravitational constant [m/s^2]";
  constant Real eps = 1.0e-15;
  constant Real r2d = 180/PI;
  constant Real d2r = PI/180;
  
  // --------------------------
  // Parameters
  // --------------------------
  parameter Real Ts_act = 0.1 "PWM sample interval [s]";
  parameter Real Ts_sen = 0.05 "Sensor sample interval [s]";
  parameter Real l_total = 0.278 "Rear axle to front axle [m]";
  parameter Real track_width = 0.234 "Track width [m]";
  parameter Real cg_height = 0.064 "CG height [m]";
  parameter Real v_max = 15.0 "Max forward velocity [m/s]";
  parameter Real a_max = 5.0 "Max forward acceleration [m/s^2]";
  parameter Real c = a_max/v_max "Viscous friction on ground [1/s]";
  parameter Real delta_max = 25.28*d2r "Max steering angle [rad]";
  
  // --------------------------
  // Inputs
  // --------------------------
  input Real pwm_throttle "Input PWM 1000 ~ 2000 [us]";
  input Real pwm_steering "Input PWM 1000 ~ 2000 [us]";

  // --------------------------
  // Outputs
  // --------------------------
  output Real x_meas "Output inertial x position [m]";
  output Real y_meas "Output inertial y position [m]";
  output Real z_meas "Output inertial z position [m]";

  output Real u_meas "Output body x velocity [m/s]";
  output Real v_meas "Output body y velocity [m/s]";
  output Real w_meas "Output body z velocity [m/s]";

  output Real ax_meas "Output body x acceleration [m/s^2]";
  output Real ay_meas "Output body y acceleration [m/s^2]";
  output Real az_meas "Output body z acceleration [m/s^2]";

  output Real phi_meas "Output roll angle [rad]";
  output Real theta_meas "Output pitch angle [rad]";
  output Real psi_meas "Output yaw angle [rad]";

  output Real p_meas "Output roll rate [rad/s]";
  output Real q_meas "Output pitch rate [rad/s]";
  output Real r_meas "Output yaw rate [rad/s]";
  
  // --------------------------
  // Internals
  // --------------------------
  discrete Real Dthr_zoh(start=0,fixed=false) "Throttle duty cycle 0 ~ 1 [-]";
  discrete Real Dstr_zoh(start=0,fixed=false) "Steering normalized -1 ~ 1 [-]";
  
  discrete Real x_zoh(start=0,fixed=false) "Sampled inertial x position [m]";
  discrete Real y_zoh(start=0,fixed=false) "Sampled inertial y position [m]";
  discrete Real z_zoh(start=0,fixed=false) "Sampled inertial z position [m]";

  discrete Real u_zoh(start=0,fixed=false) "Sampled body x velocity [m/s]";
  discrete Real v_zoh(start=0,fixed=false) "Sampled body y velocity [m/s]";
  discrete Real w_zoh(start=0,fixed=false) "Sampled body z velocity [m/s]";

  discrete Real ax_zoh(start=0,fixed=false) "Sampled body x acceleration [m/s^2]";
  discrete Real ay_zoh(start=0,fixed=false) "Sampled body y acceleration [m/s^2]";
  discrete Real az_zoh(start=0,fixed=false) "Sampled body z acceleration [m/s^2]";

  discrete Real phi_zoh(start=0,fixed=false) "Sampled roll angle[rad]";
  discrete Real theta_zoh(start=0,fixed=false) "Sampled pitch angle [rad]";
  discrete Real psi_zoh(start=0,fixed=false) "Sampled yaw angle [rad]";

  discrete Real p_zoh(start=0,fixed=false) "Sampled roll rate [rad/s]";
  discrete Real q_zoh(start=0,fixed=false) "Sampled pitch rate [rad/s]";
  discrete Real r_zoh(start=0,fixed=false) "Sampled yaw rate [rad/s]";
  
  Real x(start=0,fixed=false) "Inertial x position [m]";
  Real y(start=0,fixed=false) "Inertial y position [m]";
  Real z(start=0,fixed=false) "Inertial z position [m]";

  Real u(start=0,fixed=false) "Body x velocity [m/s]";
  Real v(start=0,fixed=false) "Body y velocity [m/s]";
  Real w(start=0,fixed=false) "Body z velocity [m/s]";

  Real ax(start=0,fixed=false) "Body x acceleration [m/s^2]";
  Real ay(start=0,fixed=false) "Body y acceleration [m/s^2]";
  Real az(start=0,fixed=false) "Body z acceleration [m/s^2]";

  Real phi(start=0,fixed=false) "Roll angle [rad]";
  Real theta(start=0,fixed=false) "Pitch angle [rad]";
  Real psi(start=0,fixed=false) "Yaw angle [rad]";

  Real p(start=0,fixed=false) "Roll rate [rad/s]";
  Real q(start=0,fixed=false) "Pitch rate [rad/s]";
  Real r(start=0,fixed=false) "Yaw rate [rad/s]";
  
  Real thr, delta;
  
equation

  // actuator: use held commands (ZOH)
  thr   = a_max * pre(Dthr_zoh);
  delta = delta_max * pre(Dstr_zoh);

  // simple kinematics
  der(x) = cos(theta)*cos(psi)*u + (sin(phi)*sin(theta)*cos(psi)-cos(phi)*sin(psi))*v + (cos(phi)*sin(theta)*cos(psi)+sin(phi)*sin(psi))*w;
  der(y) = cos(theta)*sin(psi)*u + (sin(phi)*sin(theta)*sin(psi)+cos(phi)*cos(psi))*v + (cos(phi)*sin(theta)*sin(psi)-sin(phi)*cos(psi))*w;
  der(z) = -sin(theta)*u + sin(phi)*cos(theta)*v + cos(phi)*cos(theta)*w;
  der(u) = ax+r*v-q*w;
  der(v) = ay+p*w-r*u;
  der(w) = az+q*u-p*v;
  ax = thr-c*u;
  ay = u*r;
  az = 0;
  der(phi) = p+q*sin(phi)*tan(theta)+r*cos(phi)*tan(theta);
  der(theta) = q*cos(phi)-r*sin(phi);
  der(psi) = q*sin(phi)/cos(theta)+r*cos(phi)/cos(theta);
  p = 0;
  q = 0;
  r = u/l_total*tan(delta);
  
  // sensor measurements
  x_meas = pre(x_zoh);
  y_meas = pre(y_zoh);
  z_meas = pre(z_zoh);
  u_meas = pre(u_zoh);
  v_meas = pre(v_zoh);
  w_meas = pre(w_zoh);
  ax_meas = pre(ax_zoh);
  ay_meas = pre(ay_zoh);
  az_meas = pre(az_zoh);
  phi_meas = pre(phi_zoh);
  theta_meas = pre(theta_zoh);
  psi_meas = mod(pre(psi_zoh) + PI, 2*PI) - PI;
  p_meas = pre(p_zoh);
  q_meas = pre(q_zoh);
  r_meas = pre(r_zoh);
  
algorithm
  // --- Actuator sampling: latch PWM -> Dthr_zoh, Dstr_zoh ---
  when sample(0, Ts_act) then
    Dthr_zoh := (pwm_throttle - 1000.0)/1000.0;
    Dstr_zoh := (pwm_steering - 1500.0)/500.0;
  end when;
  
  // --- Sensor sampling: latch continuous -> *_hold ---
  when sample(0, Ts_sen) then
    x_zoh := x;
    y_zoh := y;
    z_zoh := z;
    u_zoh := u;
    v_zoh := v;
    w_zoh := w;
    ax_zoh := ax;
    ay_zoh := ay;
    az_zoh := az;
    phi_zoh := phi;
    theta_zoh := theta;
    psi_zoh := psi;
    p_zoh := p;
    q_zoh := q;
    r_zoh := r;
  end when;


end Rover3D;
