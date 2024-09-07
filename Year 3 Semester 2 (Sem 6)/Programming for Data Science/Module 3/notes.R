install.packages("tidyverse")
library("tidyverse")
install.packages("dplyr")
library("dplyr")
install.packages("XQuartz")

dplyr::tbl_df(iris)
utils::View(iris)

dplyr::group_by(iris, Species)
dplyr::ungroup(iris)

dplyr::filter(iris, Sepal.Length >= 7)
dplyr::distinct(iris)
dplyr::sample_frac(iris, 0.1, replace = TRUE)

dplyr::slice(iris, 10:15)
storms = dplyr::storms
dplyr::top_n(storms, 2, day)

install.packages("magrittr")
library("magrittr")
library("dplyr")

data = data.frame(
  id = c(10,11,12,13),
  name = c('sai','ram','deepika','sahithi'),
  gender = c('M','M','F','F'),
  dob = as.Date(c('1990-10-02','1981-3-24','1987-6-14','1985-8-16')),
  state = c('HYD','VIZAG','TIRUPATI',NA),
  row.names=c('r1','r2','r3','r4')
)
data

data %>% select(2, 3)
data %>% select(2:4)
data %>% select(-c(1, 2))
data %>% select(-c("id", "name"))
data %>% select(starts_with("gen"))
data %>% select(ends_with("e"))

vit.data <- data.frame(
  student_id = c (1:5),
  student_name = c("Arick","Donan","Michelle","Ritchie","Gary"),
  cgpa = c(6.3,5.2,6.0,7.0,8.25),
  start_date = as.Date(c("2012-01-01", "2013-09-23", "2014-11-15", "2014-05-11", "2015-03-27")),
  stringsAsFactors = FALSE
)
vit.data
str(vit.data)
summary(vit.data)

vit.data[1:2,]
data.frame(vit.data$student_name, vit.data$student_id)

vit.newdata <- data.frame(
  student_id = c(6:8),
  student_name = c("Rasmi","Pranab","Tusar"),
  cgpa = c(5.0,7.5,6.8),
  start_date = as.Date(c("2013-05-21","2013-07-30","2014-06-17")),
  stringsAsFactors = FALSE
)

vit.final = rbind(vit.data, vit.newdata)
vit.final

iris %>% mutate(root_sepal_width = sqrt(Sepal.Width))
storms %>% mutate(century = as.integer(year / 100) + 1)

storms %>% arrange(by_group = hour)
