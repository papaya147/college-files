syms x y

f(x, y) = x^2 + y^2;
g(x, y) = 2*x + 4*y;
g_constraint = 40;

fx = diff(f, x);
fy = diff(f, y);
gx = diff(g, x);
gy = diff(g, y);

% finding lambda
lambda_x = fx / gx;
lambda_y = fy / gy;
to_sub = solve(lambda_x == lambda_y)

y_value = solve(subs(g, x, to_sub) == g_constraint)
x_value = solve(subs(g, y, y_value) == g_constraint)

fsurf(f)
hold on
plot3(x_value, y_value, f(x_value, y_value), 'bo', 'Linewidth', 4)