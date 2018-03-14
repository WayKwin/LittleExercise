#include"bst.h"
#include<iostream>
val_t BST::get(key_t key)
{
	//从根节点开始找
	return get(root, key);
}
val_t BST::get(Node& x, key_t key)
{
	if (&x == NULL)
	{
		return -1;
	}
	int cmp = (key < x.key ? -1 : key = x.key ? 0 : 1);
	if (cmp == -1) return get(*x.left, key);
	else if (cmp == 1) return  get(*x.right, key);
	else return x.val;
	
}
void BST::put(key_t key, val_t val)
{
	//  私有put是一个典型的递归,从root入栈,最后从root出栈 ,因为返回值是Node类型的,也可以写成void类型
	root = *put1(&root, key, val);
}
//递归版
Node* BST::put1(Node* x, key_t key, val_t val)
{
	if (x == NULL)
	{
		Node e(key, val, 1);
		return &e;
	}
	int cmp = (x->key > key ? 1 : x->key = key ? 0 : -1);
	//通过左右大小比较  入栈递归不断找到合适插入点
	if (cmp == -1)
		x->left = put1(x->left, key, val);
	else if (cmp == 1)
		x->right = put1(x->right, key, val);
	else
		x->val = val;
      x->N = x->left->N + x->right->N + 1;
	  return x;
}
//迭代版 相对于 迭代版没有回溯的过程
Node* BST::put2(Node* x, key_t key, val_t val)
{

	while (x != NULL)
	{
		int cmp = (x->key > key ? 1 : x->key = key ? 0 : -1);
		if (cmp == 1)
		{
			x->N++;
			//当x=x->right  为NULL时 也就是它右子节点为空.就找到了合适的插入点
			x = x->right;
		}
		if (cmp == -1)
		{
		x->N++;
		x=x->left;
		}
		//key值相同的情况
		else
		{
			x->val = val;
		}
	}
	Node e(key, val, 1);
	x = &e;
	return &root;
}

key_t BST::select(int t)
{
	Node *x=& root;
	if (x == NULL)
	{
		return -1;
	}
	while (x!=NULL)
	{
		//注意NULL
		key_t key = x->left->N;
		if( key== t)
		return x->N;
		else if (key > t)
		{
			x = x->left;
		}
		else if (key < t)
		{
			t = t - key - 1;
			x = x->right;
		}
	}
}

