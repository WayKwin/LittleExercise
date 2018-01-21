#include<stdio.h>
int sum(int (*a)[3])
{
	int i; int j=2;
	int sum = 0;
	for (i = 0; i <= 2; i++)
	{
		sum += a[i][i];
		
		while (j>=0)
		{
			if (i == 1 && j == 1)
			{
				j--;
				break;
			}
			sum += a[i][j];
				j--;
				break;
		}
	}

	return sum;
}
int main()
{
	//int* a[3] = { { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 } };//只有在传参的时候数组和指针数组才等价
	int a[3][3] = { { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 } };

		printf("%d", sum(a));
		getchar();
} 