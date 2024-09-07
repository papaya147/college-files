install.packages("rpart")
library(rpart)
install.packages("rpart.plot")
library(rpart.plot)
install.packages("table1")

head(iris)
dim(iris)

s <- sample(150, 100)
iris_train <- iris[s,]
iris_test <- iris[-s,]

dim(iris_train)
dim(iris_test)

dtm <- rpart(Species~., iris_train, method = "class")
plot(dtm)

text(dtm)
rpart.plot(dtm)

rpart.plot(dtm, type = 4, extra = 101)

p <- predict(dtm, iris_test, type = "class")
table(iris_test[, 5], p)
