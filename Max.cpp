void MaxPQ::swim(int m)
{
	while(m>1&&(a[m]>a[m/2]))
	{
		exch(a[m],a[m/2]);
		m/=2;
	}
}
void MaxPQ::sink(int m)
{
	while(2*m>=n)
	{
		int j=2*m;
		if(j>n&&(less(a[j],a[j+1])) j++;
				if(less(a[j],a[m]) break;
				exach(a[m],a[j]);
				m=j;
	}
}
