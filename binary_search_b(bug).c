#include<iostream>
using namespace::std;
int binary_search(int *a, int size, int key)
{
	int lo = 0;
	int hi = size;
	int mid;
	while (hi - lo)
	{
		mid = lo + (hi - lo) >> 1;
		if (key < a[mid])
			hi = mid;
		else
			lo = mid + 1;

	}
	return lo--;

}
int main()
{
	int a[] = { 0, 16, 24, 35, 47, 59, 62, 73, 88, 99 };
	int key = 24;
	int index = binary_search(a, sizeof(a) / sizeof(a[0]), key);
	cout << key << " is located at:" << index;
	system("PAUSE");
	return 0;
}