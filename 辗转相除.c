#include<stdio.h>

int GCD(int p, int q)
{
	if (q == 0)
		return p;
	int r = p%q;
	return GCD(q, r);
}
int LCM(int p, int q)
{
	int z = p*q;
	return z / GCD( p,  q);

}

int main()
{
	printf("%d", LCM(12, 18));
	getchar();
}
