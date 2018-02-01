#include<iostream>
int main()
{
	int i = 0;
	char a[10];	
	std::cin >> a;
	while (a[i] != '\0')
	{
		if (a[i] <= 90 && a[i] >= 65)
		{
			a[i] += 32;
		}
		i++;
	}
	std::cout << a << std::endl;
	system("pause");
	return 0;
}