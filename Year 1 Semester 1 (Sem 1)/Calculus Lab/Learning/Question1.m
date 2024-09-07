syms x y z

p1 = 0 + 0*x; % needs to be a func of a sym var
p2 = x;
a = 0;
b = 1;
f = 3 - x - y;

yint = int(f, y, p1, p2)
totint = int(yint, x, a, b)

viewSolid(z, 0, f, y, p1, p2, x, a, b)
%viewSolidone(z, 0, f, y, p1, p2, x, a, b)