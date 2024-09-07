print(paste("All bulbs good: ", dbinom(20, 20, 0.1)))
print(paste("At most 3 defective bulbs: ", pbinom(3, 20, 0.1)))
print(paste("Exactly 3 defective bulbs: ", dbinom(3, 20, 0.1)))