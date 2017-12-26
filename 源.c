#include<stdio.h>
#include<string.h>
#include<assert.h>
void reverse(char *start, char *end)
{
	assert(start);
	assert(end);
	while (start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

void reverse_str(char *str, int sz)
{
	assert(str);               //检测传入的字符串
	char *str1 = str;
	char *left = str;
	char *right = str + sz - 1;
	reverse(left, right);         //先将字符串整体反转
	while (*str1)
	{
		left = str1;
		while ((*str1 != '\0') && (*str1 != ' ')) //找到单词，此处一定要加(*str1 != '\0')条件限制，因为找到最后一个单词的时候，*str1停止向后移动的条件不是找到空格 而是找到结束标识符
		{
			str1++;
		}
		right = str1 - 1;               //此时str1指向单词后方的空格，需要减一方能指向单词的最后一个字母
		reverse(left, right);               //继整体反转后再次反转单词，能使单词拼写顺序恢复过来
		if (*str1 == ' ')             //等于空格让指针后移一位否则不能参与下次循环。
		{
			str1++;
		}
	}
}

int main()
{
	char arr[] = "student a am i";
	int sz = strlen(arr);
	reverse_str(arr, sz);
	printf ("%s", arr);
	getchar();
	return 0;
}