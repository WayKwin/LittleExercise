#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "%s filename\n", argv[0]);
		exit(1);
	}
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "open file err\n");
		exit(1);
	}
	int  l = 0;
	int c = 0;
	int w = 0;
	fseek(fp, 0, SEEK_END);
	int len = ftell(fp);
	//printf("%d", len);
	//回到文件开始
	rewind(fp);
	char *buff = (char *)malloc(len + 1);
//  读文件
	fread(buff, len, 1,fp);
	fclose(fp);
	int i = 0;
	// 01表示遇到单词首字母
	int status = 0;
	for (; buff[i] != 0; i++)
	{
		c++;
		if (buff[i] == '\n')
		{
			l++;
		}
		if (!isspace(buff[i])&&status==0)
		{
			w++;
			status = 1;
		}
		else if (isspace(buff[i]))
		{
			status = 0;

		}

	}



	system("pause");
}
