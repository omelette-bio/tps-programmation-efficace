#include <stdio.h>

#ifndef N
#define N 2000
#endif

#ifndef M
#define M 2000
#endif

#ifndef P
#define P 2000
#endif

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

    #ifdef QUESTION1
    for (i=0; i< N; i+=3){
        for (j=0; j< M; j++){
            for (k=0; k<P; k++){
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
        if (i+1 < N){
            for (j=0; j< M; j++){
                for (k=0; k<P; k++){
                    C[i+1][j] = C[i+1][j] + A[i+1][k] * B[k][j];
                }
            }
        }
        if (i+2 < N) {
            for (j=0; j< M; j++){
                for (k=0; k<P; k++){
                    C[i+2][j] = C[i+2][j] + A[i+2][k] * B[k][j];
                }
            }
        }
    }
    #elif QUESTION2
    for (i = 0; i < N; i += 3) {
        for (j = 0; j < M; j++) {
            for (k = 0; k < P; k++) {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
            if (i + 1 < N) {
                for (k = 0; k < P; k++) {
                    C[i+1][j] = C[i+1][j] + A[i+1][k] * B[k][j];
                }
            }
            if (i + 2 < N) {
                for (k = 0; k < P; k++) {
                    C[i+2][j] = C[i+2][j] + A[i+2][k] * B[k][j];
                }
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