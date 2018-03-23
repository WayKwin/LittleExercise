#include<iostream>
class a
{
    public :
    int intger;
    void change ()
    {
        intger = 1;
    }
};
int main()
{
    a a1;
    a1.change();
    std::cout<<a1.intger;
}

