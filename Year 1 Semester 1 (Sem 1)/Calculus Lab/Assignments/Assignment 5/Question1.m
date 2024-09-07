syms x y z t
f = [y*z, x*z, x*y + 2*z];
P1 = [1, 0, -2]; P2 = [4, 6, 3];
P(x, y, z) = f(1); Q(x, y, z) = f(2); R(x, y, z) = f(3);
r = (P2 - P1) * t + P1; % parameterisation
lim = [0, 1];
F = subs(f, {x, y, z}, r);
dr = diff(r, t);
F1 = sum(F.*dr);
W = int(F1, t, lim(1), lim(2))

% graphing for visualisation
xlin = linspace(P1(1), P2(1), 11); ylin = linspace(P1(2), P2(2), 11); zlin = linspace(P1(3), P2(3), 11);
[X, Y, Z] = meshgrid(xlin, ylin, zlin);
quiver3(X, Y, Z, P(X, Y, Z), Q(X, Y, Z), R(X, Y, Z))
hold on
a = linspace(0, 1, 11);
plot3(subs(r(1), a), subs(r(2), a), subs(r(3), a))
xlabel('x'); ylabel('y'); zlabel('z');