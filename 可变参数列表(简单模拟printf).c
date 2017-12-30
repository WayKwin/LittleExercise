//int average(int nums, ...)
//{
//	va_list arg;
//	_crt_va_start(arg, nums);
//	int i = 0;
//	int sum = 0;
//	while (i < nums)
//	{
//		int data = _crt_va_arg(arg, int);
//		sum += data;
//		i++;
//	}
//	_crt_va_end(arg);
//	return sum / nums;
//
//}
//void printfnum(int nums, ...)
//{
//	va_list arg;
//	int d1=_crt_va_start(arg, nums);//这是启动函数,返回值不是第一个数nums
//	
//	int d2 = _crt_va_arg(arg, int);
//	int d3 = _crt_va_arg(arg, int);
//	int d4 = _crt_va_arg(arg, int);
//	
//	printf("第一个数:%d\n第二个数:%d\n第三个数:%d\n第四个数:%d\n", d1, d2, d3, d4);
//	_crt_va_end(arg);
//
//}
//int  maxNum(int nums, ...)
//{
//	va_list arg;
//	_crt_va_start(arg, nums);
//	int i = 0;
//	int max = _crt_va_arg(arg, int);
//	while (i < nums-1)
//	{
//		int compare = _crt_va_arg(arg, int);
//		max = compare>max ? compare : max;
//		i++;
//	
//	}
//	 _crt_va_end(arg);
//	 return max;
//}
void print(  char* start, ...)
{
	//思路:读取每一个字符然后 putchar
	va_list arg;
	_crt_va_start(arg, start);
	assert(start);
	char *wrold = start;
	while (*wrold)
	{
		char *c = NULL;
		if (*wrold == '%')
		{
			wrold++;
			switch (*wrold)
			{
			case 'c' :
				putchar(_crt_va_arg(arg, char));
				break;
			case 'd':
					printf("%d", _crt_va_arg(arg, int));
					break;
			case 's':
				c = _crt_va_arg(arg, char*);
				while (*c)
				{
					putchar(*c++);
				}
				break;
			}
		}
		else
		{
			putchar(*wrold);
		}
		wrold++;
	}
	_crt_va_end(arg);

}