#include<stdio.h>
#define range 2000
int main()
{
	double size = range;//sqrt函数不接受int
	int i;
	int j;
	int check[range] = { 0 };// 0代表是素数 
	for (i = 2; i *i< range; i++)//C=P*O;sqrt range 左边筛完 右边就肯定找不到了
	{
		if (!check[i])//如果是素数才进行剔除它组成的合数
		{
			for (j = 2 * i; j < range; j += i)
			{
				check[j] = 1;//剔除素数组成的合数
			}
		}
	}
	for (i = 2; i < range; i++)
	{
		if (check[i] == 0)//打印留下来的素数
		{
			printf("%d ", i);
		}
	}
	getchar();
	return 0;
}