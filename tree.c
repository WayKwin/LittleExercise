#include<stdio.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<dirent.h>

int print_tree(const char *str,int gap,char shp)
{
	struct stat sbuf;
	DIR * pdir = opendir(str);
	if(pdir == NULL) return ;
	struct dirent *pd =NULL;
	while((pd=readdir(pdir))!=NULL)
		{
			if(strcmp(pd->d_name,".")==0 || strcmp(pd->d_name,"..")==0) continue;
			int len=strlen(str)+2+strlen(pd->d_name);
			char*tmp=malloc(sizeof(len));
			memset(tmp,0x00,len);
			sprintf(tmp,"%s/%s",str,pd->d_name);
			lstat(tmp,&sbuf);
			int i=0;
			for(i=0;i<gap;i++)
			{
			printf("%c",shp);
			}
			char * p=strrchr(tmp,'/');
			if(p==NULL)
				{
					printf("%s\n",tmp);
				}else {
					printf("%s\n",p+1);
				}
				
			if(S_ISDIR(sbuf.st_mode)){
				print_tree(tmp,gap+4,shp);
			}
		}
}

int main(void)
{
	print_tree(".",0,'-');
}
