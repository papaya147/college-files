library(dplyr)
library(ggplot2)
library(lubridate)
library(magrittr)

setwd("/Users/abhi/College Work/Year 4 Semester 1 (Sem 7)/Exploratory Data Analysis Lab/Assignment 2")
data = read.csv("./DS2_Match.csv")

# dimentions and names of columns
dim(data)
names(data)

# sorting data by win type
head(sort(data$Win_Type))

# summary of data
summary(data)

# finding min and max of first umpire id
min(data$First_Umpire_Id)
max(data$First_Umpire_Id)

# finding mean and median of won by amount
data$Won_By = sapply(data$Won_By, function(x) {
  if (x == "NULL") {
    return(0)
  }
  x
})
data$Won_By = as.numeric(data$Won_By)
mean(data$Won_By)
median(data$Won_By)

# finding quantiles of won by
quantile(data$Won_By)

# viewing data
View(data)

# checking NaN values (if cleanup is required)
sum(apply(data, 2, is.nan))

# check different host countries
levels(factor(data$Host_Country))

# plotting by host country
country_counts = data %>% 
  group_by(Host_Country) %>% 
  summarise(count = length(Host_Country))
pie(country_counts$count, labels=country_counts$Host_Country)

# check different win conditions
levels(factor(data$Win_Type))

# plotting by win condition
win_cond_count = data %>% 
  group_by(Win_Type) %>% 
  summarise(count = length(Win_Type))
barplot(win_cond_count$count, xlab="Win Condition", ylab="Count", names.arg=win_cond_count$Win_Type, col="cyan")

# check different city names
levels(factor(data$City_Name))

# plotting by city name, color by host country
city = data %>% 
  group_by(City_Name, Host_Country) %>% 
  summarise(count = length(City_Name))
ggplot(city, aes(x=City_Name, y=count, fill=Host_Country)) +
  geom_bar(stat="identity") +
  geom_text(aes(label=City_Name), vjust=0.5, angle=90, hjust=0) + scale_x_discrete(labels=NULL) +
  ylim(0, 100) +
  labs(x="City", y="Matches")

# casting match date column to date type
match_dates = data.frame(date=as.Date(data$Match_Date, format="%d-%b-%y"))
head(match_dates, 2)

# finding the matches played per month
match_dates = match_dates %>%
  mutate(month=month(date)) %>% 
  group_by(month) %>% 
  summarise(count=length(month))
head(match_dates)

# plotting matches played by month
ggplot(match_dates, aes(x=month, y=count, fill=month)) + 
  geom_bar(stat="identity") + 
  geom_text(aes(label=month.name[month]), vjust=-0.5) +
  labs(x="Month", y="Matches Played")