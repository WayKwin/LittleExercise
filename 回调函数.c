#include<stdio.h>
int int_cmp(void*p1, void*p2)
{
	return (*(int *)p1 > *(int *)p2);
}

void swap(void *p1, void*p2, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		//以字节为单位进行赋值
	 	char temp = *((char *)p1 + i);//p1+i的括号
		*((char *)p1 + i) = *((char *)p2 + i);
		*((char *)p2 + i) = temp;
		
	}
}
void Bubble(void *base, int size,int count, int(*cmp)(void*p1, void*p2))//这里可已换成char(*cmp)(void* p1,void*p2)
{
	int i, j;
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - 1 - i; j++)
		{
			//虽然传的是一个字节(char *),但是在比较的时候又变成四个字节了(int *)
			if (cmp((char *)base + j*size, (char *)base + (j + 1)*size))
			{
				//传参是 两个数的首字节 用for循环一次遍历交换4个字节 (一个数)
				swap((char *)base + j*size, (char*)base + (j + 1)*size,size);
			}
		}
	}
}
