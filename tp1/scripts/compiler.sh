#! /bin/bash

programs=("mat_mult" "sc_vec_mult" "vec_add")

mkdir -p bin

for prog in "${programs[@]}";
do 
    icx ../src/"$prog".c -D DYNAMIC -o "$prog"_DYNAMIC
    icx ../src/"$prog".c -o "$prog"_STATIC
done;

for prog in "${programs[@]}";
do
    for _i in {0..3};
    do
        echo "./""$prog""_STATIC"
        /bin/time ./"$prog"_STATIC
    done
    for _i in {0..3};
    do
        echo "./""$prog""_DYNAMIC"
        /bin/time ./"$prog"_DYNAMIC
    done
done