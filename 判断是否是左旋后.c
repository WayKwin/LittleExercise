#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void exchange(char*begin, char* end)
{
	while (begin < end)
	{
		char temp = *begin;
		*begin = *end;
		*end = temp;
		begin++;
		end--;
	}
}
char * left(char *str,int n)
{
	int size = strlen(str);
	char* ret = str;
	int times = n%size;
  //右旋 把head1和head2交换一下即可
	char* head1 = str;
	char* head2 = str  + times;
	exchange(head1, head2-1 );
	exchange(head2, str + size - 1);
	exchange(str, str + size-1 );
	return  str;

}
//char * left(char *str, int n)
//{
//	int Oldlen = strlen(str);
//	int times = n%Oldlen;
//	注意 abcd 变成abcdabcd  源目的字符串一样的方法
//	char *copystr = (char*)malloc(sizeof(char)*Oldlen + 1);
//	if (*copystr == NULL)
//	{
//		return;
//	}
//	strcpy(copystr, str);
//	strcat(str, copystr);
//	free(copystr);
//	char *ret = str + times;
//	*(ret + strlen(str)) = '\0'; false 注意增长后strlen也变了
//	*(ret + Oldlen) = '\0';
//	return ret;
//}
//char *right(char *str, int n)
//{
//
//	int Oldlen = strlen(str);
//	int times = n%Oldlen;
//	可以把扩容单独封装为一个函数
//	char *copystr = (char*)malloc(sizeof(char)*Oldlen + 1);
//	if (*copystr == NULL)
//	{
//		return;
//	}
//	strcpy(copystr, str);
//	strcat(str, copystr);
//	free(copystr);
//	右旋左旋唯一的区别在ret
//	char* ret = str+Oldlen-1;
//	*(ret + Oldlen) = '\0';
//	return ret;
//	 
//}
int is_le_ri(char *dst, char*src)
{
	int size_d = strlen(dst);
	int size_s = strlen(src);
	if (size_d != size_s)
	{
		return -1;
	}
	if (strcmp(dst, src) == 0)
	{
		return 0;
	}
	int lefttime = size_d;

	
	while (--lefttime>0)//注意使用前置--
	{
		
		if (strcmp(src, left(dst, lefttime)) == 0)
			return 0;
	}
	

	return -1;
}
int main()
{
	char a[] = "dabc";
	char b[] = "bcda";
	//第二种左旋 旋转次序超过两个以上以后会有BUG
	/*while (--size)
	{
		printf("旋转第 %d 次 -->%s\n", size, left(a, size));
	}*/
	printf("%d", is_le_ri(b, a));
	getchar();
}