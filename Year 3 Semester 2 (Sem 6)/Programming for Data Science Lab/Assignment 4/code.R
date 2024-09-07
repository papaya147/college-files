install.packages("quantmod")
install.packages("forecast")
install.packages("xlsx")
install.packages("tseries")
install.packages("timeSeries")
install.packages("dplyr")
install.packages("fGarch")
install.packages("prophet")
library(prophet)
library(quantmod)
library(forecast)
library("xlsx")
library(tseries)
library(timeSeries)
library(dplyr)
library(fGarch)

getSymbols("AMZN", src = "yahoo", from = "2015-01-01")
AMZN

print(adf.test(AMZN$AMZN.Close))

auto.arima(AMZN$AMZN.Close, lambda = "auto")

modelfit <- auto.arima(AMZN$AMZN.Close, lambda = "auto")
price_forecast <- forecast(modelfit, h = 30)
plot(price_forecast)

head(price_forecast$mean)
head(price_forecast$lower)
tail(price_forecast$upper)

N = length(AMZN$AMZN.Close)
n = 0.7 * N
train = AMZN$AMZN.Close[1:n, ]
test = AMZN$AMZN.Close[(n + 1):N, ]
trainarimafit <- auto.arima(train, lambda = "auto")
predlen = length(test)
trainarimafit <- forecast(trainarimafit, h = predlen)

meanvalues <- as.vector(trainarimafit$mean)
precios <- as.vector(test$AMZN.Close)
plot(meanvalues, type = "l", col = "red")
lines(precios, type = "l")
