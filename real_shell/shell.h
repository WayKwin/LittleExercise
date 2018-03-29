#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <pwd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#define MAX_PROMPT 1024
#define MAXLINE 4096
#define MAXARG 20
//获取 [@] 主机名和用户名
struct passwd *pwd;
//拼接头部
char promopt[256];
//输入型参数
void  type_prompt(char* prompt);
int read_command(char* command[], char*parameters[], char *prompt);
//存入用户输入的指令
char * buf;

