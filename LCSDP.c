#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

char a[500], b[500];
char num[501][501]; ///记录中间结果的数组
char flag[501][501];    ///标记数组，用于标识下标的走向，构造出公共子序列
void LCS(); ///动态规划求解
void getLCS();    ///采用倒推方式求最长公共子序列

int main()
{
	int i;
	strcpy(a, "CDEFG");
	strcpy(b, "BDCABA");
	memset(num, 0, sizeof(num));
	memset(flag, 0, sizeof(flag));
	LCS();
	printf("%d\n", num[strlen(a)][strlen(b)]);
	getLCS();
	getchar();
	return 0;
}

void LCS()
{
	int i, j;
	for (i = 1; i <= strlen(a); i++)
	{
		for (j = 1; j <= strlen(b); j++)
		{
			if (a[i - 1] == b[j - 1])   ///注意这里的下标是i-1与j-1
			{
				num[i][j] = num[i - 1][j - 1] + 1;
				flag[i][j] = 1;  ///对角线
			}
			else if (num[i][j - 1]>num[i - 1][j])
			{
				num[i][j] = num[i][j - 1];
				flag[i][j] = 2;  ///向左
			}
			else
			{
				num[i][j] = num[i - 1][j];
				flag[i][j] = 3;  ///向上 
			}
		}
	}
}

void getLCS()
{

	char res[500];
	int i = strlen(a);
	int j = strlen(b);
	int k = 0;    ///用于保存结果的数组标志位
	while (i>0 && j>0)
	{
		if (flag[i][j] == 1)   ///如果是对角线标记
		{
			res[k] = a[i - 1];
			k++;
			i--;
			j--;
		}
		else if (flag[i][j] == 2)  ///如果是向左标记
			j--;
		else if (flag[i][j] == 3)  ///如果是向上标记
			i--;
	}

	for (i = k - 1; i >= 0; i--)
		printf("%c", res[i]);
}