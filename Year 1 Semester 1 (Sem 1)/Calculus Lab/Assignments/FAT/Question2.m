syms x y

% <----- a ----->
f(x, y) = sqrt(x^2 + y^2);
xgrad(x, y) = diff(f, x);
ygrad(x, y) = diff(f, y);
grad = [xgrad, ygrad];
disp('(a). The gradient of the function is:')
disp(grad)

% <----- b ----->
figure
a = linspace(1, 5, 21);
[X, Y] = meshgrid(a, a);
U = xgrad(X, Y); V = ygrad(X, Y);
quiver(X, Y, U, V);
hold on
fcontour(f, [1 5])
xlabel('x')
ylabel('y')
legend('Quiver of gradient', 'Contour of function')
title('Quiver of gradient and Contours of function')

% <----- c ----->
figure
a = linspace(-3*pi, 3*pi, 10000);
f1(x) = sin(x); f2(x) = cos(x);
F1 = f1(a); F2 = f2(a);
plot(a, F1);
hold on
plot(a, F2);
xlabel('x')
ylabel('y')
legend('sin(x)', 'cos(x)')
title('Graph of sin(x) and cos(x)')