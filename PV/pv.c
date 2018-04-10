#include"comm.h"
int main()
{
    int semid = createSemSet(1);
    initSem(semid,0,1);
    pid_t pid = fork();
    if( pid < 0 )
    {
        perror("error");
        return -1;
    }
    if( pid == 0 )
    {
        int _semid = getSemSet(0);
        while(1)
        {
            //对_semid数组0号下标的信号量进行P操作
            P(_semid,0);
            printf("A ");
            fflush(stdout);
            //sleep会导致争用资源
            sleep(1);
            printf("A ");

            fflush(stdout);
            V(_semid,0);
        }
    }
    if( pid >  0)
    {
        while(1)
        {
            P(semid,0);
            printf("B ");
            fflush(stdout);
            sleep(1);
            printf("B ");
            fflush(stdout);
            V(semid,0);
        }
        wait(NULL);

    }
    destorySemSet(semid);
    return 0;
}
