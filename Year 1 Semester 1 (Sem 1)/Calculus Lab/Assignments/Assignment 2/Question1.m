syms x
f = x^3 + 1;
g = 0;

fplot(-f)

lower_limit = 0;
upper_limit = 1;

volume = int(pi * (g - f)^2, x, lower_limit, upper_limit)

h = matlabFunction(g - f);
x_values = linspace(lower_limit, upper_limit, 100);
[X, Y, Z] = cylinder(h(x_values));

Z = lower_limit + Z.*(upper_limit - lower_limit);
figure
surf(X, Y, Z)
xlabel("x")
ylabel("y")
zlabel("z")
