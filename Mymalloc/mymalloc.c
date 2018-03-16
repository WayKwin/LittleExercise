#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
// sizeof 结果是24 似乎不需要手动记录
#define BLOCK_SIZE 32
typedef struct s_block *t_block;
t_block first_block = NULL;
//弱智版
void *malloc_t(size_t size)
{
    void *p = sbrk(0);
    if(sbrk(size) == (void *)-1)
    {
        return NULL;
    }
    return p;
}
// meta-data 记录的记录信息
struct s_block
{
    //size 是可利用空间 ,就是除过结构体大小剩余的空间
    size_t size;
    //指向下一个结构体
    t_block next;
    //指向上一个结构体
    t_block before;
    //是否可用
    int free;
    //填充 不填充 结构体大小是20,不是8的整数倍
    int padding;
    char data[]; //柔性数组,表示结构体后第一个数据开始处
};
// 找到第一个可以开辟的block
// last 是记录b为空的话,最后一个不为空的结点
t_block find_block(t_block *last, size_t size)
{
    t_block b = first_block;
    *last = b;
    while(b && !(b->size>=size && b->free))
    {
        //记录此结点
        *last = b;
        b = b->next;
    }
    return b;
}
t_block extend_heap(t_block last,size_t s)
{
    t_block b;
    b = sbrk(0);
    if(sbrk(BLOCK_SIZE + s) == (void *)-1)
    {
        return NULL;
    }
    b->next=NULL;
    b->size = s;
    b->before=NULL;
    /*b->next = NULL;*/
    b->free = 1;
    if(last)
    {
        b->before=last;
        last->next=b;

    }
       return b;
}
//分裂块 提高利用率,每次都进行malloc 不需要考虑,但是一旦free了某个数据区
//下次在用数据区长度可能远小于原来的数据去,造成内存浪费
void split_block(t_block b,size_t used_size)
{
   t_block new;
   //注意要强转类型
   new=(t_block) b->data+used_size;//不对称边界
   new->size=b->size - used_size - BLOCK_SIZE;
   new->free = 1;
   new->next = b->next;
   new->before=b;
   if(b->next != NULL)
   {
    b->next->before=new;
   }
   b->next=new;
}

size_t align8(size_t size)
{
    //低三位全为0 就是8的倍数,右移三位不影响
    if(size & 0x7 == 0)
        return size;
    //    +1保证至少比原来的数大八
    return (((size >> 3)+1) << 3);
}

void* mymalloc(size_t size )
{
    /*size = align8(size);*/
    if(first_block)
    {
       t_block b = first_block;
        t_block last = first_block;
        b=find_block(&last,size);
        if (b == NULL)
            {
                b = extend_heap(last,size);
            }
        //从前往后找到的数据区可能远大于 本次使用的数据 free的结果
        if((b->size - size)>=BLOCK_SIZE+8)
        {
            split_block(b,size);
        }
       b->free=0;
    if(b == NULL)
    {
        return NULL;
    }
    return b->data;
    }
    else
    {
        first_block = extend_heap(NULL,size);
        first_block->free=0;
        return first_block->data;
    }
   }
t_block get_block(void * p)
{
   t_block tmp =(t_block)((char *)p-BLOCK_SIZE);

   return tmp;
}
int valid_addr(void *p)
{
    if(first_block)
    {
    if(p>(void *)first_block && p<(void *)sbrk(0))
    {
        return p==(void *)(get_block(p)->data);
    }
    return 0;
    }
    return 0;
}
t_block fusion(t_block p)
{
    if(p->next && p->next->free)
    {
        p->size+=p->next->size+BLOCK_SIZE;
        p->next=p->next->next;
        if(p->next)
        {
           p->next->before=p;
        }
    }
    return p;
}
void myfree(void *p)
{
    if(valid_addr(p))
    {
        t_block tmp =get_block(p);
        tmp ->free=1;
        if(tmp->before && tmp->before->free )
        {
            //往前合并需要将tmp指向它的前驱
           tmp = fusion(tmp->before);
        }
        if(tmp->next)
        {
        //后继不空闲就什么事也不错
            fusion(tmp);
        }
        //末节点可以释放
        else
        {
            /*if(tmp->before)*/
            /*{*/
            //释放末节点
            sbrk(-(BLOCK_SIZE+tmp->size));
            tmp=NULL;
            //不合理
                /*tmp->before->before=NULL;*/
            /*}*/
            /*else*/
            /*{*/
            /*//只有当前驱和后继都为0的情况*/
             /*first_block=NULL;*/
            /*// 如果tmp是最后一个结点,就回滚这个节点*/
            /*brk(tmp);*/
            /*}*/
        }
    }
}

int main()
{
    void* p1;
    void* p2;
    printf("heap的起始地址为%p\n",p1=sbrk(0));
    int *p=(int *)mymalloc(sizeof(int)*4);
    char *c=(char * )mymalloc(sizeof(char)*8);
    myfree(p);
    /*myfree(c);*/

    printf("目前sbrk指针指向%p\n",p2=sbrk(0));
    printf("在heap上开辟了%d字节的空间,其中保存内存信息的链表头大小为%d\n",p2-p1,sizeof(struct s_block ));
    /*if(c == NULL)*/
    /*{*/
        /*printf("错误\n");*/
        /*return 0;*/
    /*}*/
    /*if(p == NULL)*/
    /*{*/
        /*printf("错误\n");*/
        /*return 0;*/
    /*}*/
    /*int i=0;*/
    /*for(;i<4;i++)*/
    /*{*/
        /*p[i]=i;*/
        /*printf("%d\n",p[i]);*/
    /*}*/
    /*c="abc";*/
    /*printf("%s\n",c);*/
    /*[>printf("size_t -> %d\n",sizeof(size_t));<]*/
    /*printf("t_block-> %d\n",sizeof(size_t));*/
    /*printf("int -> %d\n",sizeof(int));*/
    /*printf("s_block -> %d\n",sizeof(struct s_block));*/
    /*printf("int * %d\n",sizeof(int *));*/

    /*[>int *p1 = sbrk(0);<]*/
    /*printf("%p\n",p1);*/
    /*int *p2 = malloc(sizeof(int)*4);*/
    /*int *p3 = sbrk(0);*/
    /*printf("%p\n",p3);*/
    /*free(p2);*/
   /*int *p4 = sbrk(0);*/
    /*printf("%p\n",p4);*/
    /*printf("%p\n",p3-p1);*/
    return 0;
}
