syms x

% <----- a ----->
f(x) = 9*x^4 - 14*x^3 - 48*x^2 + 72*x;
I = [-5, 5];
interval = linspace(I(1), I(2), 10000);
F = double(f(interval));
[local_max, max_loc] = findpeaks(F);
[local_min, min_loc] = findpeaks(-F);
local_min = -local_min;

disp('(a). The critical values for maxima are:')
disp(local_max)
disp('(a). The critical values for minima are:')
disp(local_min)

% <----- b ----->
max_x_val = interval(max_loc);
min_x_val = interval(min_loc);
ddf = diff(diff(f));
double_der_val_max = double(ddf(max_x_val));
double_der_val_min = double(ddf(min_x_val));

disp('(b). The double derivitive value for maxima is:')
disp(double_der_val_max)
disp('(b). The double derivitive value for minima is:')
disp(double_der_val_min)

% <----- c ----->
figure
fplot(f);
xlabel('x');
ylabel('y');
legend('9x^4 - 14x^3 - 48x^2 + 72x');
title('Graph of function f(x)')