syms x h
f = input("Enter function: ");
x_value = input("Enter place to check differentiability, x = ");

lim_eq = (subs(f, x + h) - subs(f, x))/h;
limit_f = limit(lim_eq, h, 0);

fplot(f, "LineWidth", 1.5)
hold on
legend(string(f))
xlabel("x")
ylabel("y")
try
    lim_value = subs(limit_f, x_value)
    
    % building tangent line
    y_value = subs(f, x_value);
    tangent = lim_value * (x - x_value) + y_value
    fplot(tangent, "LineWidth", 1.5)
    legend(string(f), string(g))
catch
    disp(['The function is not differentiable at x = ', num2str(lim)])
end

hold off