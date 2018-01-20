#include<stdio.h>
//int sum1(int *a, int n)
//{
//	return (n < 1) ? 0 : sum(a, n - 1) + a[n - 1];//数组下标从0开始
//}
int sum2(int *a, int lo, int hi)
{
	if (lo == hi)
		return a[lo];
	int mid = lo + (hi - lo) / 2;
	return sum2(a, lo, mid) + sum2(a, mid + 1, hi);
}
int main()
{
	int a[] = { 1, 2, 3, 4, 5 };
	int size = sizeof(a) / sizeof(a[0]);
	printf("%d", sum2(a,0,4));
	getchar();
	return 0;
}