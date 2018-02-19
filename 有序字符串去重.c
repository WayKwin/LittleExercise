#include<stdio.h>
int uniquify(char* a)
{
	//针对有序序列
	int i=0 ,j=0;
	while (a[++j])//从第二个序列开始   bb
	{

		//一直把不同的a[j]从a[1]开始一次赋值
		if (a[i] != a[j])
		{
			a[++i] = a[j];
		}
		//else J一直移动没有赋值动作
	
		
	}
	a[++i] = '\0';
}
int main()
{
	char a[] = "aaaabbbccccd";
	uniquify(a);
	printf("%s", a);

	system("pause");
}