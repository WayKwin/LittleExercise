#include<stdio.h>

void reverse(int *a,int size)
{
	int *frist = a;
	int *last = a + size-1;
	while (frist < last)
	{
		*frist ^= *last;
		*last ^= *frist;
		*frist ^= *last;
		frist++;
		last--;
	}
}
void bubleup(int *a,int n)
{
	int sorted = 0;
	int i = 0;
	for (sorted = 0; sorted = !sorted; n--)
	{
		for (i = 1; i < n; i++)
		{
			if (a[i] < a[i - 1])
			{
				a[i] ^= a[i - 1];
				a[i - 1] ^= a[i];
				a[i] ^= a[i - 1];
				sorted = 0;
			}
		}
	}
}
//int cmp(void* str1, void*str2)
//{
//	char *str
//}
//void sortString(void *str, int size,int length)
//{
//	char* str1 = (char*)str;
//	int sorted = 0;
//	int i = 0;
//	for (sorted = 0; sorted=!sorted; length--)
//	{
//		for (i = 1; i < length; i++)
//		{
//			if (cmp(str1 + i*size, str1 + (i - 1)*size))
//			{
//				swap(str1 + i*size, str1 + (i - 1)*size,size);
//				sorted = 0;
//			}
//		}
//		
//	}
//}
int main()
{
	//int a[] = { 5, 4, 3,2,1 };
	//reverse(a, sizeof(a) / sizeof(a[0]));
	//bubleup(a, sizeof(a) / sizeof(a[0]));
	
	getchar();

}