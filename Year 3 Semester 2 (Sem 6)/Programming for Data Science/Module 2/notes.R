langs = c("r", "java", "python")
langs[2] = "go"
langs

langs[4] = "java"
langs

langs[10] = "javascript"
langs

nums = 1:100
nums

rep(nums, times = 4)
rep(nums, each = 2)

sort(rep(nums, times = 2)) == rep(nums, each = 2)

length(nums)
length(rep(nums, times = 2))

nums = 1.5:6.5
nums

nums = 1.5:8.3
nums

list = list(24, "hi", TRUE)
list[1]
list[2]

list[4] = "a"
list = append(list, 5)
list

list = list[-4]
list
list[4]

5 %in% list
"a" %in% list

list = list(fruit = "Pineapple", number = 123456789, is_valid = TRUE, numbers = c(1, 2, 3))
list$fruit
list[1]
list$numbers[1]
list[["fruit"]]
list[["numbers"]][3]

list = list(a = 1:3, b = 4:6, c = 7:9)
list

square_function = function(x) {
  x^2
}

lapply(list, square_function)
sapply(list, square_function)

data = data.frame(name = c("a", "b", "c"), dept = c("sjt", "sjt", "tt"), salary = c(10, 10, 15))
is.data.frame(data)
ncol(data)
nrow(data)

max(data$salary)
min(data$name)

subset(data, salary == max(salary))
subset(data, salary == min(salary))

subset(data, dept == "sjt")

subset(data, salary == min(salary) & name == "a")

any(grepl("xlsx", installed.packages()))
install.packages("xlsx")
any(grepl("xlsx", installed.packages()))

install.packages("RCurl")
library("RCurl")
install.packages("XML")
install.packages("stringr")
install.packages("plyr")
links = getHTMLLinks("https://vit.ac.in")
