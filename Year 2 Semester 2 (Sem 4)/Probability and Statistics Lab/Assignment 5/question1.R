x = c(0:6)
f = c(109, 53, 131, 12, 35, 21, 12)
lambda = sum(f * x) / sum(f)
expf = dpois(x, lambda) * sum(f)
f1 = round(expf)
chisq = sum((f - expf)^2/expf)
print(chisq)
chisq_alpha = qchisq(0.95, 2)
print(chisq_alpha)
if(chisq > chisq_alpha){
	print("Poisson fit is not good")
} else {
	print("Poisson fit is good")
}
