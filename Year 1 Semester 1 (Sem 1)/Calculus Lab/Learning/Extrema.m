syms x
f(x) = sin(abs(x));

I = [-2 * pi, 2 * pi];
a = I(1);
b = I(2);
t = linspace(a, b, 10000);
p = double(f(t));

[local_maxima_f, location] = findpeaks(p);
local_maxima_x = round(t(location), 4);

[local_minima_f, location] = findpeaks(-p);
local_minima_x = round(t(location), 4);

disp("The maxima is at x = ")
disp(local_maxima_x)
disp("With values = ")
disp(local_maxima_f)

disp("The minima is at x = ")
disp(local_minima_x)
disp("With values = ")
disp(-local_minima_f)

plot(t, p, "-g")
hold on
plot(local_maxima_x, local_maxima_f, "xr", markersize = 10)
plot(local_minima_x, -local_minima_f, "xr", markersize = 10)
hold off