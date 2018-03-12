#include<iostream>
#include<stddef.h>
#include"SeqList.h"
using namespace::std;
#define p std::cout<<std::endl<<"========================="<<__FUNCTION__<<"============================"<<std::endl

SeqList s;
void testPushBack()
{
	p;
	s.PopBack();
	s.PushBack(1);
	s.PushBack(2);
	s.PopBack();
	s.showSeqList();
}
void testFront()
{
	p;
	s.insert(0, 0);
	s.insert(1, 1);
	s.insert(2, 2);
	s.showSeqList();
}
void testall()
{
    s.insert(0,0);
    s.PushBack(1);
    s.PushBack(2);
    s.PushBack(3);
    s.PushBack(4);
    s.PushBack(5);
    cout<<"查找key为5的value为:=>"<<s.findByKey(5)<<endl;
    cout<<"查找value为1的key为:=>"<<s.findByValue(1)<<endl;
    s.showSeqList();
}
int main()
{
	//testFront();
	//testFront();
    testall();
	return 0;
}
