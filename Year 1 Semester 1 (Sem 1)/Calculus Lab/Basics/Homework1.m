syms x
a = (x^2 + 5*x + 5)^(1/5)
b = exp(sin(x))
c = sin(x)*cos(x)

subplot(2,2,1)
ezplot(x,a)
hold on
ezplot(x,diff(a))
ezplot(x,diff(diff(a)))
legend('a(x)',"a'(x) - first derivative","a''(x) - second derivative")
title('Function 1')

subplot(2,2,2)
ezplot(x,b)
hold on
ezplot(x,diff(b))
ezplot(x,diff(diff(b)))
legend('b(x)',"b'(x) - first derivative","b''(x) - second derivative")
title('Function 2')

subplot(2,2,3)
ezplot(x,c)
hold on
ezplot(x,diff(c))
ezplot(x,diff(diff(c)))
legend('c(x)',"c'(x) - first derivative","c''(x) - second derivative")
title('Function 3')