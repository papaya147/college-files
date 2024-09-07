install.packages("ggplot2")
install.packages("dplyr")
library("ggplot2")
library("dplyr")

ggplot(mpg, aes(displ, hwy, color = class)) + geom_point()

head(mtcars)
ggplot(data = mtcars) + labs(title = "MTCars Data Plot for R programming")

# setting aesthetic layer
ggplot(data = mtcars, aes(x = hp, y = mpg, col = disp)) + 
  labs(title = "MTCars Data Plot")

# add scatter point layer
ggplot(data = mtcars, aes(x = hp, y = mpg, col = disp)) + 
  geom_point() +
  labs(x = "Horsepower", y = "Miles per Gallon", title = "Miles per Gallon vs Horsepower")

# adding shape and colors
ggplot(data = mtcars, aes(x = hp, y = mpg, col = factor(cyl), shape = factor(am))) +
  geom_point() + 
  labs(x = "Horsepower", y = "Miles per Gallon", title = "Miles per Gallon vs Horsepower")

# histogram
ggplot(data = mtcars, aes(x = hp)) +
  geom_histogram(binwidth = 5) +
  labs(x = "Horsepower", y = "Count", title = "Histogram of Horsepower")

p = ggplot(data = mtcars, aes(x = hp, y = mpg, shape = factor(cyl))) +
  geom_point()

# subplots based on am (expand vertically)
p + facet_grid(am ~ .) + 
  labs(x = "Horsepower", y = "Miles per Gallon", title = "Miles per Gallon vs Horsepower")

# subplots based on cyl (expand horizontally)
p + facet_grid(. ~ cyl) + 
  labs(x = "Horsepower", y = "Miles per Gallon", title = "Miles per Gallon vs Horsepower")

# smoothing with stats
ggplot(data = mtcars, aes(x = hp, y = mpg)) +
  geom_point() +
  stat_smooth(method = lm, col = "cyan") + 
  labs(title = "Miles per Gallon vs Horsepower")

# adjusting axes and changing the display spacing
ggplot(data = mtcars, aes(x = wt, y = mpg)) +
  geom_point() +
  stat_smooth(method = lm, col = "green") +
  scale_y_continuous("Miles per Gallon", limits = c(2, 35), expand = c(0, 0)) +
  scale_x_continuous("Weight", limits = c(0, 25), expand = c(0, 0)) +
  coord_equal() +
  labs(title = "Miles per Gallon vs Horsepower")

# limiting plot and line smoothing to x = [3, 6]
ggplot(data = mtcars, aes(x = wt, y = hp, col = am)) +
  geom_point() +
  geom_smooth() +
  coord_cartesian(xlim = c(3, 6))

# changing ggplot theme
ggplot(data = mtcars, aes(x = hp, y = mpg)) +
  geom_point() +
  facet_grid(. ~ cyl) +
  theme(plot.background = element_rect(fill = "blue", color = "gray")) +
  labs(title = "Miles per Gallon vs Horsepower")

