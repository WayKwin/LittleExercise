#include<stdio.h>
#include<string.h>

void exchstr(char**str1,char**str2)
{
	char *c = NULL;
	c = *str1;
	*str1 = *str2;
	*str2 = c;
}
////可变参数这里内部无法创建num长度数组,用指针还有bug
////char** bubble_sort(int num, ...)
////{
////	
////	int loopnum = num-1;
////	int loopnum1 = num;
////	int i = 0;
////	int j = 0;
////	//char* b[num];//形参不能做数组长度
////	va_list arg;
////	_crt_va_start(arg, num);
////	char**b = _crt_va_arg(arg, char*);
////	char** ret = b;
////	while (loopnum--)
////	{
////	*b= _crt_va_arg(arg, char*);//b指向左后一个元素往后的一个元素
////	b++;
////	}
////	_crt_va_end(arg);
////	for (i=0; i < num; i++)
////	{
////		b = ret; 
////		for (j=0; j < num - i; j++)
////		{
////			if (strcmp(*b, *(b + 1))>0)//char*
////			{
////				exchstr(*b, *(b + 1));
////			}
////			b++;
////		}
////	}
////	return b;
////}
//void bubble_sort(char* a[3])
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 3-i; j++)
//		{
//			if (my_strcmp(a[j], a[j + 1])<0)
//			{
//				exchstr(&a[j], &a[j + 1]);
//			}
//		}
//	}
//	//strcmp(a[0], a[1]);
//	printf("%s", a[0]);
//}
int main()
{
	char a[] = "cba";
	char b[] = "bba";
	char c[] = "aba";
	int i = 0;
	int j = 0;
	char* strarr[3] = { a, b, c };
	//exchstr(&a, &b);
	//exchstr(&b, &c);
	//exchstr(&a, &b);
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2 - i; j++)
		{
			if (strcmp(strarr[j], strarr[j + 1])>0)
			{
				exchstr(&strarr[j], &strarr[j + 1]);
			}
		}
	}
	for (i=0; i < 3; i++)
	{
		printf("%s\n", strarr[i]);
	}
	//bubble_sort(strarr[3]);
	//printf("--------------------------------" );
	//for (i = 0; i < 3; i++)
	//{
	//	printf("%s\n", strarr[i]);
	//}
	system("pause");
}