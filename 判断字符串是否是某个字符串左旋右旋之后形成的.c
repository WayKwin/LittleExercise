#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
void leftTwist(char *p,int cnt)
{
	//左旋一次就是把最左边的字母依次移到字符串末尾
	//两次就是在一次的基础上再移动一个字母
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
		leftTwist(p, cnt);
	}
}
void rightTwist(char *p, int cnt, int len)
{
	char *start = p + len - 1;
	char *before = p + len - 2;
	int exchTime = len-1;
	while (exchTime)
	{
		char temp = *start;
		*start = *before;
		*before = temp;
		*start--;
		*before--;
		exchTime--;
	}
	cnt--;
	if (cnt > 0)
	{
		rightTwist(p, cnt, len);
	}
}
int isBeforeStr(char *a, char*b, int aLen)
{
	//判断是否是左旋还是右旋
	int ifLeft = 0;
	int ifRight = 0;
	int i ;
	//先判断一次看是不是原来的字符串,然后旋转一次...看每次能否和b字符串对上
		if (strcmp(a, b) == 0)
		{
			ifLeft = 1;
			
		}
		if (ifLeft == 0)
		{
	    for (i=1; i < aLen; i++)
	    {
		leftTwist(a, i);
		if (strcmp(a, b) == 0)
		{
			ifLeft = 1;
			break;
		}
	}
		}
		//ifleft=0表明不可能和原字符串相等也不是左移相等
	if (0 == ifLeft)
	{
		for (i = 1; i < aLen; i++)
		{
			if (strcmp(a, b) == 0)
			{
				ifRight = 1;
				break;
			}
			rightTwist(a, i, aLen);
		}
	}
	//左移右移任何对上了就OK
	if (ifRight || ifLeft)
	{
		return 1;
	}
	else
		return 0;

}
int main()
{
	char a[] = { 'a', 'b', 'c', 'd','\0'};//   char *p="abcd";右边字符串是在只读常量区 不能够修改!
	char b[] = { 'b', 'c', 'd' ,'a','\0'};
	int len = strlen(a);
	printf("%d", isBeforeStr(a, b, len));
	system("pause");
	return 0;
}