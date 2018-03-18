#include"LinkNode.c"
#define show  printf("\n=========%s==========\n",__FUNCTION__)
linkNode* head = NULL;
void testinitLink()
{
    show;
    initLink(&head);
}
void testPushBack()
{
    show;
    linkListPushBack(&head,'b');
    linkListPushBack(&head,'c');
    linkListPushBack(&head,'d');
}
void testPushFront()
{
    show;
    linkListPopFront(&head);
    linkListPopFront(&head);
}
void testinsert()
{
    show;
   linkListInsert(head,'h');
}
void testfind()
{
   /*linkNode* ret =  linkListFind(head,'b');*/
    /*printf("%c\n",ret->element);*/
    linkListFind(head,'g');
}
int main()
{
    testinitLink();
    testPushBack();
    testfind();
    /*testinsert();*/
    if(head != NULL)
    {
        printf("不为空");
    }
    linkListShow(head);
    return 0;
}
