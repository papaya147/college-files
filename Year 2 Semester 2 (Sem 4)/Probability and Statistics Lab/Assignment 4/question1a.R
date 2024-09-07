p = 50000
x = 46500
n = 28
sd = 8000
alpha = 0.05
h0 = "The claim is supported at 5% LOS"
h1 = "The claim is not supported at 5% LOS"
test_tail_type = 2

z_alpha = qnorm(1 - alpha * test_tail_type / 2) # two tailed test
z = abs((x - p) / (sd * sqrt(n)))
print(paste("z: ", z))
print(paste("z_alpha: ", z_alpha))
if(z > z_alpha){
	print(h1)
} else {
	print(h0)
}