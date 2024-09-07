options(timeout = 10000)

install.packages("cowplot")
install.packages("googleway")
install.packages("ggplot2")
install.packages("ggrepel")
install.packages("ggspatial")
install.packages("libwgeom")
install.packages("sf")
install.packages("rnaturalearth")
install.packages("rnaturalearthdata")

library("ggplot2")
theme_set(theme_bw())
library("sf")
library("rnaturalearth")
library("rnaturalearthdata")

world <- ne_countries(scale = "medium", returnclass = "sf")
class(world)

ggplot(data = world) +
  geom_sf()
ggplot(data = world) +
  geom_sf() +
  xlab("Longitude") + ylab("Latitude") +
  ggtitle("World map", subtitle = paste0
          ("(", length(unique(world$NAME)), 
            " countries)"))

# Map color (geom_sf)
ggplot(data = world) + 
  geom_sf(color = "black", fill = "lightblue")


ggplot(data = world) +
  geom_sf(aes(fill = pop_est)) +
  scale_fill_viridis_c(option = "plasma", trans = "sqrt")

# Projection and Extent
ggplot(data = world) +
  geom_sf() +
  coord_sf(crs = "+proj=laea +lat_0=52 +lon_0=10 +x_0=4321000 +y_0=3210000 +ellps=GRS80 +units=m +no_defs ")

#
ggplot(data = world) +
  geom_sf() +
  coord_sf(xlim = c(-102.15, -74.12), ylim = c(7.65, 33.97), expand = FALSE)
