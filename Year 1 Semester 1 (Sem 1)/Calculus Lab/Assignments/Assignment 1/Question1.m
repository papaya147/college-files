syms x 
f = x^4 - 3*x^3 + 2

df = diff(f) % first derivative
ddf = diff(df) % second derivative

subplot(2,2,1)
fplot(f, "r", "LineWidth", 1.5)
hold on
fplot(df, "b", "LineWidth", 1.5)
fplot(ddf, "g", "LineWidth", 1.5)
xlabel("x")
ylabel("y")
legend(string(f), string(df), string(ddf))

subplot(2,2,2)
fplot(f, "r", "LineWidth", 1.5)
xlabel("x")
ylabel("y")
legend(string(f))

subplot(2,2,3)
fplot(df, "b", "LineWidth", 1.5)
xlabel("x")
ylabel("y")
legend(string(df))

subplot(2,2,4)
fplot(ddf, "g", "LineWidth", 1.5)
xlabel("x")
ylabel("y")
legend(string(ddf))

hold off