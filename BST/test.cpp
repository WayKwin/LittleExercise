#include"bst.h"
int main()
{
   BST tree;
    tree.put('a',1);
    tree.put('b',1);
    tree.put('c',1);
    tree.put('d',1);
   key_t c  =  tree.select(0);
    std::cout << c <<std::endl;
    return 0;
}
