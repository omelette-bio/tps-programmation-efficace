#! /bin/bash

orders=("bloc_base" "bloc_l1_ijk" "bloc_l2_ijk" "bloc_l3_ijk" "bloc_floop_block" "bloc_l1_ijk" "bloc_l1_ikj" "bloc_l1_jik" "bloc_l1_jki" "bloc_l1_kij" "bloc_l1_kji" "bloc_l2_ijk" "bloc_l2_ikj" "bloc_l2_jik" "bloc_l2_jki" "bloc_l2_kij" "bloc_l2_kji" "bloc_l3_ijk" "bloc_l3_ikj" "bloc_l3_jik" "bloc_l3_jki" "bloc_l3_kij" "bloc_l3_kji")


for order in "${orders[@]}";
do
    for _i in {1..4}; 
    do 
        (/bin/time -f "%e" ./mat_mult_"$order") > /dev/null 2>> bench.txt 
    done
done

#python3 export_time_data_for_report.py
