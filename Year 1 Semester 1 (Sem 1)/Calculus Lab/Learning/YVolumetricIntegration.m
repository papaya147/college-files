syms x

y(x) = input('Equation: y = ');
g = input('Rotate about: y = ');
lower_limit = input('Lower limit: x = ');
upper_limit = input('Upper limit: x = ');

f(x) = pi * (y - g)^2;
volume = int(f, x, lower_limit, upper_limit)

f_new = y(x) - g
p = function_handle(x^2 + 3*x + 4)
x_values = linspace(lower_limit, upper_limit, 100);
[X, Y, Z] = cylinder(p(x_values));

Z = lower_limit + Z .* (upper_limit - lower_limit);
surf(X, Y + g, Z)
hold on
plot(x_values, g)

xlabel('x-axis')
ylabel('y-axis')
zlabel('z-axis')