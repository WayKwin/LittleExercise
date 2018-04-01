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
//指针 绝对速度相同的话不行
linkNode*  hasCycle(linkNode* head)
{
    if(head == NULL)
        return NULL;
    /*if(head->next = NULL)*/
        /*return 0;*/
    linkNode* fastNode = head;
    linkNode* slowNode = head;
    while(fastNode->next != NULL && fastNode->next->next !=NULL)
    {
        fastNode = fastNode->next->next;
        slowNode = slowNode->next;
        if( slowNode == fastNode )
            return slowNode;
    }
    return NULL;
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
    linkNode* result = hasCycle(head);
    printf("%p\n",result);
}
//判断带环入口点
// x 头到入口点
// y  入口点到相遇点
// s = x + y
// 2s = x + nr(1. slow未到环 fast 进环走了N圈 2 slow到环 fast多走了N圈之后slow相与) + y;
// x = nr - y
// p1 走x  = p2 走 nr圈(回到原地) 再往后退Y步 就是环的入口点
linkNode* findEntry(linkNode* head)
{
    linkNode* encounter = hasCycle(head);
    linkNode* p1 = head;
    while(encounter != p1)
    {
        p1 = p1->next;
        encounter = encounter->next;
    }
    return p1;
}
void test_findEntry()
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
    linkNode* result = findEntry(head);
    printf("expected a ,actual:%c\n",result->element);
}
int  CircleLength(linkNode* head)
{

    int len = 1;
    linkNode* encounter = hasCycle(head);
    if( encounter == NULL )
    {
        return 0;
    }
    else
    {
        // 注意 len不能定义x中
        while(encounter->next != encounter)
        {
            encounter = encounter->next;
            ++len;
        }
        ++len;
        return len;
    }
}
//求交点
int hasCross_noncycle(linkNode* head1, linkNode* head2)
{
    if( head1 == NULL || head2 == NULL)
        return 0;
    linkNode* p1 = head1;
    linkNode* p2 = head2;
    //相交 y子形状 走到尾一样 结果一样就相交
    while(p1->next!= NULL || p2->next != NULL)
    {
        if(p1->next != NULL)
        p1 = p1->next;
        if( p2->next != NULL )
        p2 = p2->next;
    }
    if( p1 == p2 )
        return 1;
    return 0;
}
//求相交交点
//求出offset
//长的先走offset
//相遇就是交点
/*
 * tested
 */
