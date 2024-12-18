library(stats)
library(graphics)
library(vioplot)

X <- read.csv("bench-gcc.data", header = F)$V1
Y <- read.csv("bench-icx.data", header = F)$V1

boxplot(X,Y,names=c("bench1","bench2"),col=c("blue","pink"),ylab="secondes", main="Temps d’exécution")
