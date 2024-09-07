syms x y z
f = [x^2, exp(y), sin(z^3)];
P(x, y, z) = f(1); Q(x, y, z) = f(2); R(x, y, z) = f(3);
x = linspace(-4, 4, 11); y = x; z = x;
[X, Y, Z] = meshgrid(x, y, z);
U = P(X, Y, Z); V = Q(X, Y, Z); W = R(X, Y, Z);
subplot(2,1,1)
quiver3(X, Y, Z, U, V, W, 2);
title('3D Vector Space')
xlabel('x'); ylabel('y'); zlabel('z');
subplot(2,1,2)
% for better visualisation
quiver(X, Y, U, V, 2);
title('2D Projection of 3D Space')
xlabel('x'); ylabel('y'); zlabel('z');