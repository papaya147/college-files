syms x y t
f = [-y, x];
M(x, y) = f(1); N(x, y) = f(2);
r = [cos(t), sin(t)];
r1 = r(1); r2 = r(2);
dr = diff(r, t);
F = subs(f, {x, y}, r);
F1 = sum(F.*dr);
T = [0, pi/2];
t1 = T(1); t2 = T(2);
LHS = int(F1, t, t1, t2);

ylim = [0, sqrt(1 - x^2)];
xlim = [0, 1];
F2 = diff(N, x) - diff(M, y);
RHS = int(int(F2, y, ylim(1), ylim(2)), x, xlim(1), xlim(2));

if(LHS == RHS)
    disp('LHS of Greens Theorem = ')
    disp(LHS)
    disp('RHS of Greens Theorem = ')
    disp(RHS)
    disp('Hence Greens Theorem is verified')
end