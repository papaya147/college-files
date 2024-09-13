library(dplyr)
library(ggplot2)
library(corrplot)

# performing exploratory data analysis with mtcars
data = mtcars

# viewing data structure and dimensions
str(data)
dim(data)

# summarising the data
summary(data)

# missing data checking
sum(is.na(data))

# outlier detection
ggplot(data, aes(y=mpg)) +
  geom_boxplot(fill="#cebae6") +
  theme_minimal()

# univariate analysis
cyl_counts <- as.data.frame(table(data$cyl))
colnames(cyl_counts) <- c("Cylinders", "Count")
ggplot(cyl_counts, aes(x="", y=Count, fill=Cylinders)) +
  geom_bar(stat="identity", width=1) +
  coord_polar(theta = "y") +
  theme_void()

data$gear = as.factor(data$gear)
ggplot(data, aes(x=gear)) +
  geom_bar(fill="#cebae6", color="black")

# bivariate analysis
ggplot(data, aes(x=hp, y=mpg)) +
  geom_point(color="purple") +
  theme_minimal()

ggplot(data, aes(x=cyl, y=mpg, fill=cyl)) +
  geom_point()

# multivariate analysis
data$cyl = as.factor(data$cyl)
data$gear = as.factor(data$gear)

ggplot(data, aes(x=wt, y=mpg, color=hp)) +
  geom_point() +
  scale_color_gradient(low="blue", high="red") +
  facet_grid(cyl~gear) +
  theme_minimal()

# correlation analysis
cor_matrix = cor(data %>% select_if(is.numeric))
corrplot(cor_matrix)