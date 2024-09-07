x = linspace(-2,4,20)
y = 3*x.^3 - 26*x + 10;
dy = 9*x.^2 - 26;
ddy = 18*x;

figure
subplot(2,2,1)
plot(x,y,'--o')
hold on
plot(x,dy,'--o')
plot(x,ddy,'--o')
hold off
legend('y(x)',"y'(x)","y''(x)")

subplot(2,2,2)
plot(x,y,'--o')
legend('y(x)')

subplot(2,2,3)
plot(x,dy,'--o')
legend("y'(x)")

subplot(2,2,4)
plot(x,ddy,'--o')
legend("y''(x)")
