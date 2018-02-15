void yanghui()
{
	int n ;
        scanf("%d",&n);
	int**p = (int **)malloc(n*sizeof(int *));
	if (p == NULL)
	{
		return;
	}
	for (int i = 0; i < n; i++)
	{
		p[i] = (int *)malloc(n*sizeof(int));
	}
	 p[0][0] = 1;
	for (int i = 1; i < n;i++)
	{

		for (int j = 0; j <= i; j+=i)
		{
			
			p[i][j] = 1;
		}
	}
	for (int i = 2; i < n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			p[i][j] = p[i - 1][j] + p[i-1][j - 1];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int k = n; k>i; k--)
		{
			printf(" ");
		}
		for (int j = 0; j <= i; j++)
		{
			printf("%d ", p[i][j]);
		}
		printf("\n");

	}
	free(p);
}