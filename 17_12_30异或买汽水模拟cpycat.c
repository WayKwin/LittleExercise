#include<stdio.h>
#include<assert.h>
//找出单独的数 异或
//int main()
//{
//	int a[] = { 2, 2, 3, 3, 4, 4, 1 };
//	int i = 0;
//	int len = sizeof(a) / sizeof(a[0]);
//	int Num = a[0];
//	for (i=1; i < len; i++)
//	{
//		Num ^= a[i];
//	}
//	printf("单独出现的数是:%d\n", Num);
//	getchar();
//	return 0;
//}
//换汽水问题
//本来想用递归结果发现巨复杂,上网发现就是简单的2*n-1关系
//
//int main()
//{
//	int money = 0;
//	int count = 0;
//	scanf("%d", &money);
//	count = 2 * money - 1;
//	printf("%d\n", count);
//	getchar();
//	return 0;
//}
//错误代码
//////////int CountBottleNumM(int bottle)
//////////{
//////////	//int m = bottle / 2;
//////////	//int r = bottle % 2;
//////////	int count = 0;
//////////
////////
//////////
//////////	if (bottle != 0)
//////////		return bottle + CountBottleNumM(bottle / 2);
//////////		return 0;
//////////}
//////////int CountBottleNumR(int bottle)
//////////{
//////////	int count = 0;
//////////
//////////	while (bottle != 0)
//////////	{
//////////		if (bottle / 2 == 1)
//////////		{
//////////			count++;
//////////		}
//////////		bottle /= 2;
//////////	}
//////////	
//////////	
//////////		return count + CountBottleNumR(count);
//////////	
//////////}
//////////int WeCanDrink(int money)
//////////{
//////////	int bottle = money / 1;
//////////	return CountBottleNumR(bottle) + CountBottleNumM(bottle);
//////////	

char* my_strcpy(char *des,const char *src)
{
	assert(src!=NULL,des!=NULL);
	while ((*des++ = *src++));//赋值语句返回结果是右值 
	return des;
}
char* my_strcat(char *des, const char *src)
{
	assert(src != NULL, des != NULL);
	while (*++des);//注意应该前++,while结束的时候*des的值才是'\0' ;后++ 当*des值是'\0',des还要++一次
	while ((*des++ = *src++));
	return des;
}
int main()
{
	char a[] = "abcd";//注意char *="abcd"不可修改
	char b[] = "efgh";
	my_strcat(a, b);
	printf("%s\n", a);
	my_strcpy(a, b);
	printf("%s\n", a);

	getchar();
}