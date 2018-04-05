#include<iostream>
typedef int val_t;
typedef char key_t;
typedef struct Node
{
	key_t key;
	val_t val;
	struct Node* right;
	struct Node* left;
	int N;
	Node(key_t key, val_t val, int N) :key(key), val(val), N(N){}

}Node;

class BST
{
private:
	Node* root;
	int size(Node x);
	val_t get(Node* x, key_t key);
	Node* put1(Node* x, key_t key, val_t val);
	Node* put2(Node* x, key_t key, val_t val);
    size_t size(Node *x);
	Node* select(Node* x,int t);
    Node* deleteMin(Node*);
    Node* deleteNode(Node* x, key_t key);
    Node* findMin(Node*);
public:
    void deleteMin();
    BST():root(NULL){};
	int size();
    void show();
	val_t get(key_t key);
	void put(key_t key, val_t val);
    key_t select(int rank);
    void deleteNode(key_t key);
    int isEmpty()
    {
        return root == NULL? 1:0;
    }
};
