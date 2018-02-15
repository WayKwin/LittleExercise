void sortrank()
{
	int a, b, c, d, e;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if (
							(((b == 1) + (a == 3)) ==1) &&
							(((b == 2) + (e == 4))==1) &&
							(((c == 1) + (d == 2))==1) &&
							(((c == 5) + (d == 3))==1) &&
							(((e == 4) + (a == 1))==1)
							)
							
						   {
							int flag = 0;
							flag |= (1 << (a - 1));
							flag |= (1 << (b - 1));
							flag |= (1 << (c - 1));
							flag |= (1 << (d - 1));
							flag |= (1 << (e - 1));
							while (flag)
							{
								if (!(flag & 1))
								{
									break;
								}
								flag >>= 1;
							}
							if (flag == 0)
							{
								printf("A=%d,B=%d,C=%d,D=%d,E=%d\n", a, b, c, d, e);
							}
							
						    }

							
							
					}
				}
			}
		}
	}

}