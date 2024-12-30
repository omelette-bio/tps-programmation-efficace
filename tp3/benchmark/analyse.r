library(stats)
library(graphics)
library(vioplot)

X <- read.csv("bench_gcc.data", header = F)$V1
Y <- read.csv("bench_icc.data", header = F)$V1

pdf("bench_no_affinity.pdf")
boxplot(X,Y,names=c("gcc","icx"),col=c("blue","pink"),ylab="temps en secondes", main="Benchmark sans affinite de threads sur gcc et icx")
dev.off()

A <- read.csv("bench_gcc_compact.data", header = F)$V1
B <- read.csv("bench_icc_compact.data", header = F)$V1

pdf("benchmark_compact.pdf")
boxplot(A,B,names=c("gcc","icx"),col=c("blue","pink"),ylab="temps en secondes", main="Benchmark de la strategie compact avec les compilateurs gcc et icx")
dev.off()

C <- read.csv("bench_gcc_scatter.data", header = F)$V1
D <- read.csv("bench_icc_scatter.data", header = F)$V1

pdf("benchmark_scatter.pdf")
boxplot(C,D,names=c("gcc","icx"),col=c("blue","pink"),ylab="temps en secondes", main="Benchmark de la strategie scatter sur les compilateurs gcc et icx")
dev.off()
