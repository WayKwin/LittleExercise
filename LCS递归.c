#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

char a[30], b[30];
int a_len, lenb;
int LCS(int, int);

int main()
{
	strcpy(a, "ABCBDAB");
	strcpy(b, "BDCABA");
	a_len = strlen(a);
	b_len = strlen(b);
	printf("%d\n", LCS(a_len - 1, b_len - 1));//´ÓÄ©Î²¿ªÊ¼µÝ¹é
	getchar();
	return 0;
}

int LCS(int i, int j)
{ 
	if (i <0|| j <0)
		return 0;
	if (a[i] == b[j])
		return 1 + LCS(i -1, j-1);
	else
		return LCS(i -1, j)>LCS(i, j - 1) ? LCS(i - 1, j) : LCS(i, j - 1);
}