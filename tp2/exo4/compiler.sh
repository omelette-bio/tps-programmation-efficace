#! /bin/bash

gcc -D BASE_CASE mat_mult.c -O2 -o mat_mult_bloc_base

gcc -D BLOC_L1 mat_mult.c -O2 -o mat_mult_bloc_l1
gcc -D BLOC_L1 -D jki mat_mult.c -O2 -o mat_mult_bloc_l1_jki
gcc -D BLOC_L1 -D kji mat_mult.c -O2 -o mat_mult_bloc_l1_kji
gcc -D BLOC_L1 -floop-block mat_mult.c -O2 -o mat_mult_bloc_l1_floop_block

gcc -D BLOC_L2 mat_mult.c -O2 -o mat_mult_bloc_l2
gcc -D BLOC_L2 -D jki mat_mult.c -O2 -o mat_mult_bloc_l2_jki
gcc -D BLOC_L2 -D kji mat_mult.c -O2 -o mat_mult_bloc_l2_kji
gcc -D BLOC_L2 -floop-block mat_mult.c -O2 -o mat_mult_bloc_l2_floop_block

gcc -D BLOC_L3 mat_mult.c -O2 -o mat_mult_bloc_l3
gcc -D BLOC_L3 -D jki mat_mult.c -O2 -o mat_mult_bloc_l3_jki
gcc -D BLOC_L3 -D kji mat_mult.c -O2 -o mat_mult_bloc_l3_kji
gcc -D BLOC_L3 -floop-block mat_mult.c -O2 -o mat_mult_bloc_l3_floop_block