#include<stdio.h>
#include<stdlib.h>
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
void destoryNode(linkNode* node)
{
    free(node);
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
    *head=initNode('c');
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

int* init()
{
     int a = 3;
     printf("%u",&a);
     int *p = &a;
     return p;
}
int main()
{
    init();
    printf("%u",init());
    return 0;
}
