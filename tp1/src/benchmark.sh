#! /bin/bash

compilers=("gcc" "icx")
programs=("mat_mult" "vec_add" "sc_vec_mult")
options=("0" "1" "2" "3" "s")

for comp in "${compilers[@]}";
do
    for prog in "${programs[@]}";
    do
        for opt in "${options[@]}";
        do 
            for _i in {1..4};
            do 
                (/bin/time ./"$prog"_O"$opt"_"$comp"_statique) 2>> res_bench_"$prog"_"$comp"_statique.data
                (/bin/time ./"$prog"_O"$opt"_"$comp"_dynamique) 2>> res_bench_"$prog"_"$comp"_dynamique.data
            done
        done
    done
done