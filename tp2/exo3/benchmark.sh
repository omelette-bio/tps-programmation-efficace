#! /bin/bash

orders=("ijk" "ikj" "jik" "jki" "kij" "kji")
#orders=("ijk" "ijk_O2" "floop" "floop_O2")

for order in "${orders[@]}";
do
    for _i in {1..4}; 
    do 
        (/bin/time -f "%e" ./exemple_"$order") > /dev/null 2>> data.txt 
    done
done

python3 export_time_data_for_report.py

rm data.txt