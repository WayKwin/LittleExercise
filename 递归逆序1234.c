void print_num(int num)
{
	if (num > 9)
	{
		print_num(num / 10);
	}
	
	printf("%d ", num%10);
}