 //回文数
#include<stdio.h>
char * Is_palindromic(int a)
{
	int res = 0;
	int temp = a;
	while (temp)
	{
		//将数字翻转 123 变成321;
		res = res * 10 + temp % 10;
		temp /= 10;
	}
	if (res == a)
	{
		return "您输入的数字是回文数";
	}
	else return "不是回文数";
}
int main()
{
	int a = 12321;
	printf("%s", Is_palindromic(a));
	getchar();
}