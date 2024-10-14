# loading libraries and data
library(cluster)
data = iris

# calculating euclidean distance
euclidean = daisy(data[0:4], metric = c("euclidean"))
class(euclidean)

# performing agglomerative clustering with complete linkage
agglomerative_cluster = hclust(euclidean, method = "complete")
plot(agglomerative_cluster, main = "Agglomerative clustering")

# performing agglomerative clustering with single linkage
agglomerative_cluster = hclust(euclidean, method = "single")
plot(agglomerative_cluster, main = "Agglomerative clustering")

# performing agglomerative clustering with mean linkage
agglomerative_cluster = hclust(euclidean, method = "average")
plot(agglomerative_cluster, main = "Agglomerative clustering")

# performing agglomerative clustering with centroid linkage
agglomerative_cluster = hclust(euclidean, method = "centroid")
plot(agglomerative_cluster, main = "Agglomerative clustering")

# performing divisive clustering
divisive_cluster <- diana(as.matrix(euclidean), diss = TRUE, keep.diss = TRUE)
plot(divisive_cluster, main = "Divisive clustering")

# plotting dividing rectangle
rect.hclust(divisive_cluster, k = 2)

# viewing divided groups
group = cutree(divisive_cluster, k = 2)
table(group)
