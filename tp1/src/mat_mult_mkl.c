#include <stdlib.h>
#include <stdio.h>
#include "mkl.h"
#define N 6000
#define M 6000
#define P 6000

#ifdef DYNAMIC
double *A, *B, *C;
#else
double A[N][P], B[P][M], C[N][M];
#endif


void mat_mult()
{
    // Define scalar multipliers
    const float alpha = 1.0f;
    const float beta = 0.0f;

    #ifdef DYNAMIC
    // Use MKL's cblas_sgemm for dynamic allocation
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 
                N, M, P, alpha, A, P, B, M, beta, C, M);
    #else
    // Use MKL's cblas_sgemm for static allocation
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 
                N, M, P, alpha, &A[0][0], P, &B[0][0], M, beta, &C[0][0], M);
    #endif
}


int main()
{
    int i, j;
    #ifdef DYNAMIC
    A = malloc( N * P * sizeof(float) );
    B = malloc( P * M * sizeof(float) );
    C = malloc( N * M * sizeof(float) );
    #endif

    for ( i=0; i<N; i++ )
    {
        for ( j=0; j<P; j++ )
        {
            #ifdef DYNAMIC
            A[i*N+j] = 1.5f;
            #else
            A[i][j] = 1.5f;
            #endif
        }
    }

    for ( i=0; i<P; i++ )
    {
        for ( j=0; j<M; j++ )
        {
            #ifdef DYNAMIC
            B[i*P+j] = 1.4f;
            #else
            B[i][j] = 1.4f;
            #endif
        }
    }

    mat_mult();

    #ifdef DYNAMIC
    free(A);
    free(B);
    free(C);
    #endif

    #ifdef DYNAMIC
    fprintf(stderr, "%f %f %f\n", A[500], B[500], C[500]);
    #else
    fprintf(stderr, "%f %f %f\n", A[500][500], B[500][500], C[500][500]);
    #endif
    
    return 0;
}
