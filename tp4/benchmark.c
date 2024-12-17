#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#define N 2147483647
// modifiez la valeur de N selon vos besoins

int main()
{
    float x,y,z,t;
    int i;
    int a;

    printf("pid: %d\n", getpid());

    scanf("%c", &a);

    printf("continuons l'execution !\n");
    for (i = 0; i<N; i++){
        x=x+y;
        y=x+t;
        z=x+z;
        x=t+y;
        t=y+x;
    }
    printf("%d, %d, %d, %d\n", x, y, z, t);
    return 0;
}