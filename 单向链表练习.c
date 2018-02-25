#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
//应该定义为双向链表
//并设立首尾哨兵节点(方便插入和删除)
typedef  struct person
{
	char *name;
	int age;
	struct person* next;	
}person_t;
person_t *head = NULL;
enum option
{
	insert = 1, findbyname, deletebyname, display
};
int menu()
{
	int choose;
	printf("1:插入成员\n");
	scanf("%d", &choose);
	return choose;
	
}
void insert()
{
	person_t *p = (person_t *)malloc(sizeof(person_t));
	printf("input name\n");
	char buf[100] = {0};
	scanf("%s", &buf);
	p->name = (char *)malloc(sizeof(strlen(buf)	+1));
	//避免对指针指向的改动
	//p->name =buf;
	strcpy(p->name, buf);
	printf("input age:\n");
	scanf("%d", &(p->age));
	p->next = NULL;
	//首节点的初始化;
	if (head == NULL)
	{
		head= p;
	}
	else
	{
		person_t *temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = p;
		
	}
}
int findbyname()
{
	printf("请出入查找姓名\n");
	char buf[100] = {0};
	scanf("%s",&buf);
	person_t *p = head;
	while (p != NULL && (strcmp(p->name, buf) != 0))
	{
		p = p->next;
	}
	return p == NULL ? -1 : p->age;
}
void deletebyname()
{
	printf("请输入删除人员的名字\n	");
	char buf[100] = { 0 };
	scanf("%s", &buf);
	person_t *p = head;
	
	if (strcmp(p->name, buf) == 0)
	{
		if (p ->next != NULL)
		{
			
			head = p->next;
			free(p);
		}
		if (p->next == NULL)
		{
			head = NULL;
			free(p);
		}
		return 0;
	}
	//剩下的情况,循环结束p指向->需要删除的上一个struct;
	while (p != NULL && (strcmp(p->next->name, buf) != 0))
	{
		p = p->next;
	}
	//用指针保存此时要删除的节点,以便后续释放此节点
	person_t *temp = p->next;
	//排除尾节点的情况
	if (p->next->next!= NULL)
	p->next = p->next->next;
	//尾节点的情况
	else p->next = NULL;
	//释放
	free(temp);
}
void display()
{
	
	person_t *p = head;
	if (p == NULL)
	{
		printf("管理系统为空\n");
	}
	while( p != NULL)
	{
		printf("成员信息如下:\n" );
		printf("%s\n", p->name);
		printf("%d\n", p->age);
		p = p->next;
	}
}
int main()
{

}