#include<stdio.h>
void exchange(char*begin, char* end)
{
	while (begin < end)
	{
		char temp = *begin;
		*begin = *end;
		*end = temp;
		begin++;
		end--;
	}
}
char * left(char *str, int size,int n)
{
	char* ret = str;
	int times = n%(size-1);
	char* head1 = str;
	char* head2 = str + times;
	exchange(head1, head2-1 );
	exchange(head2, str + size - 2);
	exchange(str, str + size-2 );
	return  str;

}
int main()
{
	char a[] = "abcd";
	printf("%s", left(a, 5, 2));
	getchar();
}