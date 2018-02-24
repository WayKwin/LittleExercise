#include<iostream>
#include<string>
#include<vector>
using namespace::std;
class Screen
{
public :
	typedef  string::size_type pos;
	//测试 mutalbe用例
	void some_member() const;
	//using pos = string::size_type;
	//构造函数
	Screen() = default;
	Screen(pos hi, pos wi, char c) :height(hi), width(wi), contents(hi*wi, c){};//String还能这样初始化
	//成员函数默认是内联类型的
	char get(){ return contents[cursor]; }
	inline char get(pos hi, pos wd) const;
	Screen &move(pos r, pos c);
	//7.3.2新增函数
	Screen& set(char);
	Screen& set(pos, pos, char);
private:
	//可变数据成员被const函数调用 这个函数也能修改它 L40
	mutable size_t access_ctr;
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
};
inline char Screen::get(pos r, pos c) const
{
	pos row = r*width;
	//注意 函数const修饰, 非静态成员变量不能修改
	//contents = "abcd";
	return contents[row + c];
}
inline Screen &Screen::move(pos r, pos c)
{

	pos row = r*width;
	cursor = row + c;
	return *this;
}
void Screen::some_member() const
{
	access_ctr++;
}
class Window_mgr
{
private :
	//类数据成员的初始值
	//一组Screen存在Vector中 默认初始值就是一个特定Screen如下;
	vector<Screen> Screens{ Screen(20, 80, ' ') };
};
inline Screen& Screen::set(char c)
{
	contents[cursor] = c;//设置当前位置为C
	return *this;
}
inline Screen& Screen::set(pos r, pos col, char ch)
{
	contents[r*width + col] = ch;
	return *this;
}
int main()
{
	Screen MyScreen;
	//调用的两个函数返回值都是引用,
	//表明都是在一个对象上进行的操作
	//若move返回screen 那么set就是在新screen进行的操作
	MyScreen.move(4, 0).set('*');
}