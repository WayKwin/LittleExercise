#include<stdio.h>

int main()
{
	int arr[] = { 3, 2, 3, 2, 3, 2, 3 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int lo = 0;
	int  hi = lo + size-1;
	while (1)
	{
		while ( ((arr[lo]&1) == 1 ) && (lo < hi))
		{
			lo++;
		}
		//又是这里运算优先级错误,导致debug了好久
		//以后碰到位运算一定要带括号
		//   (arr[hi]&1) == 0!!!!!
		//算术运算>位运算>逻辑运算
		while ( ( (arr[hi]&1) == 0 )&& (lo < hi))
		{
			hi--;
		}
		if (hi <= lo)
		{
			break;
		}
		int temp = arr[lo];
		arr[lo] = arr[hi];
		arr[hi] = temp;
	}
	for (int i = 0; i < size; i++)
	{
		printf("%d", arr[i]);
	}
	getchar();
}