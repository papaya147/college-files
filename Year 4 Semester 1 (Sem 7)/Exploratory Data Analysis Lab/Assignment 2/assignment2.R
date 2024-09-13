# experiment 5 items
library(dplyr)
library(missForest)
library(mice)
library(VIM)
library(ggplot2)
library(cowplot)

data = iris
View(data)

# dropping labels
data = data %>% select(-c("Species"))
View(data)

# adding 10% random values
iris.mis <- prodNA(data, noNA = 0.1)
View(iris.mis)

ggplot(iris.mis, aes(x = Sepal.Length)) +
  geom_histogram(color="black", fill="#0099F8")

# simple imputations for Sepal.Length
imputed = data.frame(
  Original = iris.mis$Sepal.Length,
  Imp.Zero = replace(iris.mis$Sepal.Length, is.na(iris.mis$Sepal.Length), 0),
  Imp.Mean = replace(iris.mis$Sepal.Length, is.na(iris.mis$Sepal.Length), mean(iris.mis$Sepal.Length, na.rm = TRUE)),
  Imp.Median = replace(iris.mis$Sepal.Length, is.na(iris.mis$Sepal.Length), median(iris.mis$Sepal.Length, na.rm = TRUE))
)

# plotting the simple imputations
h1 = ggplot(imputed, aes(x=Original)) +
  geom_histogram(fill="red", color="black", position="identity") +
  ggtitle("Original distribution")
h2 = ggplot(imputed, aes(x=Imp.Zero)) +
  geom_histogram(fill="green", color="black", position="identity") +
  ggtitle("Zero-imputed distribution")
h3 = ggplot(imputed, aes(x=Imp.Mean)) +
  geom_histogram(fill="blue", color="black", position="identity") +
  ggtitle("Mean-imputed distribution")
h4 = ggplot(imputed, aes(x=Imp.Median)) +
  geom_histogram(fill="yellow", color="black", position="identity") +
  ggtitle("Median-imputed distribution")

plot_grid(h1, h2, h3, h4, nrow=2, ncol=2)

# viewing missing values
md.pattern(iris.mis, rotate.names=TRUE)

# performing imputations with mice algorithms
mice_imputed = data.frame(
  Original = iris.mis$Sepal.Length,
  Imp.PMM = complete(mice(iris.mis, method="pmm"))$Sepal.Length,
  Imp.CART = complete(mice(iris.mis, method="cart"))$Sepal.Length,
  Imp.Lasso = complete(mice(iris.mis, method="lasso.norm"))$Sepal.Length
)

# plotting the mice imputations
h1 = ggplot(mice_imputed, aes(x=Original)) +
  geom_histogram(fill="red", color="black", position="identity") +
  ggtitle("Original distribution")
h2 = ggplot(mice_imputed, aes(x=Imp.PMM)) +
  geom_histogram(fill="green", color="black", position="identity") +
  ggtitle("PMM-imputed distribution")
h3 = ggplot(mice_imputed, aes(x=Imp.CART)) +
  geom_histogram(fill="blue", color="black", position="identity") +
  ggtitle("CART-imputed distribution")
h4 = ggplot(mice_imputed, aes(x=Imp.Lasso)) +
  geom_histogram(fill="yellow", color="black", position="identity") +
  ggtitle("Lasso-imputed distribution")

plot_grid(h1, h2, h3, h4, nrow=2, ncol=2)

# imputations with missForest
missforest_imputed = data.frame(
  Original = iris.mis$Sepal.Length,
  Imp.Missforest = missForest(iris.mis)$ximp$Sepal.Length
)

# plotting the missForest imputations
h1 = ggplot(missforest_imputed, aes(x=Original)) +
  geom_histogram(fill="red", color="black", position="identity") +
  ggtitle("Original distribution")
h2 = ggplot(missforest_imputed, aes(x=Imp.Missforest)) +
  geom_histogram(fill="green", color="black", position="identity") +
  ggtitle("missForest-imputed distribution")

plot_grid(h1, h2, nrow=1, ncol=2)

# experiment 6 items
cov(data$Sepal.Length, data$Sepal.Width)
cor(data$Sepal.Length, data$Sepal.Width)

# experiment 7 items
# z score method
data = iris$Sepal.Length

mean.data = mean(data)
std.data = sd(data)

z.scores = (data - mean.data) / std.data

# outliers have -3 < z.score < 3
outliers = data[abs(z.scores) > 3]
outliers

# inter quartile range method
data = iris$Sepal.Length

q1 = quantile(data, 0.25)
q3 = quantile(data, 0.75)
iqr = q3 - q1

# outliers lie outside of the inter quartile range
outliers <- data[data < q1 | data > q3]
outliers

# boxplot method (purely visualisation)
data = iris$Sepal.Length
boxplot(data)
