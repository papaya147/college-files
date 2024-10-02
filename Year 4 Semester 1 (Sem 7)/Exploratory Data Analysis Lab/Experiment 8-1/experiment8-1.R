setwd("~/College Work/Year 4 Semester 1 (Sem 7)/Exploratory Data Analysis Lab/Experiment 8-1")
data = read.csv("mtcars.csv")

library(psych)
library(moments)
library(ggplot2)

# 1. measures of central tendency
# arithmetic mean
mean(data$hp)
# geometric mean
exp(mean(log(data$hp)))
# harmonic mean
1 / mean(1 / data$hp)
# median
median(data$hp)
# quantiles
quantile(data$hp)
# deciles
quantile(data$hp, probs = seq(.1, 1, by = .1))
# percentiles
quantile(data$hp, probs = seq(.01, 1, by = .01))

# 2. measures of dispersion
# range
max(data$hp) - min(data$hp)
# inter quantile range
quantile(data$hp, 0.75) - quantile(data$hp, 0.25)
# inter decile range
quantile(data$hp, probs = seq(.1, 1, by = .1))["90%"] - quantile(data$hp, probs = seq(.1, 1, by = .1))["10%"]
# mean absolute deviation
mad(data$hp)
# standard deviation
sd(data$hp)
# skewness
skewness(data$hp)
# kurtosis
kurtosis(data$hp)

# 3. frequency distributions with plots
# frequency distribution
table(cut(mtcars$hp, breaks = 5))
# histogram
hist(data$hp)
# relative frequency distribution
prop.table(table(cut(mtcars$hp, breaks = 5)))
# cumulative frequency distribution
cumsum(table(cut(data$hp, breaks = 5)))

# 4. plots from the categorical variable
# pie chart
pie(table(data$cyl))
# bar plot
barplot(table(mtcars$cyl))