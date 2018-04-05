#include"tree.h"
#include<iostream>
val_t BST::get(key_t key)
{
	return get(root, key);
}
val_t BST::get(Node* x, key_t key)
{
	if (x == NULL)
	{
		return -1;
	}
	int cmp = (key < x->key ? -1 : key = x->key ? 0 : 1);
	if (cmp == -1) return get(x->left, key);
	else if (cmp == 1) return  get(x->right, key);
	else return x->val;
}
void BST::put(key_t key, val_t val)
{
	root = put1(root, key, val);
}

Node* BST::put1(Node* x, key_t key, val_t val)
{
	if (x == NULL)
	{
        Node* node =new  Node(key,val,1);
		return node;
	}
	int cmp = (x->key > key ? 1 : x->key == key ? 0 : -1);
	if (cmp == -1)
		x->right = put1(x->right, key, val);
	else if (cmp == 1)
		x->left = put1(x->left, key, val);
	else if (cmp == 0)
    {
		x->val = val;
        return x ;
    }
        //wrong 万一子树为空就解引用了空指针
        //x->N = x->left->N + x->right->N + 1;
        x->N = size(x->left) + size(x->right) + 1;
	    return x;

}
Node* BST::put2(Node* input, key_t key, val_t val)
{
	while (input != NULL)
	{
		int cmp = (input->key > key ? 1 : input->key = key ? 0 : -1);
		if (cmp == 1)
		{
			input->N++;
			input = input->right;
		}
		else if (cmp == -1)
		{
            input->N++;
            input=input->left;
		}
		else if (cmp == 0)
		{
			input->val = val;
            return root;
		}
	}
	input = new Node(key, val, 1);
	return root;
}

size_t BST::size(Node *x)
    {
        if(x == NULL)
        {
            return 0;
        }
        return x->N;
    }
key_t BST::select(int rank)
{
    Node* tmp =  select(root,rank);
    if( tmp == NULL )
    {
        return ' ';
    }
    return tmp->key;
}
Node* BST::select(Node *x,int t)
{
    if(x == NULL)
    {
        return NULL;
    }
    int cmp = t > size(x->left)? 1 : t == size(x->left)? 0 : -1;
    if (cmp == -1)
    {
        return select(x->left,t);
    }
    if(cmp == 0)
    {
        return x;
    }
    if(cmp == 1 )
    {
        return select(x->right,t-x->left->N-1);
    }
}
Node* BST::findMin(Node* x)
{
    if( x == NULL )
        return NULL;
    Node* t= x;
    while( t->left != NULL )
    {
        t = t->left;
    }
    return t;
}
Node* BST::deleteMin(Node* x)
{
    //递归基t
    if( x->left == NULL)
    {
#ifdef __DEBUG__DELETEMIN__
        std::cout <<"删除结果为:" << x->key << std::endl;
#endif
        delete (x);
        return x->right;
    }
    /*if x.left.left = NULL
     * x.left.left = NULL
     * x.left = x.left.right;
     */
    x->left =  deleteMin(x->left);
    x->N = size(x->left) + size(x->right) + 1;
    //返回过程
    return x;
}
void BST::deleteMin()
{
    root = deleteMin(root);
}
Node* BST::deleteNode(Node* x,key_t key)
{
    //要记录所的结点的父节点
    //所以不能用select
    //如果没找到需要的节点返回NULL;
    if( x == NULL )
        return NULL;
    int cmp =(x->key > key ? 1 : x->key == key ? 0 : -1);
    if(cmp > 0)
        //通过x->left =  ()留下父节点的记录
        //x->left = x->left->left;
        //每走一步,在递归返回时就能知道它的父节点
        x->left = deleteNode(x->left, key);
   else  if(cmp < 0)
        x->right = deleteNode(x->right, key);
    else
    {
#ifdef __DEBUG__DELETENODE__
        std::cout<< "找到删除的元素" << x->key << std::endl;
#endif
        //它的右子树为空,应该在左子树中找到最大的元素和该节点交换
        //if(x->right == NULL)
            //return x->left;
        //它的左子树为空,应该在右子树中找最小的元素和该节点交换
        //if(x->left == NULL)
            //return x->right;
        //找出右子树最小的节点和删除节点交换
        //选取左后继还是右后继应该是随机的
        //左右都为空 要把改节点都置为0
        Node* t = x;
        x = findMin(t->right);
        std::cout<< "找到比"<< t->key << "小的元素" << x->key << std::endl;

        x->right = deleteMin(t->right);
        //跟新子树
        x->left = t->left;
    }
    //下面两句同递归基返回并且每次跟新节点的数量
    x->N = size(x->left) + size(x->right);
    return x;
}
void BST::deleteNode(key_t key)
{
    root = deleteNode(root,key);
}
//int  select1(int t)
//{
	//Node *x= NULL;
	//if (x == NULL)
	//{
		//return -1;
	//}
	//while (x != NULL)
	//{
		//key_t key = x->left->N;
		//if( key == t)
		//return x->left->N;
		//else if (key > t)
		//{
			//x = x->left;
		//}
		//else if (key < t)
		//{
			//t = t - key - 1;
			//x = x->right;
		//}
	//}
    //return -1;
//}
void BST::show()
{

}
