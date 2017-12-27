#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <stdio.h> 
int main()
{
	int i, j, n = 0, a[17][17] = { 0 };
	while (n<1 || n>16)
	{
		printf("请输入杨辉三角形的行数:");
		scanf("%d", &n);
	}
	/*当n=4的时候
	  数组情况为  1 0 0 0
	             1 1 0 0
				 1 2 1 0
				 1 3 3 1   先把第一列置1 这样从第二行第二个开始 是上面两数之和 打印的时候只打印 j<=i的部分(对角线)

	*/
	for (i = 0; i<n; i++)           
		a[i][0] = 1; /*第一列全置为一*/
	for (i = 1; i<n; i++)
	for (j = 1; j <= i; j++)
		a[i][j] = a[i - 1][j - 1] + a[i - 1][j];/*每个数是上面两数之和*/
	for (i = 0; i<n; i++) /*输出杨辉三角*/
	{
		for (j = 0; j <= i; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}

	system("pause");
	return 0;
}