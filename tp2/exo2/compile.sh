#!/bin/bash

gcc mat_mult.c -o exemple_sans_deroulage
gcc -D QUESTION1 mat_mult.c -o exemple_question1
gcc -D QUESTION2 mat_mult.c -o exemple_question2

gcc mat_mult.c -O2 -o exemple_sans_deroulage_O2
gcc -D QUESTION1 -O2 mat_mult.c -o exemple_question1_O2
gcc -D QUESTION2 -O2 mat_mult.c -o exemple_question2_O2