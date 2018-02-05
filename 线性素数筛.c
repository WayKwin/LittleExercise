#include<stdio.h>
#include<time.h>
#define range 2000
int main()
{
	int i;
	int j;
	int prime[range] = { 0 };
	int check[range] = { 0 };
	int primes = 0;
	for (i = 2; i < range; i++)
	{
		if (!check[i])
		{
			prime[primes++] = i;
		}
		for (j = 0; j < primes && i*prime[j] < range; j++)
		{
			check[i*prime[j]] = 1;//合数可以化为一系列素数的乘积
			if (!i%prime[j])//储存在prime[j]中的素数都是升序的 找出最小的素因子即可保证不重复选
			{
				break;
			}
		}
	}
	printf("耗时:%.2f S", (double)clock() / CLOCKS_PER_SEC);
	printf("\n");
	for (i = 0; i <primes; i++)
	{
		printf("%d ", prime[i]);
	}

	getchar();
	return 0;
}