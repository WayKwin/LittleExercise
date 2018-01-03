#include<stdio.h>
#include<assert.h>
#include<string.h>
char * my_strstr(const char* str, const char* sub)
{
	int len =strlen(str)- strlen(sub);

	while (*str&&len)
	{
	    char *msg = str;
		char *p1 = sub;
		if (*p1 == '\0')
		{
			return NULL;
		}
		while ((*msg == *p1) && *p1)
		{
			msg++;
			p1++;
		}
		if (*p1 == '\0')
		{
			return str;
		}

		else
		{
			len--;
			str++;
		}
		if (*msg == '\0')
		{
			return NULL;
		}
	}
	
}
char *my_strchr(const char*str, const char val)
{
	while (*str != val&&*str)
	{
		str++;
	}
	if (*str != '\0')
	{
		return str;
	}
	else return str;
}
int my_strcmp(const char *str1, const char *str2)
{
	int ret = 0;
	while (!(ret = *str1 - *str2) && *str1++&&*str2++);//while括号里里*str2++//循环结束str指向\0后面

	if (ret > 0)
	{
		return 1;
	}
	else if (ret < 0)
	{
		return -1;
	}
	return 0;
}
void* my_memcopy(void*dst, const *src,int size)
{
	
	char *p1 = (char *)src;
	char *p2 = (char*)dst;
	while (size--)
	{
		*p2++ = *p1++;
	}
	return dst;
}
void* my_memmove(void*dst, const *src, int size)
{

}
int main()
{
	char a[] = "1234";
	char b[] ="cc";
	char *c = (char*)my_memcopy(b, a, 4);//乱码是因为拷贝大于B字符串长度的话会把b中的'\0'覆盖掉
	printf("%s", c);
	//char a[] = "ab";
	//char b[] = "abcd";
	//int c = my_strcmp(a, b);
	//printf("%d", c);
	//char b[] = "defe";
	//char *c=my_strstr(a, b);
	//printf("%s", c);
	getchar();
	return 0;
	
}