library(maps)
library(ggplot2)

india <- map_data("world", region = "india")

ggplot() +
  geom_polygon(data = india, aes(x = long, y = lat, group = group), 
               color = "black", fill = "lightblue") +
  coord_fixed(1.3) +
  labs(title = "Map of India") +
  theme_void()
