#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define N 510000000
#define pas 8
float x, tab[N];
int i,j;

int main()
{
  int a;

  srand(time(NULL));
  
  printf("%d\n", getpid());
  
  scanf("%c", &a);
  for (i=0; i<N; i++) tab[i]=(float) rand();
  for (i=0; i<N; i=i+pas) x=x+tab[i];
  printf("%d\n", x);
}
