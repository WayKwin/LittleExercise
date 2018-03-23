#include"bst.h"
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
		x->left = put1(x->left, key, val);
	else if (cmp == 1)
		x->right = put1(x->right, key, val);
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
