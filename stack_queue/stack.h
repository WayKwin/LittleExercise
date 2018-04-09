#pragma once
#include<stddef.h>
typedef char SeqStackType;
typedef struct seqStack
{
    SeqStackType* data;
    size_t size;
    size_t capacity;
}SeqStack;
void SeqStackInit(SeqStack* stack);
void SeqStackDestroy(SeqStack* stack);
void SeqStackPush(SeqStack* stack,SeqStackType val);
void SeqStackPop(SeqStack* stack,SeqStackType* ret);
//成功失败,返回value
int SeqStackTop(SeqStack* stack,SeqStackType* value);
typedef char LinkStackType;

typedef struct LinkStack
{
    LinkStackType data;
    struct LinkStack* next;
}LinkStack;
void LinkStackInit(LinkStack** stack);
void LinkStackDestroy(LinkStack** stack);
void LinkStackPush(LinkStack** stack,LinkStackType val);
void LinkStackPop(LinkStack** stack);
//成功失败,返回value
int LinkStackTop(LinkStack* stack,LinkStackType* value);

