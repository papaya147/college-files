% x = 0:1:5;
% y = 10:1:15;
% 
% x =0:0.2:20;
% y = exp(x);

x = 0:1:20;
y = x.^2;

% plot(x,y,'--og','markersize',5,'markerfacecolor','b','markeredgecolor','k')
% --og is type of line
% markersize is the size of the 'o's
% markerfacecolor changes the 'o's color
% markeredgecolor change the 'o's edge color

u = exp(-x)
v = sin(x)
plot(x,y,x,u,x,v)

xlabel('x-axis')
ylabel('y-axis')
title('plotting')

% legend('parabola')