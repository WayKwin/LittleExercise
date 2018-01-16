#include<stdio.h>
int main()
{
	float  height=100;
	float s = 0;
	int i=0;
	for (i=1; i <= 10; i++)
	{
		//第一次落地 只有下去的
		if (i == 1)
		{
			s += height;
			continue;
		}
		//普通情况是弹上去和落下来的
		height /= 2;
	
		//第十次落地只有下去的worng
		//第十次也是在第九次后弹起来h/2后在落下来
		/*if (i == 10)
		{
			s += height;
			continue;
		}*/
		s += 2 * height;
	}
	//第十次上来的高度(i=11)
	height /= 2;
	printf("%f,%f", s, height);
	getchar();
}