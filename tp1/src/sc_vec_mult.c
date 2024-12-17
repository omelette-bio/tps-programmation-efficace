#include <stdlib.h>
#include <stdio.h>
#define N 100000000

#ifdef DYNAMIC
float* A;
#else
float A[N];
#endif
float s;

void sc_vec_mult()
{
    for (int i=0; i< N; i++){
        A[i] = A[i] * s;
    }
}

int main()
{
    s = 2.34;
    
    #ifdef DYNAMIC
    A = malloc( N * sizeof(float) );
    #endif
    
    for ( int i = 0; i < N; i++ )
    {
        A[i] = 1.2;
    }

    sc_vec_mult();
    
    fprintf(stderr, "%f %f %f\n", A[500], A[5000], A[50000]);

    #ifdef DYNAMIC
    free(A);
    #endif
    
    return 0;
}
