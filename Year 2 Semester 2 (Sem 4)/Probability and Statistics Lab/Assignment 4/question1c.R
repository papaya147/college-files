p1 = 42
n1 = 200
p2 = 18
n2 = 100
alpha = 0.05
h0 = "8% is a valid claim"
h1 = "8% is not a valid claim"
test_tail_type = 2

P1 = p1 / n1
P2 = p2 / n2
P = (p1 + p2) / (n1 + n2)
Q = 1 - P
z = (P1 - P2) / sqrt((P * Q * (1/n1 + 1/n2)))
z_alpha = qnorm(1 - alpha * test_tail_type / 2) # two tailed test
print(paste("z: ", z))
print(paste("z_alpha: ", z_alpha))
if(z > z_alpha){
	print(h1)
} else {
	print(h0)
}