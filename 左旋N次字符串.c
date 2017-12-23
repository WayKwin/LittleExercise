#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
void resver(char *p,int cnt)
{
	char *now = p;
	char *next = p+1;
	char temp = *now;
	
	while (*next != '\0')
	{
		int temp = *now;
		*now = *next;
		*next = temp;
		now++;
		next++;
	}
	cnt--;
	if (cnt > 0)
	{
		resver(p, cnt);
	}
}
int main()
{
	char a[] = { 'a', 'b', 'c', 'd','\0'};//   char *p="abcd";右边的是在只读常量区 不能够修改!
	int cnt;
	scanf("%d", &cnt);
	resver(a,cnt);
	printf("%s", a);
	system("pause");
	return 0;
}