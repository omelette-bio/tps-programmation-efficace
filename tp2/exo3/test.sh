#! /bin/bash

programs=("matrix-multiply")
flags=("ijk" "ikj" "jik" "jki" "kij" "kji" "floop" "floop_O2")

echo "flags, time" > time_data.csv

for flag in "${flags[@]}";
do
    echo "executing exemple_$flag"
    /usr/bin/time -f %e ./exemple_$flag > /dev/null 2> tmp.txt
    exec_time=$(cat tmp.txt)
    echo "$flag, $exec_time" >> time_data.csv
done

rm tmp.txt