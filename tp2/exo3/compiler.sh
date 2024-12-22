#! /bin/bash

gcc mat_mult.c -o exemple_ijk
gcc -D IKJ mat_mult.c -o exemple_ikj
gcc -D JIK mat_mult.c -o exemple_jik
gcc -D JKI mat_mult.c -o exemple_jki
gcc -D KIJ mat_mult.c -o exemple_kij
gcc -D KJI mat_mult.c -o exemple_kji
gcc mat_mult.c -floop-interchange -o exemple_floop
gcc mat_mult.c -O2 -o exemple_ijk_O2
gcc mat_mult.c -floop-interchange -O2 -o exemple_floop_O2
