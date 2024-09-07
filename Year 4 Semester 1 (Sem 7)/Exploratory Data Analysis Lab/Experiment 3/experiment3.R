library(dplyr)
library(tidyr)
library(magrittr)

setwd("/Users/abhi/College Work/Year 4 Semester 1 (Sem 7)/Exploratory Data Analysis Lab/Assignment 2")
data = read.csv("DS2_Match.csv")

# arrange()
# arrange by win type
win_type_arranged = data %>% arrange(Win_Type)
View(win_type_arranged)

# arrange by city name
city_name_arranged = data %>% arrange(City_Name)
View(city_name_arranged)

# select()
# selecting only match date
match_dates = data %>% select(Match_Date)
View(match_dates)

# selecting city and country
city_and_country = data %>% select(City_Name, Host_Country)
View(city_and_country)

# selecting everything but match id
all_but_match_id = data %>% select(-Match_Id)
View(all_but_match_id)

# filter()
# filtering by city name as Bangalore
bangalore_matches = data %>% filter(City_Name == "Bangalore")
View(bangalore_matches)

# filtering by win type as No Result
no_result_matches = data %>% filter(Win_Type == "No Result")
View(no_result_matches)

# filtering by country as India and toss decision as bat
india_bat_matches = data %>% filter(Host_Country == "India", Toss_Decision == "bat")
View(india_bat_matches)

# gather()
custom_data = data.frame(
  Name = c("Abhinav", "Tanush", "Sumathi"),
  English = c(45, 67, 87),
  Math = c(53, 65, 23)
)

# gathering courses
gathered = custom_data %>% gather("Course", "Marks", 2:3)
View(gathered)

# spread()
spread = gathered %>% spread("Course", "Marks")
View(spread)

# group_by() + summarise()
# grouping by country and summarising count
grouped = data %>% group_by(Host_Country) %>%
  summarise(count = n())
View(grouped)

# mutate()
# mutating by adding a column called year
mutated = data %>% mutate(year=format(as.Date(data$Match_Date, format="%d-%b-%y"), "%Y"))
View(mutated)
