# default iris dataset
iris

# top 6 elements of iris
head(iris)

# bottom 6 elements of iris
tail(iris)

# table of iris species
table(iris$Species)

# histogram of iris sepal widths
hist(iris$Sepal.Width)

# bar graph of iris sepal widths
barplot(iris$Sepal.Width)

# pie chart of iris species
pie(table(iris$Species))

# boxplot 
boxplot(iris$Sepal.Length~iris$Species, col="blue")
