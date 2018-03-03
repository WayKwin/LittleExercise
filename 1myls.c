#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>
#include<dirent.h>

	int foreground =0;
	int background =1;
	int colormode = 0;
void file_type(mode_t st_mode,int *f,int *b,int*m)
{
	char mode[11]="?---------";
	//文件类型
	if((st_mode&S_IFMT)==S_IFLNK)
	{
	mode[0]='l';
	*f=36;
	}
	if((st_mode&S_IFMT)==S_IFREG)
	{
		mode[0]='-';
		*f=37;
	}
	if((st_mode&S_IFMT)==S_IFSOCK)
	{
		mode[0]='s'; 
		*f=32;
	}
	if((st_mode&S_IFMT)==S_IFBLK) 
	{
		mode[0]='b';
		*f=33;
		*m=1;
	}
	if((st_mode&S_IFMT)==S_IFDIR)
	{
		mode[0]='d';
		*f =34;
	}
	if((st_mode&S_IFMT)==S_IFCHR)
	{
		mode[0]='c';
		*m=1;
		*f=33;
		*b=40;
	}
	if((st_mode&S_IFMT)==S_IFIFO)
	{
		mode[0]='p';
		*f =33;
		*b =40;
	}
	//权限
	 if((st_mode&S_IRUSR)) mode[1]='r';
	 if((st_mode&S_IWUSR)) mode[2]='w';
	 if((st_mode&S_IXUSR)) mode[3]='x';
	 if((st_mode&S_IRGRP)) mode[4]='r';
	 if((st_mode&S_IWGRP)) mode[5]='w';
	 if((st_mode&S_IXGRP)) mode[6]='x';
	 if((st_mode&S_IROTH)) mode[7]='r';
	 if((st_mode&S_IWOTH)) mode[8]='w';
	 if((st_mode&S_IXOTH)) mode[9]='x';
	 printf("%s",mode);
}
	void  display(const char* filename)
{
	struct stat sbuf;
	if(lstat(filename,&sbuf)==-1)
	{
		printf("调用错误\n");
		return ;
	}
	file_type(sbuf.st_mode,&foreground,&background,&colormode);
	// 打印硬连接
	printf("%2d ",sbuf.st_nlink);
	// 获得 uid
	struct passwd* pwu=getpwuid(sbuf.st_uid);
	printf("%2s ",pwu->pw_name);
	// 获得gid
	struct group* pwg=getgrgid(sbuf.st_gid);
	printf("%2s ",pwg->gr_name);
	// 获得文件大小
	printf("%d ",sbuf.st_size);
	// 时间
	
	struct tm *lt=localtime(&(sbuf.st_mtim.tv_sec));
	printf("%04d-%02d-%2d ",lt->tm_year+1900,lt->tm_mon+1,lt->tm_mday);
	
	// printf argv[1]
	 printf("\033[%d,%d,%dm%s\033[0m	",colormode,foreground,background,filename);
	// 判断软连接
	 if((sbuf.st_mode&S_IFMT)==S_IFLNK)
	 {
	char buf[256]={};
	readlink(filename,buf,256);
	printf("-> %s",buf);
	 }
	// printf ->  
	// readlink(argv[1],buf,buf_len);
	printf("\n");	
	
}
void  display_dir(const char *filename)
{
	DIR* dir=opendir(filename);
	struct dirent* result=NULL;
	while((result=readdir(dir))!=NULL)
	{
		if(result->d_name[0]=='.')
			continue;
	struct stat sbuf;
	if(lstat(filename,&sbuf)==-1)
	{
		printf("调用错误\n");
		return ;
	}
	file_type(sbuf.st_mode,&foreground,&background,&colormode);
	// 打印硬连接
	printf("%2d ",sbuf.st_nlink);
	// 获得 uid
	struct passwd* pwu=getpwuid(sbuf.st_uid);
	printf("%2s ",pwu->pw_name);
	// 获得gid
	struct group* pwg=getgrgid(sbuf.st_gid);
	printf("%2s ",pwg->gr_name);
	// 获得文件大小
	printf("%d ",sbuf.st_size);
	// 时间
	
	struct tm *lt=localtime(&(sbuf.st_mtim.tv_sec));
	printf("%04d-%02d-%2d ",lt->tm_year+1900,lt->tm_mon+1,lt->tm_mday);
	
	// printf argv[1]
	 printf("\033[%d,%d,%dm%s\033[0m	",colormode,foreground,background,result->d_name);
	// 判断软连接
	 if((sbuf.st_mode&S_IFMT)==S_IFLNK)
	 {
	char buf[256]={};
	readlink(filename,buf,256);
	printf("-> %s",buf);
	 }
	// printf ->  
	// readlink(argv[1],buf,buf_len);
	printf("\n");	
	}
	closedir(dir);
	
}
int main( int argc,char *argv[])
{
	if (argc != 2) {
		fprintf(stderr,"usage:%s filename\n",argv[0]);
		exit(1);
	} 
	struct stat subf;
	lstat(argv[1],&subf);
	if((subf.st_mode&S_IFMT)==S_IFDIR)
	{
	display_dir(argv[1]);
	}else{
		display(argv[1]);
	}
	
}
