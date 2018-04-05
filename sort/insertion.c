#include"sort.h"
void sort (int *a,int length)
{
    int i = 0;
    int j;
    for(i = 1; i<length; i++)
    {
        for( j = i; j > 0; j-- )
        {
            if( a[j] < a[j - 1 ] )
            {
                exch(a[j],a[j-1]);
            }
        }
    }
    show(a,length);
}
int main()
{
    int a[] = {1,8,6,43,6,8,5,3,7,8,4};
    int size = sizeof(a)/sizeof(a[0]);
    sort(a,size);
    return 0;
}
