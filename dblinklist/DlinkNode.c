#include"dblinklist.h"

//带头 带环
//prev next 都指向自己 带环
DLinkNode* CreateDLinkNode(DLinkType val)
{
    DLinkNode* ret = (DLinkNode*)malloc(sizeof(DLinkNode));
    ret->data = val;
    return ret;
}
//要把指针变成NULL 所以传二级指针
void DestroyDLinkNode(DLinkNode** node)
{
    free(*node);
    *node = NULL;
}
void DLinkListInit(DLinkNode** phead)
{
    *phead = (DLinkNode*)malloc(sizeof(DLinkNode));
    (*phead)->data = 0;
    (*phead)->prev = *phead;
    (*phead)->next = *phead;
}
// tail = head->prev
// head vs new_node
// // head->prev = new_node;
// new_node->next = head;
// tail vs new_node
//  tail->next = new_node;
//  new_node->prev = tail;
void DLinkListPushBack(DLinkNode* head,DLinkType data)
{
    if( head == NULL )
        return ;
    DLinkNode* teil = head->prev;
    DLinkNode* new_node = CreateDLinkNode(data);
    teil->next = new_node;
    new_node->prev = teil;
    head->prev = new_node;
    new_node->next = head;
}
void DLinkListPushFront(DLinkNode* phead,DLinkType data)
{
    if(phead == NULL)
        return ;
    //?
    /*if( phead->next = phead )*/
        /*return ;*/
    DLinkNode* new_node = CreateDLinkNode(data);
    new_node->prev =phead;
    new_node->next = phead->next;
    phead->next->prev = new_node;
    phead->next = new_node;
}
void DLinkListPopBack(DLinkNode* phead)
{
    if( phead == NULL )
        return;
    if( phead->next == NULL )
        return;
    DLinkNode* to_delete = phead->prev;
    phead->prev = to_delete->prev;
    to_delete->prev->next = phead;
    DestroyDLinkNode(&to_delete);
}
void DLinkListPopFront(DLinkNode* phead)
{
    if(phead == NULL)
        return;
    if(phead->next == NULL)
        return;
    DLinkNode * to_delete;
    phead->next = to_delete;
    phead->next = to_delete->next;
    to_delete->next->prev = phead;
    DestroyDLinkNode(&to_delete);
}
void DLinkLsitInsert(DLinkNode* phead,DLinkNode* pos,DLinkType data)
{
    DLinkNode* prev = pos->prev;
    DLinkNode* new_node = CreateDLinkNode(data);
    new_node->prev = prev;
    prev->next = new_node;
    new_node->next = pos;
    pos->prev = new_node;
}
void DLinkLsitInsertAter(DLinkNode* phead,DLinkNode* pos,DLinkType data)
{
    if( phead == NULL )
        return;
    DLinkNode* next = pos->next;
    DLinkNode* new_node = CreateDLinkNode(data);
    new_node->prev = pos;
    pos->next = new_node;
    next->prev = pos;
    new_node->next = next;
}
DLinkNode* DLinkListFind(DLinkNode* phead,DLinkType to_find)
{
    if(phead == NULL)
        return NULL;
    if(phead->next == phead)
    {
        return NULL;
    }
    DLinkNode* cur = phead->next;
    while(cur != phead )
    {
        if(cur->data == to_find)
            return cur;
        cur = cur->next;
    }
    return NULL;
}
void DLinkListEarse(DLinkNode* phead,DLinkNode* to_delete)
{
    if( phead == NULL )
        return ;
    if( phead->next = NULL )
        return ;
    DLinkNode* cur = phead->next;
    while(cur != phead)
    {
        if(cur == to_delete)
        {
            DLinkNode* prev = to_delete->prev;
            DLinkNode* next = to_delete->next;
            prev->next = next;
            next->prev = prev;
            DestroyDLinkNode(&to_delete);
            return;
        }
    }
    return ;
}
void DLinkListRemove(DLinkNode* phead,DLinkType to_delete_value)
{
    if( phead == NULL )
        return;
    if( phead->next == NULL )
        return ;
    DLinkNode* node = DLinkListFind(phead,to_delete_value);
    DLinkNode* prev = node->prev;
    DLinkNode* next = node->next;
    prev->next = next;
    next->prev = prev;
    DestroyDLinkNode(&node);
}
void DLinkListRemoveAll(DLinkNode** phead)
{
    if((*phead) == NULL)
        return;
    DLinkNode* cur = (*phead)->next;
    DLinkNode* tmp = (*phead)->next;
    while(cur != *phead)
    {
        tmp = cur;
        cur = cur->next;
        DestroyDLinkNode(&tmp);
    }
    DestroyDLinkNode(phead);
}
//////////////////////////////////////////////
////////测试代码
//////////////////////////////////////////////
#if 1
#include<stdio.h>
#define show_head
//要是 字符0 不可见字符, (int)强转而且使用 %d打印
DLinkNode* head;
void TestInit()
{
    DLinkListInit(&head);
    DLinkListPushBack(head,'a');
    DLinkNode* teil = head->prev;
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'c');
    DLinkListPushBack(head,'d');
    DLinkNode* cur = head->next;
    while(cur != head)
    {
        printf("[%c|%p] ",cur->data,cur);
        cur = cur->next;
    }
    printf("\n");
    cur = head->prev;
    while(cur != head)
    {
        printf("[%c|%p] ",cur->data,cur);
        cur=cur->prev;
    }
    printf("\n");
}
void testRemoveAll()
{
    DLinkListInit(&head);
    DLinkListPushBack(head,'a');
    DLinkNode* teil = head->prev;
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'c');
    DLinkListPushBack(head,'d');
    DLinkNode* cur = head->next;
    while(cur != head)
    {
        printf("[%c|%p] ",cur->data,cur);
        cur = cur->next;
    }
    printf("\n");
    cur = head->prev;
    while(cur != head)
    {
        printf("[%c|%p] ",cur->data,cur);
        cur=cur->prev;
    }
    printf("\n");
    DLinkListRemoveAll(&head);
    printf("%d\n",head==NULL);
}
int main()
{
    testRemoveAll();
    /*TestInit();*/
}
#endif
