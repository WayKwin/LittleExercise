#include<stdlib.h>
#include<stdio.h>
int main()
{
    int * p = (int * )malloc(sizeof(int));
    free(p);
    p = NULL;
    printf("%d",p==NULL);
}
