syms x
y = (exp(-x))*sin(x)

dy = diff(y)
ddy = diff(dy)

subplot(2,2,1)
ezplot(x,y)
legend('y(x)')

subplot(2,2,2)
ezplot(x,dy)
legend("y'(x) - first derivative")

subplot(2,2,3)
ezplot(x,ddy)
legend("y''(x) - second derivative")

subplot(2,2,4)
ezplot(x,y)
hold on
ezplot(x,dy)
ezplot(x,ddy)
legend('y(x)',"y'(x) - first derivative","y''(x) - second derivative")
title('All 3 function')