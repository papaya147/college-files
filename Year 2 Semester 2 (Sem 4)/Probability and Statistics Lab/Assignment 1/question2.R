n = readline()
n = as.integer(n)
x = 0
a = 0
b = 1
while(x < n){
	print(a)
	b = a + b
	a = b - a
	x = x + 1
}