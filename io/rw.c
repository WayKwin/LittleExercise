#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
int main()
{
    //调用fork(),fork()会继承父进程的环境变量
   /*int  i =  system("e $SHIT");*/
   /*printf("system returns : %d\n",i);*/
    char buf[64];
    FILE* fp = popen("mkdir ./demo","r");
    if(fp == NULL)
    {
        return 1;
    }
    /*int r;*/
    /*while( r = fread(buf,1,64,fp) )*/
    /*{*/
        /*printf("buf = %s ",buf);*/
       /*if( r < 64);*/
       /*break;*/
    /*}*/
    /*pclose(fp);*/
    return 0;
}
