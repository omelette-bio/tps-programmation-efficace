#! /bin/bash


#orders=("sans_deroulage" "question1" "question2")
orders=("sans_deroulage_O2" "question1_O2" "question2_O2")

for order in "${orders[@]}";
do
    for _i in {1..4}; 
    do 
        (/bin/time -f "%e" ./exemple_"$order") > /dev/null 2>> data.txt 
    done
done

python3 export_time_data_for_report.py

rm data.txt