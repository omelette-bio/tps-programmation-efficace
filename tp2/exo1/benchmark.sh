#! /bin/bash

orders=("base" "deroulage" "funroll")

for order in "${orders[@]}";
do
    for _i in {1..4}; 
    do 
        (/bin/time -f "%e" ./mat_mult_"$order") > /dev/null 2>> data.txt 
    done
done
