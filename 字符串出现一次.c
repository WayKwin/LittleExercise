#include<stdio.h>
int main()
{
	char arr[] = "aabccdeefb";
	int size = sizeof(arr) / sizeof(arr[0]);
	int i, j;
	printf("第一中方法\n");
	for ( i = 0; i < size; i++)
	{
		//j要从头开始找 否则会出现 aab 扫描到第二个a忽略前面的a认为a是独立的
		for ( j = 0; j < size; j++)
		{

			//注意 剔除 i==j的情况
			if (arr[j] == arr[i]&&(i!=j))
			{
				break;
			}
		}
		if (j == size)
		{
			printf("%c\n", arr[i]);
			//保证只找第一次出现的
			break;
		}
	}
	printf("第二种方法\n");
	// 空间换时间
	int table[26] = { 0 };
	for (int i = 0; i < size; i++)
	{
		table[arr[i] - 'a']++;
	}
	for (int i = 0; i < size; i++)
	{
		if (table[arr[i] - 'a'] == 1)
		{
			printf("%c\n", arr[i]);
			break;
		}
	}
	getchar();
}