#include<stdio.h>
#define  exch(x) (((x&(0xAAAAAAAA))>>1)|((x&(0x55555555)) << 1))
#define  bigNum(a,b) (a>b?a:b)
int main()
{
	int a = 5;
	int b = 10;
	int c = exch(a);
	int d = bigNum(a, b);
	printf("%d\n%d\n", c, d);
	system("pause");
	return 0;
}
