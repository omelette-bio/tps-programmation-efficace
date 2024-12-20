#! /bin/bash

# "bloc_base" "bloc_l1" "bloc_l1_kji" "bloc_l1_jki" "bloc_l1_floop_block" "bloc_l2" "bloc_l2_kji" "bloc_l2_jki" "bloc_l2_floop_block" "bloc_l3" "bloc_l3_kji" "bloc_l3_jki" "bloc_l3_floop_block"
orders=("bloc_base" "bloc_l1" "bloc_l2" "bloc_l3" "bloc_floop_block")

for order in "${orders[@]}";
do
    for _i in {1..4}; 
    do 
        (/bin/time -f "%e" ./mat_mult_"$order") > /dev/null 2>> data.txt 
    done
done

python3 export_time_data_for_report.py