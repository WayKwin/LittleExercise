#include"stack.h"
#include<stdlib.h>
static int  IncreaseCapacity(SeqStack* stack)
{
    if(stack == NULL)
        return 0;
    if(stack->size < stack->capacity)
        return 0;
    stack->capacity = stack->capacity*2 + 1;
    SeqStackType* new_data = (SeqStackType*)malloc(stack->capacity*sizeof(SeqStackType));
    if( new_data == NULL )
        return 0;
    int i = 0;
    for(; i < stack->size; i++)
    {
        new_data[i] = stack->data[i];
    }
    free(stack->data);
    stack->data = new_data;
    return 1;
}
void  SeqStackInit(SeqStack* stack)
{
    if(stack == NULL)
        return ;
    stack->size = 0;
    stack->capacity = 1000;
    stack->data = (SeqStackType*)malloc(stack->capacity*sizeof(SeqStackType));
}
void SeqStackDestroy(SeqStack* stack)
{
    if( stack == NULL )
    {
        return;
    }
    if(stack->data == NULL)
        return;
    free(stack->data);
    stack->data = NULL;
    stack->size = 0;
}
void SeqStackPush(SeqStack* stack,SeqStackType val)
{
    if(stack == NULL)
        return;
    if(stack->size >= stack->capacity)
    {
       if( IncreaseCapacity(stack) == 0 );
       return;
    }
    stack->data[stack->size++] = val;
}
void SeqStackPop(SeqStack* stack,SeqStackType* ret)
{
    if( stack == NULL )
        return;
    if(stack->size == 0 )
        return;
    *ret = stack->data[--stack->size];
}
int SeqStackTop(SeqStack* stack,SeqStackType* value)
{
    if(stack == NULL || value == NULL)
        return 0;
    if( stack->size == 0 )
        return 0;
    *value = stack->data[stack->size - 1];
    return 1;
}
void LinkStackInit(LinkStack** stack)
{

}
void LinkStackDestroy(LinkStack** stack)
{
    if(stack == NULL)
        return;
    if(*stack == NULL)
        return;
    while(*stack)
    {
        LinkStack* to_delete = *stack;
        *stack = (*stack)->next;
        free(to_delete);
        to_delete = NULL;
    }
}
void LinkStackPush(LinkStack** stack, LinkStackType val)
{
    if(stack == NULL)
        return;
    LinkStack* new_node = (LinkStack*)malloc(sizeof(LinkStack));
    new_node->data = val;
    new_node->next = *stack;
    *stack = new_node;
}
void LinkStackPop(LinkStack** stack)
{
    if(stack == NULL)
        return;
    if(*stack == NULL)
        return;
    LinkStack* to_pop = *stack;
    *stack = (*stack)->next;
    free(to_pop);
    to_pop = NULL;
}

int main()
{
    LinkStack* frist = NULL;
    LinkStackPush(&frist,'a');
}
