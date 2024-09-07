print(paste("Exactly 3 red balls: ", dpois(3, 50 / 1000 * 60)))
print(paste("Not more than 3 red balls: ", ppois(3, 50 / 1000 * 60)))