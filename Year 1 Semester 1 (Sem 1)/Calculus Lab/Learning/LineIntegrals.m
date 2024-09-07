%{
syms x y t
f = [x*y^2, x^2*y];
r = [t + sin(pi*t/2), t + cos(pi*t/2)];
I = [0, 1];
dr = diff(r, t);
F = subs(f, {x, y}, r);
Fdr = sum(F.*dr);
I = int(Fdr, t, I(1), I(2));
P(x, y) = f(1); Q(x, y) = f(2);
a = linspace(-2*pi, 2*pi, 11);
[X, Y] = meshgrid(a, a);
U = P(X, Y); V = Q(X, Y);
quiver(X, Y, U, V)
hold on
t1 = linspace(0, 2*pi);
x = subs(r(1), t1); y = subs(r(2), t1);
plot(x, y, 'r')
%}

syms x y z t
f = [x^2*y*z, x*y^2*z, x*y*z^2];
r = [t + sin(pi*t/2), t + cos(pi*t/2), t];
I = [0, 1];
dr = diff(r, t);
F = subs(f, {x, y, z}, r);
Fdr = sum(F.*dr);
I = int(Fdr, t, I(1), I(2));
P(x, y, z) = f(1); Q(x, y, z) = f(2); R(x, y, z) = f(3);
a = linspace(-2*pi, 2*pi, 11);
[X, Y, Z] = meshgrid(a, a, a);
U = P(X, Y, Z); V = Q(X, Y, Z); W = R(X, Y, Z);
quiver3(X, Y, Z, U, V, W)
hold on
t1 = linspace(0, 2*pi);
x = subs(r(1), t1); y = subs(r(2), t1); z = subs(r(3), t1);
plot3(x, y, z, 'r')
xlabel('x'); ylabel('y'); zlabel('z');