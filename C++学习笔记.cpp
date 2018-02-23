#include<iostream>
#include<string>
using namespace::std;
class Sales_Data
{
	//声明友元函数(这些定义在外部的函数可以访问内中private修饰的成员变量了) ps.public修饰谁都可以访问
	//友元函数在类外还要重新声明 一次,这次仅是声明这些函数是"友元"
	friend Sales_Data add(const Sales_Data&, const Sales_Data&);
	friend ostream& print(ostream&, const Sales_Data&);
	friend istream& read(istream&, Sales_Data&);
public:
	//构造函数
	Sales_Data(const string&s, unsigned n, double p) ;
	Sales_Data(std::istream &is);
	Sales_Data();
	//成员函数
	string isbn()const { return this->bookNo; };
	Sales_Data& combine(const Sales_Data&);
private:
	double avg_price()const;
	//成员变量
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
//构造函数 ,在类外定义构造记得在类中声明
Sales_Data::Sales_Data() = default;
Sales_Data::Sales_Data(const string&s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(p*n){};
Sales_Data::Sales_Data(std::istream &is)  { read(is, *this); }
// 接口函数
Sales_Data add(const Sales_Data&, const Sales_Data&);
ostream& print(ostream&, const Sales_Data&);
istream& read(istream&,  Sales_Data&);
//成员函数的实现
double Sales_Data::avg_price() const// 带const 意思是是不修改成员变量
{                                   // (const Sales_Data* const this)this自带第二个顶层const
	if (units_sold)
		return revenue / units_sold;
	return 0;
}
Sales_Data&  Sales_Data::combine(const Sales_Data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;//this指向本对象,解引用;
}
//接口函数实现
Sales_Data add(const Sales_Data&lhs, const Sales_Data&rhs)
{
	//注意lhs是const修饰,不可以lhs.combine;
	Sales_Data sum = lhs;
	sum.combine(rhs);
	return sum;
}
//IO属于不可靠被拷贝类型
istream& read(istream &is, Sales_Data &item)
{
	double price = 0;
	cin >> item.bookNo >> item.units_sold >> price;
	return is;
}
ostream& print(ostream& os, const Sales_Data &item)
{

}
