#include<stdio.h>
#pragma warning(disable:4996)
int months[2][13] = { {0,  31,28,31,30,31,30,31,31,30,31,30,31},
					  { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } 
					};
	int isLeap(int year)
	{
		return ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) ? 1 : 0;
	}
	void display_this(int year, int month, int start)
	{
		int i;
		printf("  一  二  三  四  五  六  日  \n");
		for (i = 0; i < start - 1; i++)
		{
			printf("    ");
		}
		for (i = 1; i <= months[isLeap(year)][month]; i++)
		{
			printf("%4d", i);
			if ((i + start - 1) % 7 == 0)
			{
				printf("\n");
			}
		}
		printf("\n");


	}
	void display_three(int year,int month)
	{	
		// before= (month-1)%12
		// after=(month+1)%12
		// if  before==12; year-1;
		// if after==1  year+1
		
		if (month == 1)
		{
			display_this(year-1, 12, frist(year-1, 12));
			printf("\n");
			display_this(year, month, frist(year, month));
			printf("\n");
			display_this(year, month + 1, frist(year, month + 1));
			printf("\n");
			return;
		}
		else if (month == 12)
		{
			display_this(year, month - 1, frist(year, month - 1));
			printf("\n");
			display_this(year, month, frist(year, month));
			printf("\n");
			display_this(year+1, 1, frist(year+1, 1));
			printf("\n");
			return;
		}

		display_this(year, month - 1, frist(year,month-1));
		printf("\n");
		display_this(year, month, frist(year, month ));
		printf("\n");
		display_this(year, month + 1, frist(year, month +1));
		printf("\n");

	}
	int frist(int year, int month)
	{
		int base_year = 2000;
		int base_week = 6;
		int i;
		int j;
		int total_day = 0;
		for (i = base_year; i < year; i++)
		{
			for (j = 0; j < 13; j++)
			{
				total_day += months[isLeap(i)][j];
			}
		}
		int day_of_fristyear = (base_week + total_day) % 7;
		total_day = 0;
		for (i = 0; i < month; i++)
		{
			total_day += months[isLeap(i)][i];
		}
		int day_of_fristmonth = (day_of_fristyear + total_day) % 7;
		//整除情况下表示是周日
		if (day_of_fristmonth == 0)
		{
			day_of_fristmonth = 7;
		}
		return day_of_fristmonth;
	}
	int main()
	{
		int year;
		int month;
		int option;
		int base_year = 2000;
		int base_week = 6;
		printf("请输入年月,选项 1:显示当月 2:近三月\n");
		scanf("%d-%d,%d", &year, &month,&option);
		option %= 2+1;
		option == 1 ? display_this(year, month,frist(year,month)) : display_three(year, month);
		system("pause");
	}