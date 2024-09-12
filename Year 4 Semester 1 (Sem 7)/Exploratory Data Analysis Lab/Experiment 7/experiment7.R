# z score method
data = c(10, 10, 11, 11, 12, 12, 13, 12, 11, 14, 13, 15, 100)

mean.data = mean(data)
std.data = sd(data)

z.scores = (data - mean.data) / std.data

# outliers have -3 < z.score < 3
outliers = data[abs(z.scores) > 3]
outliers

# inter quartile range method
data = c(10, 10, 11, 11, 12, 12, 13, 12, 11, 14, 13, 15, 100)

q1 = quantile(data, 0.25)
q3 = quantile(data, 0.75)
iqr = q3 - q1

# outliers lie outside of the inter quartile range
outliers <- data[data < q1 | data > q3]
outliers

# boxplot method (purely visualisation)
data = c(10, 10, 11, 11, 12, 12, 13, 12, 11, 14, 13, 15, 100)
boxplot(data)
