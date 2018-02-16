int digui(int n,int k)
{
	if (k == 0)
		return 1;
	return digui(n,k-1)*n;
}
int DigitSum(int n)
{
	if (n < 10)
	{
		return n;
	}
	return DigitSum(n / 10) + n % 10;
}