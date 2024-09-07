syms x y z

% sphere:
a = 3 % radius
z1 = -sqrt(a^2 - x^2 - y^2);
z2 = sqrt(a^2 - x^2 - y^2);
y1 = -sqrt(a^2 - x^2);
y2 = sqrt(a^2 - x^2);
x1 = -a;
x2 = a;

% double paraboloid
z1 = x^2 + 3*y^2;
z2 = 8 - x^2 - y^2;
y1 = -sqrt(2 - x^2/2);
y2 = sqrt(2 - x^2/2);
x1 = -2;
x2 = 2;

zint = int(1 + 0*x + 0*y + 0*z, z, z1, z2);
yint = int(zint, y, y1, y2);
xint = int(yint, x, x1, x2)

viewSolid(z, z1, z2, y, y1, y2, x, x1, x2)