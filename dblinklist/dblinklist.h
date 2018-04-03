// 带头结点,带环的双向链表
#include<stdio.h>
#include<stdlib.h>
#pragma once
typedef char DLinkType;
typedef struct DLinkNode
{
    //c++ 可以不写struct
    struct DLinkNode* prev;
    struct DLinkNode* next;
    DLinkType data;
} DLinkNode;

//创建一个连表表示  空
void DLinkListInit(DLinkNode** phead);
//DLinkType*  DLinkListInit(DLinkType* phead);
// 修改头指针的指向 才用传如**
void DLinkListPushBack(DLinkNode* phead,DLinkType data);
void DLinkListPushFront(DLinkNode* phead,DLinkType data);
void DLinkListPopBack(DLinkNode* phead);
void DLinkListPopFront(DLinkNode* phead);
//在pos之前插入data
void DLinkLsitInsert(DLinkNode* phead,DLinkNode* pos,DLinkType data);
//在pos之后插入data
void DLinkLsitInsertAter(DLinkNode* phead,DLinkNode* pos,DLinkType data);
//查找
DLinkNode* DLinkListFind(DLinkNode* phead,DLinkType to_find);
//pos指向head 不能删除head
//函数命名要用动词 动名词 或者
//变量要是 名词

void DLinkListEarse(DLinkNode* phead,DLinkNode* to_delete);
void DLinkListRemove(DLinkNode* phead,DLinkType to_delete_value);
void DLinkListRemoveAll(DLinkNode** phead);
