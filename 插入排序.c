#include<iostream>
using namespace::std;
int main()
{
	int arr[] = { 5, 4, 2, 5, 3, 2, 6, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	for (int i =1; i < size; i++)
	{

		for (int j = i ; j>0; j--)
		{
			//想要提高效率,在内循环先找到最小值,之后在外循环交换一次
			//但发现这样就成选择排序了
			if (arr[j] < arr[j-1])
			{
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
	getchar();
	return 0;
}