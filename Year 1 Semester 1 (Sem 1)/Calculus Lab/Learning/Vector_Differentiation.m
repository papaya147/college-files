
syms x y
f = x^2*y^2 + x*y;
grad = gradient(f, [x, y]);
P(x, y) = grad(1);
Q(x, y) = grad(2);
x = linspace(-10, 10, 11);
y = x;
[X, Y] = meshgrid(x, y);
U = P(X, Y); V = Q(X, Y);
quiver(X, Y, U, V, 0.5)
axis on
xlabel('x'); ylabel('y');
hold on
fcontour(f, [-10, 10])


% < ------------------------------- > %

%{
syms x y
f = [x*y^2, x^2];
div(x, y) = divergence(f, [x, y]);
P(x, y) = f(1); Q(x, y) = f(2);
x = linspace(-4, 4, 21); y = x;
[X, Y] = meshgrid(x, y);
U = P(X, Y); V = Q(X, Y);
figure
pcolor(X, Y, div(X, Y));
shading interp
hold on
quiver(X, Y, U, V, 0.5)


% < ------------------------------- > %

syms x y z
f = [-y, x, 0];
P(x, y, z) = f(1); Q(x, y, z) = f(2); R(x, y, z) = f(3);
crl = curl(f, [x, y, z]);
C1(x, y, z) = crl(1); C2(x, y, z) = crl(2); C3(x, y, z) = crl(3);
x = linspace(-4, 4, 11); y = x; z = x;
[X, Y, Z] = meshgrid(x, y, z);
U = P(X, Y, Z); V = Q(X, Y, Z); W = R(X, Y, Z);
CR1 = C1(X, Y, Z); CR2 = C2(X, Y, Z); CR3 = C3(X, Y, Z);
figure
subplot(1,2,1)
quiver3(X, Y, Z, U, V, W);
title('3D view of vector field')
subplot(1,2,2)
quiver3(X, Y, Z, CR1, CR2, CR3)
%}