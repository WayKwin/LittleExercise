#include<stdio.h>
#include<stdlib.h>
void fun(int * p)
{
    int *new_p = (int *) malloc(sizeof(int));
    *new_p = 1;
    p = new_p;
}
int main()
{
    int a = 3;
    fun(&a);
    printf("%d\n",a);

}
