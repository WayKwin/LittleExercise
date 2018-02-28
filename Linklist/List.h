#include"ListNode.h"
class List
{
private:
	Node header;
	Node trailer;
	int _size;
public:
	//构造函数
	List(){ init(); }
	void init();
	//只读接口
	Node frist() const{ return header->Succ; }
	Node last() const{ return trailer->Pred; }
	//写入接口
	Node insertAsFrist(int data);//插入首节点  header 头
	Node insertAsLast(int data);//插入尾节点   trailer 末
	Node insertAsB(Node p, int data);//在该节点前插入节点
	Node insertAsA(Node p, int data);//在该节点后插入节点
	int remove(Node p);
};
