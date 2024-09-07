setwd("/Users/abhi/College Work/Year 3 Semester 2 (Sem 6)/Programming for Data Science Lab")
library("dplyr")

# performing some visualisations
third_class_survivors = dplyr::filter(titanic.raw, Class == "3rd" & Survived == "Yes")
third_class_survivors
third_class_deaths = dplyr::filter(titanic.raw, Class == "3rd" & Survived == "No")
third_class_deaths
pie(c(nrow(third_class_survivors), nrow(third_class_deaths)), c("Survivors", "Deaths"), main = "3rd Class")

second_class_survivors = dplyr::filter(titanic.raw, Class == "2nd" & Survived == "Yes")
second_class_survivors
second_class_deaths = dplyr::filter(titanic.raw, Class == "2nd" & Survived == "No")
second_class_deaths
pie(c(nrow(second_class_survivors), nrow(second_class_deaths)), c("Survivors", "Deaths"), main = "2nd Class")

first_class_survivors = dplyr::filter(titanic.raw, Class == "1st" & Survived == "Yes")
first_class_survivors
first_class_deaths = dplyr::filter(titanic.raw, Class == "1st" & Survived == "No")
first_class_deaths
pie(c(nrow(first_class_survivors), nrow(first_class_deaths)), c("Survivors", "Deaths"), main = "1st Class")

options(timeout=1000)
install.packages("party")
install.packages('caTools')
library("party")
library("caTools")

# splitting the data into train and test datasets (70% train data, 30% test data)
titanic_sample = sample.split(titanic.raw, SplitRatio = 0.7)
train_data = subset(titanic.raw, sample_data == TRUE)
test_data = subset(titanic.raw, sample_data == FALSE)

# creating the model
model = ctree(Survived ~ ., train_data)

# plotting the model
plot(model)

# predict the test values using the model
predict_model = predict(model, test_data)