#include<stdio.h>
int Fibonacci1(int n)
{
	int before = 1;
	int now = 1;
	int bbfore;
	while (2<n--)
	{
		bbfore = before;//n-2=n-1
		before = now;//n-1=n;
		now = before + bbfore;//n=n-1+n-2
	}
	return now;
}
int Fibonacci2(int n){

	int g = 1, f = 1;

	while (2<n--)
	{

		g = g + f;//新G=老G+老F

		f = g - f;//新F=新G-老F=老G

	}
	return g;
}
int Fibonacci3(int n)
{
	if (n <= 2)
		return 1;
	return Fibonacci3(n - 1) + Fibonacci3(n - 2);
}

int main()
{
	int g = Fibonacci2(5);
	printf("%d", g);
	getchar();
	return 0;
}