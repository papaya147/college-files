syms x
f(x) = sin(abs(x));
df(x) = diff(f);
ddf(x) = diff(df);

subplot(2,2,1)
fplot(f)
hold on
subplot(2,2,2)
fplot(df)
subplot(2,2,3)
fplot(ddf)
hold off

t = linspace(-2 * pi, 2 * pi, 10000);
p = double(f(t))


solution = solve(df, x, "returnconditions", true);
solution.x
solution.conditions