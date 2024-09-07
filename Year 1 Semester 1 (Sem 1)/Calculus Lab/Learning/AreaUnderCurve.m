syms x
f(x) = input('Enter curve 1: ');
g(x) = input('Enter curve 2: ');
a = input('Enter lower limit: ');
b = input('Enter upper limit: ');
h(x) = f(x) - g(x);
area = int(h(x), x, a, b)

fplot(f);
hold on
fplot(g);
legend("curve 1", "curve 2");
hold off