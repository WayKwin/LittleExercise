#include"comm.h"
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#define sleep_time 3
int semid;
void wait_for_right_fork_bug(int No)
{
    int right_fork = (No + 1) % 5;
    //bug 这里取两只筷子不是原子操作
    P(semid,right_fork);
}
void wait_for_left_fork_bug(int No)
{
    int left_fork = (No + 1) % 5;
    //bug 这里取两只筷子不是原子操作
    P(semid,left_fork);
}
void free_forleft_forks_bug(int No)
{
    int left_fork = No;
    //bug 这里不是原子操作
    V(semid,left_fork);
}
void free_for_right_forks_bug(int No)
{
    int right_fork = No;
    //bug 这里不是原子操作
    V(semid,right_fork);
}
//同时拿起两只叉子
void wait_for2forks(int No)
{
    int left_fork = No;
    int right_fork = (No + 1) % 5;
    struct sembuf buf[2] ={ {left_fork, -1, 0},{right_fork, -1, 0} };
    //信号数为2 ,同时取两个叉子
    semop(semid, buf, 2);
}
//同时放下两个叉子
void free_2forks(int No)
{
    int left_fork = No;
    int right_fork = (No + 1) % 5;
    struct sembuf buf[2] ={ {left_fork, 1, 0},{right_fork, 1, 0} };
    semop(semid, buf, 2);
}
void philosopher(int No)
{

    while(1)
    {
        printf(" name: %d ,i'm thinking now !!\n",No);
        sleep(sleep_time);
        printf("i'm hungry!!!\n");
        wait_for2forks(No);
        printf("find 2 forks i'm eating now\n");
        sleep(sleep_time);
        free_2forks(No);
        printf("i'm over,keep thinking\n");
        sleep(sleep_time);
    }
}

void philosopher_bug(int No)
{

    while(1)
    {
        printf(" name: %d ,i'm thinking now !!\n",No);
        sleep(sleep_time);
        printf("name: %d i'm hungry!!!\n",No);
        wait_for_left_fork_bug(No);
        sleep(3);
        wait_for_right_fork_bug(No);
        printf("find 2 forks i'm eating now\n");
        sleep(sleep_time);
        free_forleft_forks_bug(No);
        free_for_right_forks_bug(No);
        printf("i'm over,keep thinking\n");
        sleep(sleep_time);
    }
}

int main()
{
    int i;
    int No = 0;
    //五个叉子,五个信号量
     semid = createSemSet(5);
    //
    for(i = 0; i < 5; i++)
    {
        //每个信号量是二元信号量
        //取值1,0
        initSem(semid,i,1);
    }

    for(i = 1; i < 5; i++)
    {
        pid_t pid = fork();
        if( pid < 0 )
        {
            perror("fork:");
            return -1;
        }
        if( pid == 0 )
        {
            No = i;
            break;
        }
    }
#ifdef buf_version
    philosopher_bug(No);
#else
    philosopher(No);
#endif

}
