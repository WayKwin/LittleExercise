#include"LinkNode.c"
#define show  printf("\n=========%s==========\n",__FUNCTION__)
// 关于循环是 head != NULL 还是 head->next != NULL
// 取决于 循环体内要对末节点操作还是只用指向末节点
linkNode* head = NULL;
linkNode* head2 = NULL;
void testinitLink()
{
    show;
    initLink(&head);
}
void testPushBack()
{
    show;
    initLink(&head);
    linkListPushBack(&head,'h');
    linkListPushBack(&head,'g');
    linkListPushBack(&head,'f');
    linkListPushBack(&head,'e');
    linkListPushBack(&head,'d');
    linkListPushBack(&head,'c');
    linkListPushBack(&head,'b');
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
void testReverse()
{
    show;
    initLink(&head);
    linkListPushBack(&head,'b');
    linkListPushBack(&head,'c');
    linkListPushBack(&head,'d');
    linkListPushBack(&head,'d');
    linkListPushBack(&head,'e');
    linkListPushBack(&head,'f');
    linkListPushBack(&head,'g');
    linkListPushBack(&head,'h');
    printf("逆置前链表为:\n");
    linkListShow(head);
    LinkListReverse(&head);
    printf("逆置后链表为: \n");
    linkListShow(head);
}
void testEarse()
{
    show;
    initLink(&head);
    linkListErase2(&head,'a');
}
/*//以下为链表练习*/
// 带环队列吃小孩
void circle(linkNode *head)
{
    linkNode* frist = head;
    while(head->next != NULL)
    {
        head = head -> next;
    }
    head ->next = frist;
}
void eat(linkNode *head, int M)
{
    if (head == NULL)
    {
        return;
    }
    linkNode* cur = head;
    while(cur->next != cur)
    {
       int i = 1;
       for(;i < M; i++)
       {
           cur = cur->next;
       }
       printf("被删除的元素:%c ",cur->element);
       cur->element = cur->next->element;
       cur->next = cur->next->next;
       //内存泄漏
    }
    printf("存活:%c\n",cur->element);
}
void bubbleup(linkNode* head)
{
    show;
    if( head == NULL )
        return ;
    linkNode* teil = NULL;
    linkNode* cur = head;
    while(teil != head)
    {
        //注意结束条件
        for(cur = head;cur->next != teil;cur = cur->next)
        {
            if(cur->element > cur->next->element)
            {
                char tmp = cur->element;
                cur->element = cur->next->element;
                cur->next->element = tmp;
            }

        }
        // 第一次teil等于最后一个元素,第二次就往前移动一个元素
        teil = cur;
    }
}
//merge
int cmp(const linkNode* head1,const linkNode* head2)
{
    return head1->element > head2->element ? \
        1 : head1->element == head2->element ?  0 : -1;
}
linkNode* merge(linkNode* head1, linkNode *head2)
{
    if(head1 == NULL || head2 == NULL)
    return head1 == NULL ? head2 : head1;
    for(; head1 != NULL || head2 != NULL; )
    {
        //短路性质
        if(head1 != NULL && (head2 == NULL || cmp(head1,head2) <= 0))
            head1 = head1->next;
        if(head2 != NULL && (head1 == NULL || cmp(head1,head2) > 0))
        {
            //head2插入head1中
            linkNode *old = head2;
            head2 = head2->next;
            old->next = head1->next;
            head1->next =old;
            //head 1 比 head 2 大 所以要前插,交换元素值
           eleType tmp_value = head1->element;
           head1->element = old->element;
           old->element = tmp_value;

        }
    }
    return head1;
}
void tesetmerge()
{
    show;
    initLink(&head);
    initLink(&head2);
    linkListPushBack(&head,'b');
    linkListPushBack(&head2,'c');
    linkListPushBack(&head,'d');
    linkListPushBack(&head2,'e');
    linkListPushBack(&head,'f');
    linkListPushBack(&head2,'g');
    linkListPushBack(&head,'h');
    printf("before merge :\n");
    linkListShow(head);
    linkListShow(head2);
    merge(head,head2);
    printf("after merge : \n");
    linkListShow(head);
}
//找中点
linkNode* FindMidNode(linkNode* head)
{
    if ( head == NULL )
    {
        return NULL;
    }
    if( head->next == NULL )
    {
        return head;
    }
    linkNode* fastNode = head->next;
    linkNode* slowNode = head;
    //注意是当fastNode为末节点停下来
    while(fastNode->next != NULL)
    {
        //贪心,能走两步不走一步
        fastNode = (fastNode->next->next == NULL? fastNode->next: \
                    fastNode->next->next);
        slowNode = slowNode->next;
    }
    return slowNode;
}
void testFindMidNode()
{
    show;
    initLink(&head);
    linkListPushBack(&head,'b');
    linkListPushBack(&head,'c');
    linkListPushBack(&head,'d');
    linkListPushBack(&head,'e');
    linkListPushBack(&head,'f');
    linkListPushBack(&head,'g');
    linkListPushBack(&head,'h');
    linkListPushBack(&head,'i');
    linkListShow(head);
    printf("中点元素为 : %c\n ",FindMidNode(head)->element);
}
//从后往前第K个节点
linkNode* FindLastKNode(linkNode* head,size_t k)
{
    if( head == NULL )
    {
        return NULL;
    }
    // 快比慢 快k节点,快节点到NULL 慢节点到倒数K
    linkNode* fastNode = head;
    linkNode* slowNode = head;
    //移动次数
    int behind = k-1;
    //如果移动次数大于节点长度 返回首节点
    while(behind--&& fastNode->next != NULL)
    {
        fastNode = fastNode->next;
    }
    while(fastNode->next != NULL)
    {
        slowNode = slowNode->next;
        fastNode = fastNode->next;
    }
    return slowNode;
}
void testLastKnode()
{
    show;
    initLink(&head);
    linkListPushBack(&head,'b');
    linkListPushBack(&head,'c');
    linkListPushBack(&head,'d');
    linkListPushBack(&head,'e');
    linkListPushBack(&head,'f');
    linkListPushBack(&head,'g');
    linkListPushBack(&head,'h');
    linkListPushBack(&head,'i');
    linkListShow(head);
    int k = 2;
    printf("倒数第%d节点值为%c\n", k, FindLastKNode(head,k)->element);
}
//判断是否带环
//钟表时针分针 速度不同,肯定会相遇
int hasCycle(linkNode* head)
{
    if(head == NULL)
        return -1;
    /*if(head->next = NULL)*/
        /*return 0;*/
    linkNode* fastNode = head;
    linkNode* slowNode = head;
    while(fastNode->next != NULL )
    {
        fastNode = (fastNode->next->next == NULL? fastNode->next: \
                    fastNode->next->next);
        slowNode = slowNode->next;
        if( slowNode == fastNode )
            return 1;
    }
    return 0;
}
void testHasCycle(linkNode* head)
{
    show;
    initLink(&head);
    linkListPushBack(&head,'b');
    linkListPushBack(&head,'c');
    linkListPushBack(&head,'d');
    linkListPushBack(&head,'e');
    linkListPushBack(&head,'f');
    linkListPushBack(&head,'g');
    circle(head);
    int result = hasCycle(head);
    printf("%d\n",result);
}
int main()
{
    testHasCycle(head);
    /*testLastKnode();*/
    /*testFindMidNode();*/
    /*testPushBack();*/
    /*linkListShow(head);*/
    /*bubbleup(head);*/
    /*linkListShow(head);*/
    /*tesetmerge(head,head2);*/
    /*testinitLink(&head);*/
    /*testPushBack(&head);*/
    /*circle(head);*/
    /*eat(head,5);*/
    return 0;
}
