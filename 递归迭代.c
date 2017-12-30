#include<stdio.h>
#include<assert.h>
//不创建第三方参数使用递归来求字符串长度;
//int mystrlen(const char* a)
//{
//	while (*a != '\0')
//	{
//	
//	return 1 + mystrlen(a + 1);
//	}
//	return 0;
//}
//输入1234 输出1 2 3 4 递归
//void printfNum(int num)
//{
//	if (num >= 10)
//	{
//		num/=10;//wrong
//		printfNum(num);
//	}
//	printf(" %d ", num%10);
//}
//int fe(int num)//递归形式每次要开辟新的栈帧 麻烦
//{
//	if (num <= 2)
//	{
//		return 1;
//	}
//	return fe(num - 1) + fe(num - 2);
//}
//int fe1(int num)
//{
//
//	
//		int result;
//		int pre_result;
//		int pre_pre_result;
//
//		result  = pre_result  = 1;
//
//		while (num > 2)
//		{
//			num  -= 1;
//			pre_pre_result  = pre_result;
//			pre_result  = result;
//			result  = pre_result  + pre_pre_result;
//		}
//		return result;
//	
//}