syms x y

u = x^y;

a = diff(diff(diff(u, x), y), x);
b = diff(diff(diff(u, y), x), x);

isAlways(a == b)

subplot(2,2,1)
fsurf(u)
hold on
subplot(2,2,2)
fsurf(a)
subplot(2,2,3)
fsurf(b)
hold off