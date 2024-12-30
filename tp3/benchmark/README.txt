############## PARTIE 1 ##############
================================
#commande shell
================================
#variable d'environnement pour le nombre de thread
export OMP_NUM_THREADS=4
-----------------------------
#commande de compilation
gcc -O2 -fopenmp ./matrixmatrixmultiply.c -o ./matrix-gcc
icx -O2 -qopenmp ./matrixmatrixmultiply.c -o ./matrix-icc
-----------------------------
#comande pour lancer le script de création des datas gcc et icc
./script.sh 
-----------------------------
================================
#commande R
================================
#stocker les data des benchmarks dans des varialbes en R
X <- read.csv("bench_gcc.data", header=F)$V1
Y <- read.csv("bench_icc.data", header=F)$V1
-----------------------------
#verifier si les datas ont été attribuées au variable
summary(X)
summary(Y)
-----------------------------
#tracer le plot
boxplot(X,Y,names=c("bench_gcc","bench_icc"),
		col=c("blue","pink"),
		ylab="secondes",
		main="Temps d’exécution",
		outline=FALSE)
-----------------------------
================================
############## PARTIE 2 ##############
================================
#commande shell
================================
#variable d'environnement pour le placement de thread avec gcc et icc

KMP_AFFINITY = explicit #pour icc uniquementcpermet de spécifier le placement des threads manuellement avec la variable "GOMP_CPU_AFFINITY"
export GOMP_CPU_AFFINITY="0 1 2 3"

#pour connaitre la position des coeurs avec likwid
likwid-topology -g
-----------------------------
#lancer script création des datas gcc et icc pour les placement de thread
./script_placement_thread_gcc.sh
./script_placement_thread_icc.sh
-----------------------------
================================
#commande R
================================
#stocker les data des benchmarks dans des varialbes en R
bench_gcc_scatter <- read.csv("bench_gcc_scatter.data", header=F)$V1
bench_icc_scatter <- read.csv("bench_icc_scatter.data", header=F)$V1
------------------
bench_gcc_compact <- read.csv("bench_gcc_compact.data", header=F)$V1
bench_icc_compact <- read.csv("bench_icc_compact.data", header=F)$V1
-----------------------------
#verifier si les datas ont été attribuées au variable
summary(bench_gcc_scatter)
summary(bench_icc_scatter)
------------------
summary(bench_gcc_compact)
summary(bench_icc_compact)
-----------------------------
#tracer le plot
boxplot(bench_gcc_scatter,bench_icc_scatter,names=c("bench_gcc_scatter","bench_icc_scatter"),
		col=c("blue","pink"),
		ylab="secondes",
		main="Temps d’exécution",
		outline=FALSE)
------------------
boxplot(bench_gcc_compact,bench_icc_compact,names=c("bench_gcc_compact","bench_icc_compact"),
		col=c("blue","pink"),
		ylab="secondes",
		main="Temps d’exécution",
		outline=FALSE)
-----------------------------
================================