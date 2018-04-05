#include<stdio.h>
#define exch(x,y) int tmp=x;x=y;y=tmp

int show(int *a,int length)
{
    int i = 0;
    for(i = 0 ; i < length; i++)
    {
      printf("%d ",a[i]);
    }
    printf("\n");
}
void  sort(int *a,int length);
