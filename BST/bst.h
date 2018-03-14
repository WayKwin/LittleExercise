typedef int val_t;
typedef char key_t;
typedef struct Node
{
	val_t key;
	val_t val;
	struct Node* right;
	struct Node* left;
	int N;
	Node(key_t key, val_t val, int N) :key(key), val(val), N(N){}

}Node;

class BST
{
private:
	Node root;
	int size(Node x);
	val_t get(Node& x, key_t key);
	Node* put1(Node* x, key_t key, val_t val);
	Node* put2(Node* x, key_t key, val_t val);
public:
	int size();
	val_t get(key_t key);
	void put(key_t key, val_t val);
	//返回名次为t 的节点的key
	key_t select(int t);
};