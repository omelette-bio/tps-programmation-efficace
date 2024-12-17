#!/bin/bash

compilers=("gcc" "icx")
values=(1500 2000)
trucs=("question1" "question2" "base")

for compiler in "${compilers[@]}"; do
    for value in "${values[@]}"; do
        $compiler mat_mult.c -D QUESTION1 -D N="$value" -D M="$value" -D P="$value" -o "$compiler"_mat_mult_question1_"$value"
        $compiler mat_mult.c -D QUESTION2 -D N="$value" -D M="$value" -D P="$value" -o "$compiler"_mat_mult_question2_"$value"
        $compiler mat_mult.c -D N="$value" -D M="$value" -D P="$value" -o "$compiler"_mat_mult_base_"$value"
    done
done

for _ in {1..10}; do
    for compiler in "${compilers[@]}"; do
        for value in "${values[@]}"; do
            for truc in "${trucs[@]}"; do
                /usr/bin/time -f "%e" ./"$compiler"_mat_mult_"$truc"_"$value" > /dev/null 2> toto
                res=$(cat toto)
                echo "$compiler, $value, $truc, $res" >> data.csv
            done
        done
    done
done