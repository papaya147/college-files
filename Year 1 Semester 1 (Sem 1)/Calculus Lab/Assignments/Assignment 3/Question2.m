syms x y L
 
f(x, y) = x^2 + y^2;
g(x, y) = 2*x + 4*y - 40;
 
F = f + L * g;
Fx = diff(F, x);
Fy = diff(F, y);
 
S = solve(g, Fx, Fy, 'Real', true);
points = [S.x, S.y];
points = double(points);
value = double(f(S.x, S.y))
 
X = double(linspace(min(S.x) - 3, max(S.x) + 3, 25));
Y = double(linspace(min(S.y) - 3, max(S.y) + 3, 25));
 
[X, Y] = meshgrid(X, Y);
Z = double(f(X, Y));
 
surf(X, Y, Z)
hold on
xlabel('x');
ylabel('y');
zlabel('f(x,y)');

gv = fimplicit(g, 'b');
xv = get(gv, 'XData');
yv = get(gv, 'YData');
fv = double(f(xv, yv));

plot3(xv, yv, fv, '-r')
