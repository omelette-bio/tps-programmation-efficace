#include <stdlib.h>
#include <stdio.h>
#define N 260000000

#ifdef DYNAMIC
float *A, *B, *C;
#else
float A[N], B[N], C[N];
#endif

void vect_add()
{
  for (int i=0; i< N; i++){
    C[i] = A[i] + B[i];
  }
}

int main()
{
    #ifdef DYNAMIC
    A = malloc( N * sizeof(float) );
    B = malloc( N * sizeof(float) );
    C = malloc( N * sizeof(float) );
    #endif

    for (int i = 0; i < N; i++)
    {
        A[i] = 1.5f;
        B[i] = 1.4f;
    }

    vect_add();
    
    fprintf(stdout, "%f\n", C[300]);

    #ifdef DYNAMIC
    free(A);
    free(B);
    free(C);
    #endif

    return 0;
}
