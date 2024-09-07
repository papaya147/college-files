syms x
f = sqrt(x);

lower_limit = 1;
upper_limit = 3;

h = matlabFunction(f - 1);
x_values = linspace(lower_limit, upper_limit, 100);
[X, Y, Z] = cylinder(h(x_values))

surf(X, Y, Z)
xlabel("x")
ylabel("y")
zlabel("z")
