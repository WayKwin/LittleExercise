#pragma once
#include<stdlib.h>
#include<stddef.h>
#define SeqListInitCapacity 30
#define SeqListtype size_t//注意是无符号整型
#define CheckNULL if(a==NULL)return
#define OutofCapacity (size>=capacity?1:0)
#define CheckSize if(size<=0)return
class SeqList{
private:
  //可以换成内联函数
	int *a;
	SeqListtype size;
	SeqListtype capacity;
	int IncreaseCapacity();//1成功 0失败
public:
	void SeqListInit();
	SeqList(){ SeqListInit(); }
	~SeqList(){  }
	void PushBack(int value);
	int PopBack();
	void showSeqList();
	void PushFront(int value);
	int PopFront();
	void insert(int key, int value);
	int removeByKey(int key);
	// need to debug
	int removeByValue(int Value);
	int findByKey(int key);
	int findByValue(int value);
};
