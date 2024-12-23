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
            $comp "$prog".c -O"$opt" -o "$prog"_O"$opt"_"$comp"_statique
            $comp "$prog".c -O"$opt" -D DYNAMIC -o "$prog"_O"$opt"_"$comp"_dynamique
        done
    done
done