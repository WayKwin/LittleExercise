#include<stdio.h>
int drinkWater(int moeny)
{
	int bottle = moeny;
	int drink = bottle;
	int empty = bottle ;
	while (empty > 1)
	{
		drink += empty/2;
		empty = empty / 2 + empty % 2;
	}
	//while (empty > 1)
	//{
	//	
	//	drink++;
	//	empty /= 2;
	//	
	//}
	return drink;
}

int main()
{
	printf("%d",drinkWater(7));
	getchar();
	return 0;
}