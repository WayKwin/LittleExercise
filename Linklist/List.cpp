#include"List.h"
//当前节点前插入,设当前节点为p
void List::init()
{
	header = new ListNode;
	tailer = new ListNode;
	header->Pred = NULL;
	header->data = 111;
	header->Succ = tailer;
	tailer->Pred = header;
	tailer->Succ = NULL;
	tailer->data = 999;
	_size = 0;
}
Node List::insertAsFrist(int data)
{
	_size++;
	
	return  header->insertAsSucc(data);

}
Node List::insertAsLast(int data)
{
	_size++;
	return tailer->insertAsPre(data);
}
Node List::insertAsB(Node p, int data)
{
	_size++;
	//注意insertAsPre是节点类的成员函数,不能无故调用
	//Node p = p->insertAsPre(data);
	return p->insertAsPre(data);
}
Node List::insertAsA(Node p, int data)
{
	_size++;
	return p->insertAsSucc(data);
}
int  List::remove(Node p)
{
	_size--;
	p->Succ->Pred = p->Pred;
	p->Pred->Succ = p->Succ;
	int x = p->data;
	free(p);
	return x;
}
void List::copyNode(Node p, int n)
{
	init();
	while (n--)
	{
		insertAsLast(p->data);
		p->Succ;
	}
}
List::List(List const &L)
{
	copyNode(L.frist(), L._size);
}