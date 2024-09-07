P1 = 0.2
n1 = 900
P2 = 0.15
n2 = 1600
alpha = 0.05
h0 = "The difference between the proportions is not significant"
h1 = "The difference between the proportions is significant"
test_tail_type = 2

p1 = P1 * n1
p2 = P2 * n2
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