import pandas as pd

timestamp = []
timestamp.append(pd.Timestamp(year = 2022, month = 1, day = 12))
timestamp.append(pd.Timestamp(year = 2022, month = 1, day = 7, hour = 22))
timestamp.append(pd.Timestamp.now())
timestamp.append(pd.Timestamp(year = 2022, month = 12, day = 30).date())
timestamp.append(pd.Timestamp.now().date())
timestamp.append(pd.Timestamp(year = 2022, month = 1, day = 12, hour = 12, minute = 34, second = 56).time())
timestamp.append(pd.Timestamp.now().time())
for i in timestamp:
    print(i)
