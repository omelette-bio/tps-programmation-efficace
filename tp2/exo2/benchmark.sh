#! /bin/bash

orders=("question1" "question2" "sans_deroulage")

for order in "${orders[@]}";
do
    for _i in {1..4}; 
    do 
        (/bin/time -f "%e" ./exemple_"$order") > /dev/null 2>> data.txt 
    done
done

python3 export_time_data_for_report.py