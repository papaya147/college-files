syms x y

equation(x, y) = input('Equation: ');

fx = diff(equation, x);
fy = diff(equation, y);
fxx = diff(fx, x);
fyy = diff(fy, y);
fxy = diff(fy, x);

[ax, ay] = solve(fx, fy);
ax = double(ax);
ay = double(ay);

S = size(ax);
S = S(1) * S(2);

subplot(2,1,1)
fsurf(equation)
subplot(2,1,2)
fsurf(equation)
leg = ['Function Plot'];
hold on

for i = 1:S
    xval = ax(i);
    yval = ay(i);
    zval = equation(xval, yval);
    
    m = subs(subs(fxx * fyy - fxy * fxy, x, xval), y, yval);
    r = subs(subs(fxx, x, xval), y, yval);
    
    if isreal(m) && isreal(r)
        if m > 0 && r < 0
            msg = sprintf('Maxima at x = %f and y = %f', xval, yval);
            leg = [leg, {'Maxima'}];
            mkr = 'g+';
        elseif m > 0 && r > 0
            msg = sprintf('Minima at x = %f and y = %f', xval, yval);
            leg = [leg, {'Minima'}];
            mkr = 'r*';
        elseif m < 0
            msg = sprintf('Saddle point at x = %f and y = %f', xval, yval);
            leg = [leg, {'Saddle Point'}];
            mkr = 'ko';
        elseif m == 0
            msg = sprintf('Not known at x = %f and y = %f', xval, yval);
            leg = [leg, {'Case of Further Investigation'}];
            mkr = 'bv';
        end

        plot3(xval, yval, zval, mkr, "Linewidth", 4)
        disp(msg)
    end
end

legend(leg, 'Location', 'best');

xlabel('x')
ylabel('y')
zlabel('z')