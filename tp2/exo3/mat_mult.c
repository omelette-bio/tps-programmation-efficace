#include <stdio.h>

#define N 2000
#define M 2000
#define P 2000

float A[N][P], B[P][M], C[N][M];

int main()
{
    int i,j,k;

    for ( i = 0; i < N; i++ )
    {
        for ( j = 0; j < P; j++ )
        {
            A[i][j] = 1.5f;
        }
    }

    for ( i = 0; i < P; i++ )
    {
        for ( j = 0; j < M; j++ )
        {
            B[i][j] = 1.4f;
        }
    }

    #ifdef ijk
    for (i=0; i< N; i++){
        for (j=0; j< M; j++){
            for (k=0; k< P; k++){
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    #elif ikj
    for (i=0; i< N; i++){
        for (k=0; k< P; k++){
            for (j=0; j< M; j++){
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    #elif jik
    for (j=0; j< M; j++){
        for (i=0; i< N; i++){
            for (k=0; k< P; k++){
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    #elif jki
    for (j=0; j< M; j++){
        for (k=0; k< P; k++){
            for (i=0; i< N; i++){
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    #elif kji
    for (k=0; k< P; k++){
        for (j=0; j< M; j++){
            for (i=0; i< N; i++){
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    #elif kij
    for (k=0; k< P; k++){
        for (i=0; i< N; i++){
            for (j=0; j< M; j++){
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    #else
    for (i=0; i< N; i++){
        for (j=0; j< M; j++){
            for (k=0; k< P; k++){
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
    #endif

    printf("%f, %f, %f\n", A[500][500], A[999][999], A[0][0]);
    printf("%f, %f, %f\n", B[500][500], B[999][999], B[0][0]);
    printf("%f, %f, %f\n", C[500][500], A[999][999], C[0][0]);
}