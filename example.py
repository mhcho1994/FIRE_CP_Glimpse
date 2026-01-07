import casadi as ca

# Define a simple CasADi function f(x) = sin(x) + x^2
x = ca.MX.sym('x')
f = ca.Function('f', [x], [ca.sin(x) + x**2])

# Generate self-contained C code
f.generate('f.c')

