#include<stdio.h>
void swapword(char *lo, char*hi)
{
	char *lower = lo;
	char *higher = hi;
	while (lower < --higher)
	{
		char temp = *lower;
		*lower = *higher;
		*higher = temp;
		lower++;
		
	}
}

void resverse(char *str, int size)
{
	char *lo = str;
	char*hi = str + size-1;
	while (lo < --hi)
	{
		char temp = *lo;
		*lo = *hi;
		*hi = temp;
		lo++;
		
	}
	lo = str;
	hi = str;
	while (1)
	{
		while (*hi != '\0'&&*hi != ' ')
		{
			hi++;
		}
		swapword(lo, hi);
		if (*hi == '\0')
		{
			return;
		}
		hi += 1;
		lo = hi;
	}
}
int main()
{
	char a[] = "student a am i";
	int size = sizeof(a) / sizeof(a[0]);
	resverse(a,size);
	printf("%s", a);
	getchar();
	return 0;
}