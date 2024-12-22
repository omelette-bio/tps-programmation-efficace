#! /bin/bash

gcc mat_mult.c -O2 -o exemple_ijk
gcc -D IKJ mat_mult.c -O2 -o exemple_ikj
gcc -D JIK mat_mult.c -O2 -o exemple_jik
gcc -D JKI mat_mult.c -O2 -o exemple_jki
gcc -D KIJ mat_mult.c -O2 -o exemple_kij
gcc -D KJI mat_mult.c -O2 -o exemple_kji
gcc mat_mult.c -floop-interchange -O2 -o exemple_floop