linkNode* getCrossPoint_noncycle(linkNode* head1,linkNode* head2)
{
    if( head1 == NULL || head2 == NULL )
        return NULL;
    if(!hasCross_noncycle(head1,head2))
        return NULL;
      int len1=1;
      int len2=1;
      int offset = 0;
      linkNode* cur1 = head1;
      linkNode* cur2 = head2;

      while(cur1 != NULL)
      {
          len1++;
          cur1 = cur1->next;
      }
      while(cur2 != NULL)
      {
          len2++;
          cur2 = cur2->next;
      }
      offset = (len1 > len2)?len1 - len2 : len2 - len1;
      cur1 = (len1>len2)? head1:head2;
      while(offset--)
          cur1 = cur1->next;
      cur2 = (len1 > len2)? head2:head1;
      while(cur1 != cur2)
      {
          if(cur1 == NULL || cur2 == NULL)
              return NULL;
          cur1 = cur1->next;
          cur2 = cur2->next;
      }
      return cur1;

}
void test_getCrossPoint_noncycle()
{
    show;
    linkNode a;
    linkNode b;
    linkNode c;
    linkNode d;
    linkNode e;
    //
    a.element = 'a';
    b.element = 'b';
    c.element = 'c';
    d.element = 'd';
    e.element = 'e';
    //交点在b   a和e 交于b点
    a.next =& b;
    b.next = &c;
    c.next = &d;
    d.next = NULL;
    e.next = &b;
    linkNode* result =  getCrossPoint_noncycle(&a,&e);
    printf("expected : b  actual : %c\n",result->element );
}
/****************************************************************/
//相交(可能带环)
//1.两个链表一个带环 一个不带环 (不想交)
//(相交必带环)两个链表都带环
//交点在环外.环上
//如果两个环入口点相同
// 两个环的入口点  从一个入口点能走到另一个入口点  (入口点在环上)
//入口点一样 交点在环外
// 入口点不一样 排除上列情况 不想交
int hasCross(linkNode* head1,linkNode* head2)
{
    if( head1 == NULL || head2 ==NULL )
        return 0;

    //带环不带换 不想交
#ifdef __DEBUG__
    printf("head 1的相遇点%c\n",hasCycle(head1)->element);
    printf("head 2的相遇点%c\n",hasCycle(head2)->element);
    printf("head 1的入口点%c\n",findEntry(head1)->element);
    printf("head 2的入口点%c\n",findEntry(head2)->element);
#endif
    if ((hasCycle(head1) ==NULL  && hasCycle(head2) != NULL) || (hasCycle(head1) != NULL && hasCycle(head2) == NULL))
        return 0;
    //都不带环
   if(!hasCycle(head1) && !hasCycle(head2))
        return hasCross_noncycle(head1,head2);
    //交点在圆上
    linkNode* Entry1 = findEntry(head1);
    linkNode* Entry2 = findEntry(head2);
#ifdef __DEBUG__
    printf("Entry1 :%c\n",Entry1->element);
    printf("Entry2 :%c\n",Entry2->element);
#endif
    Entry1 = Entry1->next;
    while(Entry1 != Entry1)
    {
        if(Entry2 == Entry1)
            return 1;
        Entry1 = Entry1->next;
    }
    // 交点在线上
    linkNode* cur1 = head1;
    linkNode* cur2 = head2;
    Entry1 = findEntry(head1);
    Entry2 = findEntry(head2);
    while(cur1 !=Entry1)
        cur1 = cur1->next;
    while(cur2 != Entry1)
        cur2 = cur2->next;
    if( cur1 == cur2 )
        return 1;
    //不相交在环上也不相交在线上,不相交
    return 0;
}
void test_hasCross()
{
    show;
    linkNode a;
    linkNode b;
    linkNode c;
    linkNode d;
    linkNode e;
    linkNode A;
    linkNode B;
    //
    a.element = 'a';
    b.element = 'b';
    c.element = 'c';
    d.element = 'd';
    e.element = 'e';
    A.element = 'A';
    B.element = 'B';
    //交点在c   b和e 交于c点
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &c;
    //第二条链表交于第一条的b点(环上)
    A.next = &B;
    B.next = &b;
    printf("%d\n",hasCross(&a,&A));
}

/****************************************************************/
//交点(可能不带换)
// 环上 两个入口点
// 环外 把入口点当NULL 计算offset
/*
 * untest
 */
linkNode* getCrossPoint(linkNode* head1,linkNode* head2)
{
    if(!hasCross(head1,head2))
        return NULL;
    //都不带环
    if(!hasCycle(head1) && !hasCycle(head2))
        return getCrossPoint_noncycle(head1,head2);
    //都带环,在环上 ,那么两个交点就是入口点,可以返回较短或者较长的交点(入口点),
    linkNode* Entry1 = findEntry(head1);
    linkNode* Entry2 = findEntry(head2);
    Entry1 = Entry1->next;
    while(Entry1 != Entry1)
    {
        if(Entry2 == Entry1)
            return Entry2;
        Entry1 = Entry1->next;
    }
    //交点在线上
    //不用初始化Entry1
    /*Entry1 = findEntry(head1);*/
    int len1 = 1;
    int len2 = 1;
    int offset;
    linkNode* cur1 = head1;
    linkNode* cur2 = head2;
    while(cur1 != Entry1)
    {
        len1++;
        cur1 = cur1->next;
    }
    while(cur2 != Entry1)
    {
        len2++;
        cur2 = cur2->next;
    }
    offset = (len1 > len2)?len1 - len2 : len2 - len1;
    cur1 = (len1>len2)? head1:head2;
    while(offset--)
        cur1 = cur1->next;
    cur2 = (len1 > len2)? head2:head1;
    while(cur1 != cur2)
    {
         cur1 = cur1->next;
         cur2 = cur2->next;
    }
    return cur1;
}
/*
 * unfinised
 */
