#include<stdio.h>
#include<string.h>

void exchstr(char**str1, char**str2)
{
	char *c = NULL;
	c = *str1;
	*str1 = *str2;
	*str2 = c;
}
void string_sort(char **str, int size)
{
	int i = 0;
	int j = 0;
	int sorted ;
	for (i = 0; i < size - 1; i++)
	{
		sorted = 0;
		for (j = 0; j < size - 1 - i; j++)
		{

			if (strcmp(str[j], str[j+1])>0)
			{
				exchstr(&str[j], &str[j + 1]);
				sorted = 1;
			}
			
		}
		if (sorted == 0)
			break;
	}
}
int main()
{
	char *a[] = { "bello", "cello", "aello" };
	string_sort(a, sizeof(a) / sizeof(a[0]));
	printf("%s\n%s\n%s\n", a[0], a[1], a[2]);
	getchar();
}