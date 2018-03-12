#include"SeqList.h"
#include<iostream>
void SeqList::SeqListInit()
{
	a = (int *)malloc(sizeof(int)*SeqListInitCapacity);
	capacity = SeqListInitCapacity;
	if (a == NULL)
	{
		return;
	}
	size = 0;
}
//¿¿-1 ¿¿¿¿¿¿
int SeqList::findByKey(int value)
{
	int p = -1;
	for (int i = 0; i < size; i++)
	{
		if (a[i] == value)
		{
			p = i;
		}
	}
	return p ;
}
int SeqList::findByValue(int key)
{
	if (key >= size || key<0)
	{
		return -1;
	}
	return a[key];
}
void SeqList::PushBack(int value)
{
	CheckNULL;
	if (OutofCapacity)
		IncreaseCapacity();
	a[size++] = value;
}
int SeqList::PopBack()
{
	CheckNULL -1;
	CheckSize  -1;
	return a[--size];
}
void SeqList::PushFront(int value)
{
	CheckNULL;
	if (OutofCapacity)
		IncreaseCapacity();
	size++;
	//i-1 ×óÖ¸Õë  iÓÒÖ¸Õë
	for (int i = size - 1; i >0; i--)
	{
		a[i] = a[i-1];
	}
	a[0] = value;
}
int SeqList::PopFront()
{
	CheckNULL - 1;
	CheckSize - 1;
	for (int i = 0; i < size - 1; i++)
	{
		a[i] = a[i + 1];
	}
	size--;
}
void SeqList::insert(int key, int value)
{
	CheckNULL;
	if (key>size) return;
	size++;
	for (int i = size - 1; i - 1 >= key; i--)
	{
		a[i] = a[i - 1];
	}
	a[key] = value;

}
int SeqList::removeByKey(int key)
{
	CheckNULL - 1;
	CheckSize - 1;
	if (key > size - 1) return -1;
	int ret = findByValue( key);
	for (int i = key; i + 1 < size ; i++)
	{
		a[i] = a[i + 1];
	}
	size--;
	return ret;
}
int SeqList::removeByValue(int value)
{
	removeByKey(findByKey(value));
}
int SeqList::IncreaseCapacity()
{
	int *need_free = a;
	int new_capacity = 2 * size;
	int *tmp = (int *)malloc(sizeof(int)* new_capacity);
	if (tmp == NULL)
	{
		return -1;
	}
	for (int i = 0; i < size; i++)
	{
		tmp[i] = a[i];
	}
	a = tmp;
	capacity = new_capacity;
	free(need_free);
	return 1;
}
void SeqList::showSeqList()
{
	CheckNULL;
	CheckSize;
	for (int i = 0; i < size; i++)
	{
		std::cout <<"a["<<i<<"]=>"<< a[i]<<"  ";
	}
	std::cout <<std::endl<<"size:"<<size<<std::endl<<"capacity:"<<capacity<<std::endl;
}
