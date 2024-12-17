#include <stdlib.h>
#include <stdio.h>
#define N 2000
#define M 2000
#define P 2000

#ifdef DYNAMIC
float *A, *B, *C;
#else
float A[N][P], B[P][M], C[N][M];
#endif


void mat_mult()
{
    for (int i=0; i< N; i++){
        for (int j=0; j< M; j++){
            for (int k=0; k< P; k++){
                #ifdef DYNAMIC
                C[i*N+j] = C[i*N+j] + A[i*N+k] * B[k*P+j];
                #else
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
                #endif
            }
        }
    }
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
