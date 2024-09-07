t = seq(0, 8*pi, 0.01)
y = (1 - cos(t)) / 2
plot(t, y, type="l", col="red", ylim=c(-1.1, 1.1), lwd=2)
grid(nx=NULL, ny= NULL, lty=1, col="gray", lwd=2)