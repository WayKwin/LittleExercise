#include"sort.h"
int main()
{
    int a[] = {3,2,4,5,6,8,6,3,1,2,3,4,5};
    int i = 0;
    int j = 0;
    int cur_max = sizeof(a)/sizeof(a[0])  ;
    for(i = 0; i < cur_max - 1;i ++ )
    {
        int min = i;
        for( j = i + 1; j < cur_max; j++ )
        {
            if (a[min] > a[j])
            {
                min = j;
            }
        }
        int tmp = a[min];
        a[min] = a[i];
        a[i] = tmp;
    }
    show(a,cur_max);
    return 0;
}
