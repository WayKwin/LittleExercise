#include<stdio.h>
//head 和 teil
// teil 可以在head前面
// 只要size<=数组长度
//
//加入动态扩容
#define SeqQueueMaxSize 100
typedef char SeqQueueType;
typedef struct SeqQueue
{
    SeqQueueType* data;
    size_t head;
    size_t tail;
    size_t size;
    size_t capacity;
}SeqQueue;
void SeqQueueInit(SeqQueue* queue);
void SeqQueueDestroy(SeqQueue* queue);
//计算机会做除法//循环减
//效率不高
//但是Maxsize = 2^n 移位操作
//执行效率高
//q->teil %= Maxsize;
//
// if(q->head > Maxsize) head = 0
void SeqQueuePush(SeqQueue* queue,SeqQueueType val);
void SeqQueuePop(SeqQueue* queue);
//------------------------------------------------------------
typedef char NodeType;
typedef struct  Node
{
    NodeType data;
    struct Node* next;
}Node;
typedef struct LinkQueue
{
    Node* head;
    Node* tail;
}LinkQueue;
void LinkQueueInit(LinkQueue* queue);
void LinkQueueDestroy(LinkQueue* queue);
void LinkQueuePush(LinkQueue* queue,NodeType val);
void LinkQueuePop(LinkQueue* queue);


