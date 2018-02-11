#include<stdio.h>
int Drinkpop(int money)
{
	int drink = money;
	int empty = money ;
	while (empty > 1)
	{
		drink += empty / 2;//每次都增加的是当前空瓶子的一半
		empty = empty / 2 + empty%2;//计算当前空瓶子
	}
	//wrong
	//int empty = money/2 ;
	//while (empty > 1)
	//{
	//	drink += empty / ;//每次都增加的都是当前的瓶子.只有第一次是空瓶子的一般
	//	empty = empty / 2 + empty % 2;//计算当前空瓶子
	return drink;
}
int main()
{
	printf("%d", Drinkpop(20));
	getchar();
	
}