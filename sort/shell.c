#include"sort.h"
void sort(int *a,int length)
{
    int i,j;
    int h = 1;
    while(h < length/3)
    {
        h = 3 * h + 1;
    }
    while(h >= 1)
    {
        for( i = h ;i < length; i++ )
        {
            for(j = i; j >= h ;j -= h)
            {
                if( a[j] < a[j - h] )
                {
                    exch(a[j],a[j-h]);
                }
            }
        }
            h /= 3;
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
