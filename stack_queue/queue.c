#include"queue.h"
#include<stdlib.h>

static void IncreaseCapacity(SeqQueue* queue)
{
    if(queue == NULL)
        return;
    if( queue->size < queue->capacity )
        return;
    /*if( queue->head < queue->tail  )*/
    /*{*/

    /*}*/
    /*//满了的情况就是再次相遇*/
    /*if(queue->tail = queue->head)*/
    /*{*/

    /*}*/
    queue->capacity = queue->capacity*2+1;
    SeqQueueType* new_data = malloc(queue->capacity);
    int i ;
    int new_cur = 0;
    for(i = queue->head;i < queue->size; i ++)
    {
        new_data[new_cur++] = queue->data[i];
    }
    for(i = 0; i < queue->head; i++)
    {
        new_data[new_cur++] = queue->data[i];
    }
    SeqQueueType* to_delete = queue->data;
    queue->data = new_data;
    queue->head = 0;
    queue->tail = new_cur;
    free(to_delete);
    to_delete = NULL;
}
void SeqQueueInit(SeqQueue* queue)
{
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
    queue->capacity = 3;
    queue->data = (SeqQueueType*)malloc(queue->capacity*sizeof(SeqQueueType));
}
void SeqQueueDestroy(SeqQueue* queue)
{
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
    free(queue->data);
    queue->data = NULL;
}
void SeqQueuePush(SeqQueue* queue,SeqQueueType val)
{
    if( queue == NULL )
        return;
    if(queue->size >= queue->capacity)
    {
        IncreaseCapacity(queue);
    }
    //最后一个位置 c - 1
    if(queue->tail ==  queue->capacity -1 )
    {
        queue->data[queue->tail] = val;
        queue->tail = 0;
    }
    else
    {
        //tail和size一样 左封右开
        queue->data[queue->tail++] = val;
    }
    //当head和tail再次相与时 size 就满了
    queue->size++;
}
void SeqQueuePop(SeqQueue* queue)
{
    if( queue == NULL )
        return;
    if(queue->size == 0)
        return;
    if(queue->head == queue->capacity -1)
    {
        queue->head = 0;
    }
    else
    {
        queue->head++;
    }
    queue->size--;
}
void test()
{
    SeqQueue q;
    SeqQueueInit(&q);
    SeqQueuePush(&q,'a');
    SeqQueuePush(&q,'b');
    SeqQueuePush(&q,'c');

    printf("tail:exc: 0 act: %d,size:%d\n",q.tail,q.size);
    SeqQueuePop(&q);
    SeqQueuePush(&q,'d');
    printf("tail exp:1 act:%d,head exp: 1,act %d\n",q.tail,q.head);
    printf("now size:exc: 3  act:%d capacity: exc 7,act %d\n",q.size,q.capacity);
    SeqQueuePush(&q,'f');
    printf("tail exp:4  act:%d,head exp: 0,act %d\n",q.tail,q.head);
    printf("now size:exc: 4  act:%d capacity: exc 7,act %d\n",q.size,q.capacity);
}
void LinkQueueInit(LinkQueue* queue)
{
    if(queue == NULL)
        return;
    queue->head = (Node*) malloc(sizeof(Node));
    queue->tail =queue->head ;
    queue->tail->next = NULL;
}
void LinkQueueDestroy(LinkQueue* queue)
{
    while(queue->head->next)
    {
        Node* to_delete = queue->head;
        queue->head = queue->head->next;
        free(to_delete);
        to_delete = NULL;
    }
    //归位尾指针
    queue->tail = queue->head;
}
void LinkQueuePush(LinkQueue* queue,NodeType val)
{

    if(queue == NULL)
        return;
    Node* new_node = (Node*)malloc(sizeof(Node));
    if( new_node == NULL)
        return;
    new_node->data = val;
    new_node->next = NULL;
    //尾指针永远指向最后一个元素
    queue->tail->next = new_node;
    queue->tail = new_node;
}
void  LinkQueuePop(LinkQueue* queue)
{
    if( queue == NULL)
        return;
    if( queue->head->next == NULL )
        return;
    Node* to_delete = queue->head->next;
    queue->head->next = queue->head->next->next;
    free(to_delete);
    if(queue->head->next == NULL)
    {
        //删完队列 ,尾指针归位
        queue->tail = head;
    }
    to_delete = NULL;
}
void testLink()
{
    LinkQueue q;
    LinkQueueInit(&q);
    LinkQueuePush(&q,'a');
    LinkQueuePush(&q,'b');
    LinkQueuePush(&q,'c');
    Node* cur = q.head->next;
    while(cur)
    {
        printf("%c\n",cur->data);
        cur=cur->next;
    }
    LinkQueuePop(&q);
    printf("%c\n",q.head->next->data);
    LinkQueueDestroy(&q);
}
int main()
{

    testLink();
    return 0;
}
