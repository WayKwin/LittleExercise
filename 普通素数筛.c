#include<stdio.h>
#include<math.h>
#define size 2000


int main()
{
	int check[size] = { 0 };
	int prime[size] = { 0 };
	int pos = 0;//prime素数数组的下标  i是素数
	int i = 2, j;
	for (i; i < size; i++)
	{
		if (!check[i])
		{
			prime[pos++] = i;
		}
		
		for (j = 2 * i; j < size; j += i)
		{
			check[j] = 1;
		}
	}
	for (i = 0; i < pos; i++)
	{
		printf("%d ", prime[i]);
	}
	getchar();
}