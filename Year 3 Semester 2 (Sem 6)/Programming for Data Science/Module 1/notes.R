setwd("~/Programming/R")
install.packages("rjson")
library("rjson")
json_data = fromJSON(file = "data.json")

install.packages("XML")
library("XML")
xml_result = xmlParse(file = "data.xml")
xml_data = xmlToList(xml_result)

data = data.frame(num = c(1, 2, 3, 4), letter = c("a", "b", "c", "d"))
data

install.packages("dplyr")
library("dplyr")
filter(data, num > 2)

cumsum(c(1, 2, 3, 4, 5, 6))
cumsum(rev(c(1, 2, 3, 4, 5, 6)))

rain = c(0.1,0.6,0.8,0.9,0.1,0.4,0.5,0.6,0.9,0.4,0.4,0.2)
mean(rain)
sd(rain)
cumsum(rain)
which.max(rain)
which.min(rain)

mat = matrix(runif(100), ncol = 10)
rowMeans(mat)
sd(rowMeans(mat))

cm = colMeans(mat)
hist(cm)

install.packages("car")
library("car")

data = data.frame(Name=c("Dhoni", "Raina", "Jaddu"), Age=c(25, 30, 22))
names = data$Name
names
ages = data$Age
ages

first_row = data[1,]
first_row

vec = c(1, 2, 3, 4, 5)
mean(vec)
median(vec)
table(vec)[which.max(table(vec))]

sort(vec)
vec[vec > 2]

x = c(1, 2, 3, 4, 5, 6, 7)
y = c(0, 1, 1, 2, 3, 5, 8)
plot(x, y, main = "Fibbonaci", xlab = "number", ylab = "fib value")

hist(vec)

g1 = "Hi"
g2 = "Abhinav"
paste(g1, g2)

str = "Hello, Programming in Data Science!"
substr(str, start = 2, stop = 8)

for(i in 0:5){
  print(i)
}

i = 0
while(i < 5){
  print(i)
  i = i + 1
}
