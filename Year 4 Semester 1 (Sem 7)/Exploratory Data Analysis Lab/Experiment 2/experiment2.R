# vectors
num_vec = c(1:5)
char_vec = c("a", "b", "c")
logi_vec = c(TRUE, FALSE, TRUE)

print(num_vec)
print(num_vec[2])
print(char_vec)
print(char_vec[3])
print(logi_vec)

# lists
l = list(
  numbers = c(1:3),
  names = c("abhinav", "papaya"),
  is_list = TRUE
)
print(l)
print(l$names)

# matrices
m = matrix(
  c(1:6),
  nrow = 3,
  ncol = 2
)
print(m)
print(m[3,2])

# data frame
df = data.frame(
  id = 1:3,
  fruit = c("pineapple", "papaya", "mango"),
  age = c(1, 2, 1)
)
print(df)
print(df$age)
print(df[df$age > 1, ])

# factors
colors = factor(c("red", "blue", "green", "blue", "red"))
print(levels(colors))
print(colors)

# arrays
arr = array(
  c(1:12),
  dim = c(3, 2, 2)
)
print(arr)
print(arr[1,1,1])

