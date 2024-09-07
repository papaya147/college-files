options(timeout = 1000)
install.packages("sparklyr")
library("sparklyr")
spark_available_versions()
spark_installed_versions()

sc <- spark_connect(master="local[*]", 
                    version = "3.5",
                    config = spark_config(),
                    spark_home = "/opt/homebrew/Cellar/apache-spark/3.5.1/libexec/")
cars = copy_to(sc, mtcars)
cars
spark_web(sc)

library("DBI")
dbGetQuery(sc, "SELECT COUNT(*) FROM mtcars")
