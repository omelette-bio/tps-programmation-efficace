export OMP_NUM_THREADS=4
export KMP_AFFINITY=scatter
for i in {1..50} ; 
do
	/usr/bin/time -f "%e" -o tmp ./matrix-icc;
	cat tmp >> bench_icc_scatter.data ;
done

export KMP_AFFINITY=compact
for i in {1..50} ; 
do
	/usr/bin/time -f "%e" -o tmp2 ./matrix-icc; 
	cat tmp2 >> bench_icc_compact.data ;
done

