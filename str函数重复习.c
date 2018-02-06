#include<stdio.h>
int strcmp(const char *str1,const char *str2)
{
	int ret = 0;
	while (!(ret = *str1 - *str2) && *str1++&&*str2++);

	return ret>0 ? 1 : ret == 0 ? 0 : -1;
}
void* memcpy(void *dst, const void *src,int size)
{
	char *d = (char*)dst;
	char *s = (char*)src;
	while ((*d++ = *s++, --size));
}

void* memmove(void *dst, const void *src, int size)
{
	char *d = (char*)dst;
	char *s = (char*)src;

	if (s + size > d)//不对称边界 当s+size-1>=d是就会重叠
	{
		int m1 = size;
	    while (--m1)
		{
			s++;
			d++;
		}
		while (size--)
		{
			*d-- = *s--;
		}
		
	}
	else 
	while ((*d++ = *s++, --size));
}
memset(void*dst, int c, int size)
{
	char*d = (char*)dst;
	while (size--)
	{
		*d = c;

	}
}

int main(){
	char a[] = "1234";
	char b[] = "abcd";
	memmove(a,b,2);
	getchar();
	return 0;
}