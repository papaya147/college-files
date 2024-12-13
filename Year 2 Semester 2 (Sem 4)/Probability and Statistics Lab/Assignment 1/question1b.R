t = seq(-3*pi, 3*pi, 0.01)
y = cos(t)
x = sin(t)
plot(t, x, type="l", col="red", lwd=2, ylim=c(-2, 2), xlim=c(-2.1*pi, 2.1*pi))
lines(t, y, type="l", col="green", lwd=2)
legend(2, legend=c("sinx", "cosx"), lty=1, lwd=2, col=c("red", "green"))
grid(nx=NULL, ny=NULL, lty=1, lwd=1)