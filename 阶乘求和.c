#include<stdio.h>
//½×³ËÇóºÍ
int main()
{
	int i = 1;
	//int j = 1;
	int m = 1;
	int sum = 0;
	//for (i=1; i <=4; i++)
	//{
	//	m = 1;
	//	for (j = 1; j <= i; j++)
	//	{
	//		
	//		m *= j;
	//		
	//	}
	//	sum += m;
	//}
	for (i = 1; i <= 4; i++)
	{
		m *= i;
		sum += m;
	}
	printf("%d", sum);
	getchar();
}