#include<stdio.h>
int add(int x, int y)
{
	return x + y;
}
int sub(int x, int y)
{
	return x - y;
}
int mul(int x, int y)
{
	return x * y;
}
int div(int x, int y)
{
	if (y == 0)
	{
		printf("´íÎó,³ıÊıÎª0");
		return 0;
	}
	return x / y;
}
int main()
{
	int x,y;
	int choose;
	int ret;
	int(*a[])(int, int) = { 0, add, sub, mul, div };
	while (choose)
	{
		printf("**************\n");
		printf("1:add    2:sub\n");
		printf("3.sub   4.div\n");
		printf("0.exit\n");
		printf("**************\n");
		scanf("%d%d", &x, &y);
		ret = (a[choose])(x,y);
		
	
	}
	getchar();
	return 0;
}