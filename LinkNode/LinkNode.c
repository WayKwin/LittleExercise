#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
typedef char eleType;
typedef struct linkNode
{
    eleType element;
    struct linkNode* next;
}linkNode;
typedef struct link
{
   linkNode* head;
   size_t  size;
}link;
/*linkNode* initNode(char val)*/
//{
    //linkNode node;
    //node.element = val;
    //node.next = NULL;
    //return &node;
/*}*/
linkNode* initNode(eleType c)
{
    linkNode* node=(linkNode *)malloc(sizeof(linkNode));
    node->element = c;
    node->next = NULL;
    return node;
}
void destoryNode(linkNode** node)
{
    /*(*node)->next = NULL;*/
    free(*node);
    //把p值为NULL 不代表p_pre 就是NULL了
    //p_pre还指向原来P的地址 这是赋值操作,不是动态绑定
    *node = NULL;

}
void initLink(linkNode** head)
{
    if (head == NULL)
    {
        //传入非法地址
        return ;
    }
    if(*head == NULL)
    {
    *head=initNode('a');
    }
 }
void linkListPushBack(linkNode** head,eleType e)
{
    if(head == NULL)
        return ;
    if(*head == NULL)
    {
        initLink(head);
        return ;
    }
    linkNode* p=*head;
    while((p)->next != NULL)
    {
        p = p->next;
    }
    p->next=initNode(e);
}
eleType linkListPopBack(linkNode** head)
{
    if(head == NULL)
    return ' ';
    if(*head == NULL)
    {
        return ' ' ;
    }
    linkNode* p=*head;
    linkNode* p_pre = *head;
    while((p)->next != NULL)
    {
        p_pre = p;
        p = p->next;
    }
   eleType ret =  p->element;
     if(p == *head)
    {
        destoryNode(head);
        return ' ';
    }
    destoryNode(&p);
    p_pre->next = NULL;
    //特殊处理首节点
    //修改p前面的指针指向
    return ret;
}
linkNode* linkListFind(linkNode* head,eleType to_find )
{
    while(head != NULL && head->element != to_find)
    {
        head = head->next;
    }
    if(head == NULL)
    {
        printf("not find\n");
        return NULL ;
    }
    return head;
}
void linkListInsert(linkNode* pos,eleType value)
{
    /*linkNode** oldpos = &pos;*/

    linkNode* newNode=initNode(value);
    //不用考虑首节点// 前插仅仅是把后插把值交换了
     /*if( pos == *head )*/
    /*{*/
        /** head = newNode;*/
       /*(*head)->next = pos;*/
        /*return;*/
    /*}*/
    eleType oldvalue = pos->element;
    pos->element = value;
   newNode->element = oldvalue;
     newNode-> next =  pos -> next ;
    pos->next = newNode;

}
void linkListInsertAfter(linkNode* pos,eleType value)
{
    linkNode* newNode = initNode(value);
    newNode->next = pos->next;
    pos->next = newNode;
}
void linklistErase(linkNode** head,linkNode* pos)
{
    if(pos == *head)
    {
     destoryNode(head);
     return ;
    }
    linkNode *tmp =  *head;
    while( tmp->next != pos)
    {
        tmp = tmp->next;
    }
    tmp->next = pos->next;
    destoryNode(&pos);
}
void LinkListReverse(LinkNode* head)
{
    if(*head == NULL)
        return;
    LinkNode * pre;

}
void  lisadnkListPushFront(linkNode** head,eleType c)
{
    //initlink里面检查head是否合法
    initLink(head);
    linkNode* node = initNode(c);
    node->next = *head;
    *head = node;
}
eleType linkListPopFront(linkNode** head)
{
    if(head == NULL)
        return ' ';
    if(*head == NULL)
        return ' ';
    eleType ret = (*head)->element;
    linkNode* oldHead = *head;
    *head = (*head)->next;
    destoryNode(&oldHead);
    return ret;
}
void linkListShow(linkNode* head)
{
    for( ; head != NULL; head = head->next )
    {
        printf (" %c -> ", head -> element );
    }
    printf("NULL\n");
}

