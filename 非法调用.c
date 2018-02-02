#include <stdio.h>
#include <windows.h>

void *ret = NULL;

void bug()
{
	int x;
	int *q = &x;
	q += 2;
	*q = ret;
	printf("bug: hehe, I am a bug!\n");
	Sleep(2000);
}

int myadd(int x, int y)
{
	int *p = &x;
	p--;

	ret = *p;
	*p = bug;
	printf("myadd: myadd is called, begin return...\n");
	//int z = x + y;
	//return z;
}

int main()
{
	int a = 10;
	int b = 20;

	int c = myadd(a, b);
	__asm{
		sub esp, 4
	}

	printf("main: you should running here!\n");
	printf("res : %d\n", c);
	system("pause");
	return 0;
}