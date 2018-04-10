#include"comm.h"
static  int getSemId(int nums,int flags)
{
    key_t key = ftok(PATHNAME,PRO_J);
    if( key  < 0 )
    {
        perror("ftok");
        return -1;
    }
    int semid = semget(key,nums,flags);
    if( semid < 0  )
    {
        perror("semget");
        return -1;
    }
    return semid;
}
int createSemSet(int nums)
{
    return getSemId(nums,IPC_CREAT|IPC_EXCL|0666);
}
int getSemSet(int nums)
{
    return getSemId(nums,IPC_CREAT);
}
int initSem(int semid,int nums,int inintVal)
{
   union semun _un;
   _un.val = inintVal;
   if(semctl(semid,nums,SETVAL,_un) < 0)
   {
       perror("init Sem:semctl");
       return -1;
   }
    return 0;
}
int destorySemSet(int semid)
{
    if( semctl(semid, 0,IPC_RMID ) < 0 )
    {
        perror("semctl");
        return -1;
    }
    return 0;
}
int commPV(int semid,int who,int op)
{
    struct sembuf _buf;
    _buf.sem_num = who;
    _buf.sem_op = op;
    _buf.sem_flg = 0;
    if(semop(semid,&_buf, 1) < 0)
    {
        perror("semop");
        return -1;
    }
    return 0;
}
int P(int semid,int who)
{
    commPV(semid,who, -1);
}
int V(int semid,int who)
{
    commPV(semid,who, 1);
}
