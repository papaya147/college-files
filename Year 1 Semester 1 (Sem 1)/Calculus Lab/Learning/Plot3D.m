syms x
syms y

z(x, y) = input('Enter equation: ');
dz = diff(z)
fsurf(dz)