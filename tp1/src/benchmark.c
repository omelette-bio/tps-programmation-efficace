#include <stdlib.h>
#include <stdio.h>
#define N 2000
#define M 260000000
#define P 260000000


#ifdef DYNAMIC
float *A, *B, *C;
float *D, *E, *F;
float* G;
#else
float A[N][N], B[N][N], C[N][N];
float D[M], E[M], F[M];
float G[P];
#endif
float s;


void vect_add()
{
  for (int i=0; i< M; i++){
    F[i] = D[i] + E[i];
  }
}

void mat_mult()
{
    for (int i=0; i< N; i++){
        for (int j=0; j< N; j++){
            for (int k=0; k< N; k++){
                #ifdef DYNAMIC
                C[i*N+j] = C[i*N+j] + A[i*N+k] * B[k*P+j];
                #else
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
                #endif
            }
        }
    }
}

void sc_vec_mult()
{
    for (int i=0; i< P; i++){
        G[i] = G[i] * s;
    }
}

int main()
{
    int i, j;
    #ifdef DYNAMIC
    A = malloc( N * N * sizeof(float) );
    B = malloc( N * N * sizeof(float) );
    C = malloc( N * N * sizeof(float) );
    
    D = malloc( M * sizeof(float) );
    E = malloc( M * sizeof(float) );
    F = malloc( M * sizeof(float) );

    G = malloc( P * sizeof(float) );
    #endif

    s = 2.34;
    
    for ( int i = 0; i < P; i++ )
    {
        G[i] = 1.2;
    }

    for (int i = 0; i < M; i++)
    {
        D[i] = 1.5f;
        E[i] = 1.4f;
    }


    for ( i=0; i<N; i++ )
    {
        for ( j=0; j<N; j++ )
        {
            #ifdef DYNAMIC
            A[i*N+j] = 1.5f;
            B[i*N+j] = 1.4f;
            #else
            A[i][j] = 1.5f;
            B[i][j] = 1.4f;
            #endif
        }
    }

    vect_add();
    mat_mult();
    sc_vec_mult();


    #ifdef DYNAMIC
    fprintf(stderr, "%f\n", C[500]);
    fprintf(stderr, "%f\n", F[500]);
    fprintf(stderr, "%f\n", G[500]);
    #else
    fprintf(stderr, "%f\n", C[500][500]);
    fprintf(stderr, "%f\n", F[500]);
    fprintf(stderr, "%f\n", G[500]);
    #endif

    #ifdef DYNAMIC
    free(A);
    free(B);
    free(C);
    free(D);
    free(E);
    free(F);
    free(G);
    #endif
    
    return 0;
}
