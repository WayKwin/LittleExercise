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
    SeqStack* input;
    SeqStack* output;
}QueueBy2Stack;
void QueueBy2StackInit(QueueBy2Stack* q)
{
    SeqStackInit(q->input);
    SeqStackInit(q->output);
}
void QueueBy2StackPush(QueueBy2Stack* q,SeqStackType val)
{
    SeqStackType top;
    while(q->output->size)
    {
        SeqStackPop(q->output,&top);
        SeqStackPush(q->input,top);
    }
        SeqStackPush(q->input,val);
}
void QueueBy2StackPop(QueueBy2Stack* q,SeqStackType* ret)
{
    SeqStackType top;
    while(q->input->size)
    {
        SeqStackPop(q->input,&top);
        SeqStackPush(q->output,top);
    }
        SeqStackPop(q->output,ret);
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
    SeqQueue* q1;
    SeqQueue* q2;
}StackBy2Queue;
void StackBy2QueueInit(StackBy2Queue* s)
{
    SeqQueueInit(s->q1);
    SeqQueueInit(s->q2);
}























