#include<stdio.h>
int my_strlen(const char *str)
{
	if (*str=='\0')
		return 0;
	//注意前置++,后置会栈溢出 ,why?
	return  my_strlen(++str) + 1;
}

char *Is_palindromic(char *str,int size)
{
	char *frist = str;
	char *last = str + size - 1;

	while (frist<last)
	{
		if (*frist != *last)
		{
			return "不是回文字符串";
		}
		frist++;
		last--;
	}
	return "是回文数";
}
int main()
{
	char a[] = "abcbcba";
	//printf("%d",my_strlen(a));
	
	printf("%s", Is_palindromic(a, my_strlen(a)));
	getchar();
}