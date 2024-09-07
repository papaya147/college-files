clc
clear 
syms x y z real
xa=z;xb=8-z;
ya=z+0*x;yb=8+0*x;
za=0;zb=4;
int(int(int(1+0*x,xa,xb),y,ya,yb),z,za,zb)
viewSolidone(x,xa,xb,y,ya,yb,z,za,zb)