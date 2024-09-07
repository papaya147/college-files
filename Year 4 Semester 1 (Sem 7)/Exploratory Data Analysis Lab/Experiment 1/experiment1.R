# branching with if
x = 5
if (x == 5) {
  print("x is greater than 5")
}

# branching with if... else
x = 2
if (x > 3) {
  print("x is greater than 3")
} else {
  print("x is less than or equal to 3")
}

# branching with if... else if... else
x = 3
if (x > 3) {
  print("x is greater than 3")
} else if (x < 3) {
  print("x is less than 3")
} else {
  print("x is equal to 3")
}

# looping with range
for (i in 1:5) {
  print(i)
}

# looping through elements
names = c("abhinav", "tanush", "dinesh", "sumathi")
for (name in names) {
  print(name)
}

# while loop
x = 0
while (x < 5) {
  print(x)
  x = x + 1
}

# repeat loop
x = 1
repeat {
  print(x)
  if (x >= 5) {
    break
  }
  x = x + 1
}

# branching and looping combo
for (x in 0:10) {
  if (x %% 2 == 0) {
    print(paste(x, "is even"))
  } else {
    print(paste(x, "is odd"))
  }
}
