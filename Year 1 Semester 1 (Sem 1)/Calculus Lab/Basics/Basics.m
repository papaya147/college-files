% creating row vectors %
A = [1 2 3 4]
A = [1,2,3,4] % these are the same %

% creating column vectors %
B = [1;2;3;4]

C = [5 6 7 8]

% concatenating row vectors %
D = [A C]

% transpose matrix %
E = A'

% creating custom matrix %
F = 0:1:10 % this creates a matrix [0 1 2 ... 9 10]

% creates evenly spaced matrix from 1st arg to 2nd arg with 3rd arg %
% elements %
linspace(0,10,100)

% create 2 dimensional 2x2 matrix %
G = [1 2;3 4]

% create 2 dimensional 3x2 matrix %
H = [1 2;3 4;5 6]

% use ; to hide output in command window %
5+4; % this will assign 9 to ans but not display it%

% to show 15 decimal places %
format long

% to show 4 decimal places %
format short

% to show 2 decimal places %
format bank

% inverse of a matrix %
inv(G)

% determinant of a matrix %
det(G)

% sind() to get ans with degrees and sin() to get with radians %
sind(90) % = 1 %
sinr(pi) % = 0 %

% asind() to get ans in degrees and asin() to get in radians %
asind(1) % = 90 %
asin(1) % = pi/2 %

% replace matrix entries %
G(1,1) = 3 % replaces entry (1, 1) to 3 %

% natural log %
log(2) % = 0.69 %

% base 10 log %
log10(10) % = 1 %

% get specific columns entries %
G(:,2) % returns 2nd column entries %

% get specific row entries %
G(2,:) % returns 2nd row entries %

% get order of matrix %
size(G) % = 2 2 %

% get length of vector %
length(A) % = 4 %

% create identity matrix of any order %
eye(3)

% create 2 dimensional ones matrix of any order %
ones(2,3)

% create 2 dimensional zeros matrix of any order %
zeros(2,3)

% create 3 dimensional ones matrix of any order %
ones(3,3,3)

% create 3 dimensional zeros matrix of any order %
zeros(3,2,3)

% position wise multiplication %
A.*C % with another matrix %
A.^2 % with itself %

% regular matrix multiplication %
A*B % with another matrix %
G^2 % with itself (needs to be square matrix) %

% position wise division %
A./C % with another matrix %

I = [5 6;8 10]
% matrix division (actually multiplication with inverse) %
G/I % = G * inv(I) %

% create symbolic variables %
syms x
f(x) = ((1 + x)^3)/(x^4)

% find limit using sym var %
limit(f(x), x, inf) % = 0 %
% can put 4th arg for 'left' and 'right' limits %

% find derivative using sym var %
diff(f(x)) % = (3*(x + 1)^2)/x^4 - (4*(x + 1)^3)/x^5 %

% find integral using sym var %
int(f(x)) % = log(x) - (3*x^2 + (3*x)/2 + 1/3)/x^3 %

% substitute value for sym var %
subs(f(x),x,9) % = 1000/6561 %

% simplify expressions with sym var %
simplify(f(x))