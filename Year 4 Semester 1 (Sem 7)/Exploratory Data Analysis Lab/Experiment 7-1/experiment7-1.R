library(lubridate)

setwd("~/College Work/Year 4 Semester 1 (Sem 7)/Exploratory Data Analysis Lab/Experiment 7-1")

# 1. loading the data
data = read.csv("airpassengers.csv")
data$Month = as.Date(paste0(data$Month, "-01"), format = "%Y-%m-%d")

# 2. structure and data types of data
head(data)
typeof(data$Month)
typeof(data$X.Passengers)

# 3. checking for missing values in the data
sum(is.na(data))

# 4. checking start and end date
min(data$Month)
max(data$Month)

# 5. checking frequency of the data
frequency(data)

# 6. checking summary of the data
summary(data)

# 7. plotting with decompose
ts.data = ts(data$X.Passengers, start = c(1949, 1), frequency = 12)
plot(decompose(ts.data))

# 8. plotting the data
plot(data)

# 9. plotting the time series of the data
plot.ts(data)

# 10. regression line for the data
abline(lm(data$X.Passengers~data$Month))

# 11. cycles for the data
cycle(ts.data)

# 12. making the data stationary and plotting it
plot(log(ts.data))
plot(diff(log(ts.data)))

# 13. box plot
boxplot(ts.data~cycle(ts.data))