#! /bin/bash

gcc mat_mult.c -O2 -o mat_mult_base
gcc mat_mult.c -O2 -D DEROULAGE -o mat_mult_deroulage
gcc mat_mult.c -O2 -funroll-loops -o mat_mult_funroll