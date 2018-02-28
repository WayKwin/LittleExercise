#include"List.h"

	int main()
	{
		List mylist;
		Node p1 = mylist.insertAsFrist(1);
		Node p2 = mylist.insertAsA(p1, 2);
		Node p3 = mylist.insertAsA(p2, 3);
		mylist.remove(p2);
		Node p = p1;
		while (p != mylist.last())
		{
			cout << p->data << endl;
			p = p->Succ;
		}
		cout << p->data << endl;
		getchar();

	}
