print(paste("More than 2150 hours: ", 1 - pnorm(2150, 2040, 60)))
print(paste("Less than 1050 hours: ", pnorm(1950, 2040, 60)))
print(paste(">1920 and <2160 hours: ", pnorm(2160, 2040, 60) - pnorm(1920, 2040, 60)))