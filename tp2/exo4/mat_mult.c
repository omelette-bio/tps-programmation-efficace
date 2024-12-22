#include <stdio.h>

#ifdef BLOC_L1
#define BLOC 64
#elif BLOC_L2
#define BLOC 295
#else
#define BLOC 836
#endif

#define N 2000
#define M 2000
#define P 2000

float A[N][P], B[P][M], C[N][M];

int min(int a, int b)
{
    if (a < b) return a;
    else return b;
}

int main()
{
    int i,j,k;
    int i0,j0,k0;

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

    #ifdef BASE_CASE
    for (i=0; i< N; i++){
        for (j=0; j< M; j++){
            for (k=0; k<P; k++){
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
    #elif ikj
    for (i0 = 0; i0 < N; i0 += BLOC)
        for (k0 = 0; k0 < P; k0 += BLOC)
            for (j0 = 0; j0 < M; j0 += BLOC)
                for (i = i0; i < min(i0 + BLOC, N); i++)
                    for (k = k0; k < min(k0 + BLOC, P); k++)
                        for (j = j0; j < min(j0 + BLOC, M); j++)
                            C[i][j] += A[i][k] * B[k][j];
    #elif jki
    for (j0 = 0; j0 < M; j0 += BLOC)
        for (k0 = 0; k0 < P; k0 += BLOC)
            for (i0 = 0; i0 < N; i0 += BLOC)
                for (j = j0; j < min(j0 + BLOC, M); j++)
                    for (k = k0; k < min(k0 + BLOC, P); k++)
                        for (i = i0; i < min(i0 + BLOC, N); i++)
                            C[i][j] += A[i][k] * B[k][j];
    #elif jik
    for (j0 = 0; j0 < M; j0 += BLOC)
        for (i0 = 0; i0 < N; i0 += BLOC)
            for (k0 = 0; k0 < P; k0 += BLOC)
                for (j = j0; j < min(j0 + BLOC, M); j++)
                    for (i = i0; i < min(i0 + BLOC, N); i++)
                        for (k = k0; k < min(k0 + BLOC, P); k++)
                            C[i][j] += A[i][k] * B[k][j];
    #elif kji
    for (k0 = 0; k0 < P; k0 += BLOC)
        for (j0 = 0; j0 < M; j0 += BLOC)
            for (i0 = 0; i0 < N; i0 += BLOC)
                for (k = k0; k < min(k0 + BLOC, P); k++)
                    for (j = j0; j < min(j0 + BLOC, M); j++)
                        for (i = i0; i < min(i0 + BLOC, N); i++)
                            C[i][j] += A[i][k] * B[k][j];
    #elif kij
    for (k0 = 0; k0 < P; k0 += BLOC)
        for (i0 = 0; i0 < N; i0 += BLOC)
            for (j0 = 0; j0 < M; j0 += BLOC)
                for (k = k0; k < min(k0 + BLOC, P); k++)
                    for (i = i0; i < min(i0 + BLOC, N); i++)
                        for (j = j0; j < min(j0 + BLOC, M); j++)
                            C[i][j] += A[i][k] * B[k][j];
    #else //ijk
    for (i0 = 0; i0 < N; i0 += BLOC)
        for (j0 = 0; j0 < M; j0 += BLOC)
            for (k0 = 0; k0 < P; k0 += BLOC)
                for (i = i0; i < min(i0 + BLOC, N); i++)
                    for (j = j0; j < min(j0 + BLOC, M); j++)
                        for (k = k0; k < min(k0 + BLOC, P); k++)
                            C[i][j] += A[i][k] * B[k][j];
    #endif

    printf("%f, %f, %f\n", A[500][500], A[999][999], A[0][0]);
    printf("%f, %f, %f\n", B[500][500], B[999][999], B[0][0]);
    printf("%f, %f, %f\n", C[500][500], A[999][999], C[0][0]);
}
