#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>
/*#define N 30*/
//fork
int main()
{
    pid_t pid[3];
    int u = 0;
    for(; i<3; i++)
    {
        if ( pid[i] == 0 )
        {
            printf (" im children  pid : %d,my father is %d \n",getpid(),getppid());
        }
        else if (pid[i] > 0)
        {
            printf ("im parent my id : %d,my child is %d\n",getpid(),pid[i]);
            sleep(3);
        }
    }
    /*int a = 100;*/
    /*pid_t pid = fork();*/
    /*if ( pid == 0  )*/
    /*{*/
     /*printf("children 1 doing something  id : %d parent id :%d \n",getpid(),getppid());*/
     /*a -= 10;*/
     /*printf("children do the minus ,result is :%d\n",a);*/
    /*}*/
    /*else if (pid > 0)*/
    /*{*/
    /*printf("im your Daddy id : %d  my Daddy is :%d\n",getpid(),getppid());*/
    /*a += 10;*/
    /*printf("parent do the add ,result is :%d\n",a);*/
    /*}*/
    return 0;
}
/*int main()*/
/*{*/
 /*pid_t pid_1 = fork();*/
 /*if (pid_1 == 0)*/
 /*{*/
     /*printf("children 1 doing something shitty id : %d partent id :%d \n",getpid(),getppid());*/
     /*sleep(3);*/
     /*exit(1);*/
 /*}*/
 /*//只有父进程才能走到这*/
 /*pid_t pid_2 = fork();*/
 /*if( pid_2 == 0 )*/
 /*{*/
     /*printf("children 2 doing something shitty id : %d partent id :%d \n",getpid(),getppid());*/
     /*sleep(3);*/
     /*exit(2);*/
 /*}*/
    /*int st1,st2;*/
    /*waitpid(pid_1,&st1,0);*/
    /*waitpid(pid_2,&st2,0);*/
    /*printf("in parent, child 1 pid = %d\n",pid_1);*/
    /*printf("in parent, child 2 pid = %d\n",pid_2);*/
    /*printf("in parent, parent pid = %d\n",getpid());*/
    /*printf("in parent, child 1 exit with= %d\n",st1);*/
    /*printf("in parent, child 2 exit with= %d\n",st2);*/
/*}*/
