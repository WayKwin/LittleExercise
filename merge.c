#include<stdio.h>
int main()
{
	int a[] = { 1, 3, 5, 7 };
	int b[] = { 4, 5, 8, 9, 10};
	int asize = 4;
	int bsize = 5;
	int c[9];
	int i = 0;
	int j = 0;
	int k = 0;
	for (; i < asize || j < bsize;)
	{
		if (i<asize && (bsize<=j||a[i] <= b[j]))// 由于 i < asize || j < bszie  所以i<asize可能会不成立,因此这里必须保证a[i]的合法性
		{                       //    i<asize&&a[i]<=b[j] 也不严密 存在i>size 转向else if 判断但是b[j]<a[i]的情况,死循环,
			                    //事实上当i>size  就把B全部装进C就行了
			c[k++] = a[i++];    // 这里加上 bisze<=k  b越界,也就是b[]全部装进了C[]中,那么A[]剩下的肯定不用判断,要全部装入C[]
		}                       //哨兵 无穷大技巧
		else if (j<bsize && (asize<=i||b[j] < a [i]))
		{
			c[k++] = b[j++];
		}
	}
	getchar();
	return 0;
}