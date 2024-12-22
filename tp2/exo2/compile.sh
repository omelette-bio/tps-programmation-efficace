#!/bin/bash

gcc mat_mult.c -o exemple_sans_deroulage
gcc -D QUESTION1 mat_mult.c -o exemple_question1
gcc -D QUESTION2 mat_mult.c -o exemple_question2