syms x y t
f = [x^2 - y^3, x^3 + y^2];
M(x, y) = f(1); N(x, y) = f(2);
r = [8*cos(t), 4*sin(t)];
dr = diff(r, t);
F = subs(f, {x, y}, r);
F1 = sum(F.*dr);
T = [0, 2*pi];
LHS = int(F1, t, T(1), T(2));

ylim = [-sqrt(16 - (x/2)^2), sqrt(16 - (x/2)^2)];
xlim = [-8, 8];
F2 = diff(N, x) - diff(M, y);
RHS = int(int(F2, y, ylim(1), ylim(2)), x, xlim(1), xlim(2));

if LHS == RHS
    disp('LHS = ')
    disp(LHS)
    disp('RHS = ')
    disp(RHS)
    disp('Therefore Greens theorem is verified')
end