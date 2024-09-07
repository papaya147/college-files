A = matrix(c(1, 2, -8, 14, 7, 13, 24, 17, 5, 9, 7, 32, 10, 14, 5, 3, 4, 53, 34, 43, 9, 11, 14, -10, 4), 5, 5)
B = matrix(c(-10, 12, 11, 4, 2, 9, 21, 7, 13, 8, 17, 2, 1, 17, -19, 2, 7, 5, 3, 4, 15, 1, 4, -31, 14), 5, 5)
print("A: ")
print(eigen(A))
print("B: ")
print(eigen(B))
if(all.equal(solve(A %*% B), solve(B) %*% solve(A))){
	print("Inverse of AB is equal to inverse of B * inverse of A")
}
print("The dimension of 4*A^5 - 5*A^3 + A^2 is 5 x 5")
A[4, ] = c(5, -4, 6, 3, 2)
print(A)
B[, 5] = c(14, 9, 43, 4, 26)
print(B)