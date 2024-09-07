options(timeout = 1000)
install.packages("DBI")
install.packages("RSQLite")
library(DBI)
library(RSQLite)

conn = dbConnect(RSQLite::SQLite(), dbname='papaya', host='localhost', port=3306, 
                 user='root', password='root')
dbWriteTable(conn, "papaya.mtcars", mtcars)