void test_getCrossPoint()
{
    show;
    linkNode a;
    linkNode b;
    linkNode c;
    linkNode d;
    linkNode e;
    linkNode A;
    linkNode B;
    //
    a.element = 'a';
    b.element = 'b';
    c.element = 'c';
    d.element = 'd';
    e.element = 'e';
    A.element = 'A';
    B.element = 'B';
    //交点在c   b和e 交于c点
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &c;
    //第二条链表交于第一条的b点(环上)
    A.next = &B;
    B.next = &b;
    linkNode* result = getCrossPoint(&a,&A);
    printf("expected : b actual :%c\n",result->element);
}

/****************************************************************/
/*链表交集( 有序链表 )思路和 归并一样
 * untested
 */
linkNode* unionLinkList(linkNode* head1, linkNode* head2)
{
    if( head1 ==NULL || head2 == NULL )
        return NULL;
    linkNode* newHead = (linkNode*)malloc(sizeof(linkNode));
    linkNode* new_node = newHead;
    linkNode* cur1 = head1;
    linkNode* cur2 = head2;
    while(cur1&&cur2)
    {
        if(cur1->element < cur2->element)
            cur1 = cur1->next;
        else if(cur1->element == cur2->element)
        {
            //内存泄漏?
            new_node->element = cur1->element;
            new_node->next = (linkNode*)malloc(sizeof(linkNode));
            new_node = new_node->next;
            cur1 = cur1->next;
        }
        else
        cur2 = cur2->next;
    }
//    退出循环 new_node 指向最后开辟的内存未使用
    free(new_node);
    new_node = NULL;
    return newHead;
}
void test_unionLinkList()
{
    show;
    linkNode a;
    linkNode b;
    linkNode c;
    linkNode d;
    linkNode e;
    linkNode A;
    linkNode B;
    //
    a.element = '1';
    b.element = '3';
    c.element = '4';
    d.element = '6';
    e.element = '7';
    A.element = '2';
    B.element = '3';
    //交点在c   b和e 交于c点
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = NULL;
    //第二条链表交于第一条的b点(环上)
    A.next = &B;
    B.next = NULL;
    linkNode* result = unionLinkList(&a,&A);
    while(result)
    {
        printf("%c ",result->element);
        result = result->next;
    }

}
/****************************************************************/
/*复杂链表的复制
 *1 先按照简单链表方式复制
 * diff函数
 *2 遍历旧链表,找到每个链表节点random指针相对于链表头部的偏移量
 *  step
 *3 遍历新链表,根据偏移量,设置新链表的random指针
 * 2和3 在一个
 */
