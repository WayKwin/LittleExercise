#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<unistd.h>
#define PATHNAME "/tmp"
#define PRO_J  0X6666
union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
};
int createSemSet(int nsems);
int getSemSet(int nsems);
//类似 创建一个数组semid,数组个数nums,每个元素的值 initVal
//num 0 1 2 3....
int initSem(int semid,int nums,int initVal);
int P(int semid,int who);
int V(int semid,int who);
int destorySemSet(int semid);
