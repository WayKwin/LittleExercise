#include"stack.h"
#include"queue.h"
SeqStack MinStack;
void initStack()
{
    SeqStackInit(&MinStack);
}
/*
 * o(1)取最小
 *入栈一对元素(value,min)
 *注意入栈顺序
 * untest
 */
void PushMinStack(SeqStack *stack,SeqStackType val)
{
    SeqStackType min;
    if(stack == NULL)
        return;
    if(stack->size == 0)
    {
        min = val;
    }
    SeqStackTop(stack, &min);
    min = min < val ? min : val;
    SeqStackPush(stack,val);
    SeqStackPush(stack,min);
}
void PopMinStack(SeqStack* stack,SeqStackType* MinRet,SeqStackType* PopRet)
{
    if(stack == NULL)
        return;
    if(stack->size == 0 )
        return;
    SeqStackPop(stack,MinRet);
    SeqStackPop(stack,PopRet);

}
/*====================================*/
/*
 * 两个栈实现一个队列
 * input output  入栈 out->in push in
 * 出栈 in->out pop out
 * untest
 */
typedef struct QueueBy2Stack
{
    SeqStack input;
    SeqStack output;
}QueueBy2Stack;
void QueueBy2StackInit(QueueBy2Stack* q)
{
    SeqStackInit(&q->input);
    SeqStackInit(&q->output);
}
void QueueBy2StackPush(QueueBy2Stack* q,SeqStackType val)
{
    SeqStackType top;
    while(q->output.size)
    {
        SeqStackPop(&q->output,&top);
        SeqStackPush(&q->input,top);
    }
        SeqStackPush(&q->input,val);
}
void QueueBy2StackPop(QueueBy2Stack* q,SeqStackType* ret)
{
    SeqStackType top;
    while(q->input.size)
    {
        SeqStackPop(&q->input,&top);
        SeqStackPush(&q->output,top);
    }
        SeqStackPop(&q->output,ret);
}
void testQueueBy2Stack()
{
    QueueBy2Stack q;
    QueueBy2StackInit(&q);
    QueueBy2StackPush(&q,'a');
    QueueBy2StackPush(&q,'b');
    QueueBy2StackPush(&q,'c');
    SeqStackType ret;
    QueueBy2StackPop(&q,&ret);
    printf("excpted a, actual: %c\n",ret);
    QueueBy2StackPop(&q,&ret);
    printf("excpted b, actual: %c\n",ret);
    QueueBy2StackPop(&q,&ret);
    printf("excpted c, actual: %c\n",ret);
}


/*=====================================
 * 两个队列实现栈
 *  pop -> 把有元素的队列从head一次进入第二个队列
 *  直到head == tail ,把第一个队列元素出队列
 *  push-> 加入到非空队列
*/
/*=============================================*/
typedef struct StackBy2Queue
{
    SeqQueue q1;
    SeqQueue q2;
}StackBy2Queue;
void StackBy2QueueInit(StackBy2Queue* s)
{
    SeqQueueInit(&s->q1);
    SeqQueueInit(&s->q2);
}
void StackBy2QueuePush(StackBy2Queue* s,SeqQueueType val)
{
    SeqQueue* Push_Queue = s->q1.size  != 0 ? &s->q1 : &s->q2;
    SeqQueuePush(Push_Queue, val);
}
void StackBy2QueuePop(StackBy2Queue* s,SeqQueueType* ret)
{
    SeqQueue* from;
    SeqQueue* to;
    if(s->q1.size == 0)
    {
        from = &s->q2;
        to = &s->q1;
    }
    if(s->q1.size != 0)
    {
        from = &s->q1;
        to = &s->q2;
    }
    //留下一个等待被pop的yuansu
    while(from->size != 1)
    {
         SeqQueuePop(from,ret);
         SeqQueuePush(to,*ret);
    }
    SeqQueuePop(from,ret);
}
void testStackBy2QueuePop()
{
    StackBy2Queue s;
    StackBy2QueueInit(&s);
    StackBy2QueuePush(&s,'a');
    StackBy2QueuePush(&s,'b');
    StackBy2QueuePush(&s,'c');
    SeqQueueType ret;
    StackBy2QueuePop(&s,&ret);
    printf("excpted : c ,actual: %c\n",ret);
    StackBy2QueuePop(&s,&ret);
    printf("excpted : b ,actual: %c\n",ret);
    StackBy2QueuePop(&s,&ret);
    printf("excpted : a ,actual: %c\n",ret);
}
/*==============================*/
/*
 * 字符串变换入栈合法性 bcd cdb非法  bcd  dcd 合法
 * 只要不相同的部位是局部逆序的 就是合法的 比如 a bc def
 *                                              a cb dfe
 *
 *    思路:   循环: 在不同元素处一直入栈知道碰到相同元素
 * :           在相同的字符开始循环出栈 双重循环结束后能把栈出空 而且dst 指向末尾 表明可以
 *
 */
int StackOrder(char src[],size_t src_size,char dst[],size_t dst_size)
{
    if(src == NULL || dst == NULL || src_size == 0 || dst_size == 0)
    {
        return -1;
    }
    SeqStack stack;
    SeqStackType ret;
    SeqStackInit(&stack);
    size_t src_index = 0;
    size_t dst_index = 0;
    for(;src_index < src_size; src_index++)
    {
        SeqStackPush(&stack,src[src_index]);
        SeqStackTop(&stack,&ret);
       while ( ret == dst[dst_index])
        {
                dst_index++;
                SeqStackPop(&stack,NULL);
                SeqStackTop(&stack,&ret);
        }
    }
    //注意有相同的元素 dst_index就++   abcd四个相同 那么就是4 所以和size相等 不是size-1

    if(stack.size == 0 && dst_index == dst_size )
    {
        return 1;
    }
    return 0;

}
#include<string.h>
int main()
{
    char* src = "abcd";
    char* dst = "dcba";
    int src_size = strlen(src);
    int dst_size= strlen(dst);
    printf("%d\n",StackOrder(src,src_size,dst,dst_size));
    /*testStackBy2QueuePop();*/
    /*testQueueBy2Stack();*/
    return 0 ;
}
/* ===========================================*/






















