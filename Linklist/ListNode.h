#include<iostream>
using namespace::std;
#define Node ListNode*
struct ListNode
{
	int data;
	struct ListNode* Pred;
	struct ListNode* Succ;
	ListNode(){};
	ListNode(int d, ListNode* p = NULL, ListNode* s = NULL)\
		:data(d), Pred(p), Succ(s){};
	ListNode* insertAsPre(int data);
	ListNode* insertAsSucc(int data);
	ListNode* my_insertAsPre(int data);

};
