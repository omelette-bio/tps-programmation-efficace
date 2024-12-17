#include <stdio.h>

#define N 1000
#define M 1000
#define P 1000

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

    // for (i=0; i< N; i++){
    //     for (j=0; j< M; j++){
    //         #ifdef DEROULAGE
    //         for (k=0; k< P; k+=8){
    //             C[i][j] = C[i][j] + A[i][k] * B[k][j];
    //             C[i][j] = C[i][j] + A[i][k] * B[k+1][j];
    //             C[i][j] = C[i][j] + A[i][k] * B[k+2][j];
    //             C[i][j] = C[i][j] + A[i][k] * B[k+3][j];
    //             C[i][j] = C[i][j] + A[i][k] * B[k+4][j];
    //             C[i][j] = C[i][j] + A[i][k] * B[k+5][j];
    //             C[i][j] = C[i][j] + A[i][k] * B[k+6][j];
    //             C[i][j] = C[i][j] + A[i][k] * B[k+7][j];
    //         }
    //         #else
    //         for (k=0; k<P; k++){
    //             C[i][j] = C[i][j] + A[i][k] * B[k][j];
    //         }
    //         #endif
    //     }
    // }

    // for (i = 0; i < N; i += 3) {
    //     for (j = 0; j < M; j++) {
    //         for (k = 0; k < P; k++) {
    //             C[i][j] = C[i][j] + A[i][k] * B[k][j];
    //         }
    //         if (i + 1 < N) {
    //             for (k = 0; k < P; k++) {
    //                 C[i+1][j] = C[i+1][j] + A[i+1][k] * B[k][j];
    //             }
    //         }
    //         if (i + 2 < N) {
    //             for (k = 0; k < P; k++) {
    //                 C[i+2][j] = C[i+2][j] + A[i+2][k] * B[k][j];
    //             }
    //         }
    //     }
    // }

    // i,j,k
    for (i=0; i< N; i++){
        for (j=0; j< M; j++){
            for (k=0; k< P; k++){
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    // i,k,j
    for (i=0; i< N; i++){
        for (k=0; k< P; k++){
            for (j=0; j< M; j++){
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    // j,i,k
    for (j=0; j< M; j++){
        for (i=0; i< N; i++){
            for (k=0; k< P; k++){
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    printf("%f, %f, %f\n", A[500][500], A[999][999], A[0][0]);
    printf("%f, %f, %f\n", B[500][500], B[999][999], B[0][0]);
    printf("%f, %f, %f\n", C[500][500], A[999][999], C[0][0]);
}