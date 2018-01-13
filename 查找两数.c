#include<stdio.h>
void search(int *arr, int count)
{
	int n;
	int data1 = 0;
	int data2 = 0;
	int i = 0;
	int flag = 1;
	for (i=0; i < count-1; i++)
	{
		n = arr[i] ^ arr[i + 1];
	}
	while (!(n&flag))
	{
		flag <<= 1;
	}
	for (i = 0; i < count; i++)
	{
		//难点分组处理
		//注意分组 如果与flag的1位   按位相与为0 表示这位肯定为0,而且整个数是0, 否则此位为1,
		//整个数不确定是多少 
		//if ((arr[i] & flag) ==1) wrong
		if ((arr[i] & flag) ==0)
		{
			data1 ^= arr[i];
		}
		else 
		{
			data2 ^= arr[i];
		}
	}
	printf("找到的两数是 %d ,%d", data1, data2);
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4,5, 6,7 };
	int count = sizeof(arr) / sizeof(arr[0]);
	search(arr,count);
	getchar();
	return 0;
}