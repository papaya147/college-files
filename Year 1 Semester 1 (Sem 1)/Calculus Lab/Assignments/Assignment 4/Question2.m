syms x y z
f = [cos(x + 2*y), sin(x - 2*y), 0*x*y*z];
P(x, y, z) = f(1); Q(x, y, z) = f(2); R(x, y, z) = f(3);
crl = curl(f, [x, y, z]);
C1(x, y, z) = crl(1); C2(x, y, z) = crl(2); C3(x, y, z) = crl(3);
a = linspace(-1, 1, 21);
[X, Y, Z] = meshgrid(a, a, a);
CR1 = C1(X, Y, Z); CR2 = C2(X, Y, Z); CR3 = C3(X, Y, Z);
U = P(X, Y, Z); V = Q(X, Y, Z); W = R(X, Y, Z);
subplot(2,2,1)
quiver3(X, Y, Z, CR1, CR2, CR3, 2)
title('Curl with quiver3')
xlabel('x'); ylabel('y'); zlabel('z');
subplot(2,2,2)
quiver(X, Y, U, V, 2)
title('Vector Function with quiver')
xlabel('x'); ylabel('y');
subplot(2,2,3)
[X, Y] = meshgrid(a, a);
surf(X, Y, double(C3(X, Y, 0)))
title('Surf of Curl Function')
xlabel('x'); ylabel('y'); zlabel('z');
subplot(2,2,4)
pcolor(X, Y, C3(X, Y, 0))
shading interp
hold on
[X, Y, Z] = meshgrid(a, a, a);
quiver(X, Y, U, V, 2)
title('Vector Function with quiver and pcolor Curl')
xlabel('x'); ylabel('y'); zlabel('z');