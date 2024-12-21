#! /bin/bash

gcc -D BASE_CASE mat_mult.c -O2 -o mat_mult_bloc_base
gcc -D BASE_CASE -floop-block mat_mult.c -O2 -o mat_mult_bloc_floop_block

gcc -D BLOC_L1 mat_mult.c -O2 -o mat_mult_bloc_l1_ijk
gcc -D BLOC_L1 -D ikj mat_mult.c -O2 -o mat_mult_bloc_l1_ikj
gcc -D BLOC_L1 -D jik mat_mult.c -O2 -o mat_mult_bloc_l1_jik
gcc -D BLOC_L1 -D jki mat_mult.c -O2 -o mat_mult_bloc_l1_jki
gcc -D BLOC_L1 -D kji mat_mult.c -O2 -o mat_mult_bloc_l1_kji
gcc -D BLOC_L1 -D kij mat_mult.c -O2 -o mat_mult_bloc_l1_kij

gcc -D BLOC_L2 mat_mult.c -O2 -o mat_mult_bloc_l2_ijk
gcc -D BLOC_L2 -D ikj mat_mult.c -O2 -o mat_mult_bloc_l2_ikj
gcc -D BLOC_L2 -D jik mat_mult.c -O2 -o mat_mult_bloc_l2_jik
gcc -D BLOC_L2 -D jki mat_mult.c -O2 -o mat_mult_bloc_l2_jki
gcc -D BLOC_L2 -D kji mat_mult.c -O2 -o mat_mult_bloc_l2_kji
gcc -D BLOC_L2 -D kij mat_mult.c -O2 -o mat_mult_bloc_l2_kij

gcc -D BLOC_L3 mat_mult.c -O2 -o mat_mult_bloc_l3_ijk
gcc -D BLOC_L3 -D ikj mat_mult.c -O2 -o mat_mult_bloc_l3_ikj
gcc -D BLOC_L3 -D jik mat_mult.c -O2 -o mat_mult_bloc_l3_jik
gcc -D BLOC_L3 -D jki mat_mult.c -O2 -o mat_mult_bloc_l3_jki
gcc -D BLOC_L3 -D kji mat_mult.c -O2 -o mat_mult_bloc_l3_kji
gcc -D BLOC_L3 -D kij mat_mult.c -O2 -o mat_mult_bloc_l3_kij