typedef struct complexNode{
    eleType element;
    struct complexNode* next;
    struct complexNode* random;
}complexNode;
complexNode* initComplexNode()
{
    complexNode* node1 = (complexNode*)malloc(sizeof(complexNode));
    complexNode* node2 = (complexNode*)malloc(sizeof(complexNode));
    complexNode* node3 = (complexNode*)malloc(sizeof(complexNode));
    complexNode* node4 = (complexNode*)malloc(sizeof(complexNode));
    node1->element = '1';
    node2->element = '2';
    node3->element = '3';
    node4->element = '4';
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;
    node1->random = node4;
    node2->random = NULL;
    node3->random = node1;
    node4->random = node1;
    return node1;
}
complexNode* copyNode(complexNode* head)
{
    if( head == NULL )
        return NULL;
    //newHead指针必须先初始化
    complexNode* newHead = (complexNode*)malloc(sizeof(complexNode));
    complexNode* new_node = newHead;
    complexNode* head_pos = head;
    for(; head->next != NULL ; head = head->next)
    {
        new_node->element = head->element;
        new_node->next = (complexNode*)malloc(sizeof(complexNode));
        new_node = new_node->next;
        /*printf("[%c|%p]",new_node->element);*/
    }
    new_node->element = head->element;
    new_node->next = NULL;
    /*free(new_node);*/
    /*new_node = NULL;*/
    /*printf("新节点\n");*/
    /*for(;newHead != NULL;newHead = newHead->next)*/
    /*{*/
        /*printf("[%c|%p]   ",newHead->element,newHead);*/
    /*}*/
    /*printf("\n");*/
    /*return newHead;*/
    complexNode* start_new = newHead;
    complexNode* start_head = head_pos;
    complexNode* start_for = newHead;
    for(;start_for != NULL;start_for =start_for->next,head_pos = head_pos->next )
    {
        int step = 0;
        complexNode* cur = start_head;
        complexNode* cur2 = start_new;
        while(cur != head_pos->random)
        {
            cur = cur->next;
            step++;
        }
        if(cur == NULL)
        {
            new_node->random = NULL;
        //有else 可以省略
        /*continue;*/
        }
        else
        {
            while(step--)
            {
                cur2 = cur2->next;
            }
            start_for->random = cur2;
        }
    }
   return newHead;
}
void test_copyNode()
{
     complexNode* oldHead = initComplexNode();
     complexNode* newHead = copyNode(oldHead);
     while(oldHead)
     {
         if( !oldHead->random )
         {
             printf("NULL ");
             oldHead = oldHead->next;
             continue;
         }
         printf("%c ",oldHead->random->element);
         oldHead = oldHead->next;
     }
     printf("\n");
     while(newHead)
     {
         if( !newHead->random )
         {
             printf("NULL ");
             newHead = newHead->next;
             continue;
         }
         printf("%c ",newHead->random->element);
         newHead = newHead->next;
     }
}
complexNode* copyNode_version2(complexNode* head)
{
    complexNode* cur_head = head;
    complexNode* new_node;
    //复制节点
    while(cur_head != NULL)
    {
        new_node = (complexNode*)malloc(sizeof(complexNode));
        new_node->element = cur_head->element;
        new_node->next = cur_head->next;
        cur_head->next = new_node;
        //记得把指针往后移动俩格
        cur_head = cur_head->next->next;
    }
    //恢复指针
    cur_head = head;
    //复制过来是双数的
    for( ; cur_head != NULL; cur_head = cur_head->next->next)
    {
        if(cur_head->random == NULL)
        {
            cur_head->next->random = NULL;
            continue;
        }
        cur_head->next->random = cur_head->random->next;
    }
    cur_head = head;
    complexNode* newhead = cur_head->next;
    complexNode* cur_newhead = newhead;
    //分离链表
    //1 0 1 0 1 0
    //一个走一步一个走两步
    while(cur_head->next->next != NULL)
    {
        //  先设置next
        cur_head->next = cur_head->next->next;
        //指针指向next
        cur_head = cur_head->next;
        cur_newhead->next = cur_head->next;
        cur_newhead = cur_newhead->next;
    }
    //尾节点next是null
    //
    cur_head->next = NULL;
    cur_newhead->next = NULL;
    return newhead;
}
void test_copyNode_version2()
{
     complexNode* oldHead = initComplexNode();
     complexNode* newHead = copyNode_version2(oldHead);
     while(oldHead)
     {
         if( !oldHead->random )
         {
             printf("NULL ");
             oldHead = oldHead->next;
             continue;
         }
         printf("[%c|%p] ",oldHead->random->element,oldHead->random);
         oldHead = oldHead->next;
     }
     printf("\n");
     while(newHead)
     {
         if( !newHead->random )
         {
             printf("NULL ");
             newHead = newHead->next;
             continue;
         }
         printf("[%c|%p] ",newHead->random->element,newHead->random);
         newHead = newHead->next;
     }
}
/* new_node random = cur -> random->next
 * 1 1 2 2 3 3 4 4
 *
 */

/****************************************************************/
int main()
{
    /*test_unionLinkList();*/
    /*test_copyNode();*/
    /*test_getCrossPoint_noncirle();*/
    test_copyNode_version2();
    /*test_hasCross();*/
    /*test_getCrossPoint();*/
    /*test_findEntry();*/
    /*testHasCycle(head);*/
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

