# Load necessary libraries
library(dplyr)

setwd("/Users/abhi/College Work/Year 3 Semester 2 (Sem 6)/Programming for Data Science Lab/Assignment 2/")
print(getwd())
file_path <- "Contacts.csv"

df <- read.csv(file_path)

# Displaying a summary of the dataset
summary(df)

# Check for missing values
missing_values <- sum(is.na(df))
cat("Number of missing values:", missing_values, "\n")

# Handle missing values (replace with mean, median, or remove)
# Example: Replace missing values with the mean of the column
df <- df %>% mutate_if(is.character, ~ifelse(is.na(.), "empty", .))

# Remove duplicate rows
df <- distinct(df)

# Check for outliers and handle them if necessary
# Example: Remove outliers from a numeric column
# outliers <- boxplot.stats(df$numeric_column)$out
# df <- df %>% filter(!numeric_column %in% outliers)

# Save the cleaned dataset to a new file
# Replace 'cleaned_dataset.csv' with your desired file name
write.csv(df, 'cleaned_dataset.txt', row.names = FALSE)
head(df)
