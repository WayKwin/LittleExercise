/*
 * 实现  复制
 *		 文件->文件
 *       目录-> 目录
 *       文件->目录
 *       释放开辟的内存
 *  未实现
 *		复制目录的时候 没有考虑相同目录,文件略过问题
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
void copy_file(const char*src,const char*dst,mode_t st_mode)
{
	umask(0);
	chmod(dst,st_mode);
	FILE * f_src=fopen(src,"r");
	FILE * f_dst=fopen(dst,"w");
	if (f_dst==NULL)
	{
		printf("open file error\n");
	}
	char buf[4096];
	int r;
	//此时r恰好就是实际读取的字节数
	//fread返回的是实际读取的个数(当size=1,就是字节数)也就是实际的count
	while((r=fread(buf,1,sizeof(buf),f_src))>0)
	{
		fwrite(buf,1,r,f_dst);
	if(r<sizeof(buf))
	  break;
	}
	fclose(f_src);
	fclose(f_dst);
}
char* catstr(const char*src,const char*dst)
{
		int len=strlen(src)+2+strlen(dst);
		char *path=(char *)malloc(len);
		sprintf(path,"%s/%s",dst,src);
		return path;
}
void copy_dir(const char*src,const char*dst)
{
	DIR* dp_src=opendir(src);
	struct dirent * dir_src;
	struct stat  sbuf_src;
	while((dir_src=readdir(dp_src))!=NULL)
	{
		//记住忽略.和..
		if(strcmp(dir_src->d_name,".")==0 || strcmp(dir_src->d_name,"..") == 0)
		  continue;
		char* s_path=catstr(dir_src->d_name,src);
		lstat(s_path,&sbuf_src);
		if(S_ISREG(sbuf_src.st_mode))
		{
		    printf("正在打开源普通文件-->%s\n",s_path);
			if(S_ISREG(sbuf_src.st_mode)==-1)
			{
				printf("error\n");
			}
			
			char* d_path=catstr(dir_src->d_name,dst);
			printf("正在复制到目标地区->%s\n",d_path);
			//拼接目录
			copy_file(s_path,d_path,sbuf_src.st_mode);
			free(s_path);
			free(d_path);
		}
		else if(S_ISDIR(sbuf_src.st_mode))
		{
			char*d_path=catstr(dir_src->d_name,dst);
		    printf("正在打开源目录-->%s\n",s_path);
			mkdir(d_path,sbuf_src.st_mode);
		    printf("正在创建目标目录-->%s\n",s_path);
			copy_dir(s_path,d_path);
			free(s_path);
			free(d_path);
		}
	}
}
int main(int argc,char*argv[])
{
	if(argc!=3)
	{
		fprintf(stderr,"./mycp dst src\n");
	}
	struct stat sbuf_src;
	struct stat sbuf_dst;
	mode_t old=umask(0);
	size_t flag_src=lstat(argv[1],&sbuf_src);
	size_t flag_dst=lstat(argv[2],&sbuf_dst);
	if(S_ISREG(sbuf_src.st_mode))
	{
		if(flag_dst==-1)
		{
			printf("目标不存在.是否创建新文件[y\\n\n]");
			char n;
			sscanf("%[yynn]",&n);
			if(n=='y' || n =='y')
			{
				copy_file(argv[1],argv[2],sbuf_src.st_mode);
			}
		}
		else if(S_ISREG(sbuf_dst.st_mode))
		{
			copy_file(argv[1],argv[2],sbuf_src.st_mode);
		}
		else if(S_ISDIR(sbuf_dst.st_mode))
		{
			char*dst_path=catstr(argv[1],argv[2]);
			copy_file(argv[1],dst_path,sbuf_src.st_mode);
			free(dst_path);
			// a    c/d
			// a   c/d/a
		}
	}
	else if(S_ISDIR(sbuf_src.st_mode))
	{
		if(S_ISREG(sbuf_dst.st_mode))
		{
			fprintf(stderr,"错误\n");
		}
		else if(S_ISDIR(sbuf_dst.st_mode))
		{
			char*s_dir=strrchr(argv[1],'/');
			s_dir++;
			if(s_dir==NULL)
			{
				s_dir=argv[1];
			}
			char* dst_path=catstr(s_dir,argv[2]);
			//如果目录不存在再创建目录
			if(access(dst_path,F_OK)!=0)
			{
				int mkdir_ret=mkdir(dst_path, sbuf_src.st_mode);
				if(mkdir_ret==-1)
				{
				  printf(" mkdir erroe\n");
				  return 0;
				}
			}
			copy_dir(argv[1],dst_path);
			free(dst_path);
		}

	}
	return 0;
}













