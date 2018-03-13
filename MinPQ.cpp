#include<iostream>
using  namespace::std;
#define less(x,y)	((x<y)?1:0)
#define exch(x,y)	int c=y; y=x;x=c
class indexMinPQ
{
private:
	int *a;//优先队列
	int n = 0;//优先队列的长度
	char *b;// value
	int k;//key
	//*a里面装 k  通过b[k]找value
	void swim(int m)
	{
		while (m>1)
		{
			// key1->value < key2->value
			//交换a[n]里的key   key指向内容不变
			if (b[a[m]] <b[a[m / 2]])
			{
				exch(a[m], a[m / 2]);
				m /= 2;
			}
			//注意大于的情况直接结束
			else break;
		}
	}
	void sink(int m)
	{
		//当还有子节点的时候
		while (2 * m <= n)
		{
			//默认的左子节点
			int j = 2 * m;
			//如果有右子节点且比左子节点小
			if (j < n&&less(b[a[j+1]], b[a[j]] ))
			{
				j++;//变成右节点
			}
			//如果父节点的内容比最小子节点内容小  ,交换两个key
			if (less(b[a[m]],b[a[j]])) break;
			exch(a[m], a[j]);
			m = j;
		}
	}
public:
	indexMinPQ(int *start = (int *)malloc(sizeof(int)*(3)),char *value=(char*)malloc(4)) :a(start),b(value){};
	~indexMinPQ(){ free(a); free(b); }
	void insert(int key,char  value)
	{
		a[++n] = key;
		b[key] = value;
		swim(n);
	}
	//找到最小的索引
	bool isEmpty()
	{
		return (n < 1 ? true : false);
	}
	int find_minkey()
	{
		return a[1];
	}
	//找到最小元素
	char find_minvalue()
	{
		return b[a[1]];
	}
		//仅改变索引,不改变优先队列
	void chage_key(int key,char value)
	{
		b[key] = value;
	}
	//返回最小值的索引
	int del_minkey()
	{
		int p = a[1];
		a[1] = a[n--];
		sink(1);
		return p;
	}
	char findvalue(int key)
	{
		return b[key];
	}
	char del_minvalue()
	{
		return b[del_minkey()];
	}


};
int main()
{
	//优先队列可以在有效空间内总是返回最大,最小元素
	indexMinPQ m;
	char *a = "adg";
	char *b = "beh";
	char *c = "cfi";
	char*list[] = { a, b, c };
	//  a  b  c 的key分别刚好就是 0 1 2 
	for (int i = 0,k=0; i <3; i++)
	{
		m.insert(i, list[i][k]);
	}
	int key ;
     //优先队列为0表示排序完成
	while (!m.isEmpty())
	{
		printf("%c", m.find_minvalue());
		key = m.del_minkey();
		//注意前置++  保证不会insert \0  而且是从第二个字符开始插入,(刚好满足前面已经打印第一个元素了,需要处理第二个元素的要求)
		if (*(++list[key]) != '\0')
		{
			m.insert(key, *(list[key]));
		}
	}
	getchar();
	return 0;
}