#include <iostream>
using namespace std;

class Node
{
	friend class Tree;
private:
	int key;
	Node* left = nullptr;
	Node* right = nullptr;
	Node* parent = nullptr;
	int height = 1;
	int numOfNode = 0;
	int BF = 0;

	Node(int v)
	{
		key = v;
	}
};

class Tree
{
private:
	Node * root;
public:
	Tree()
	{
		root = nullptr;
	}
	void inorder(Node* n)
	{
		if (n != nullptr)
		{
			inorder(n->left);
			cout << n->key << " ";
			inorder(n->right);
		}
	}
	Node* maxNode(Node* n)
	{
		Node* p = n;
		while (p->right != nullptr)
		{
			p = p->right;
		}
		return p;
	}
	Node* minNode(Node* n)
	{
		Node* p = n;
		while (p->left != nullptr)
		{
			p = p->left;
		}
		return p;
	}
	void numOfNodes(Node* n)
	{
		Node* p = n;
		if (p != nullptr)
		{
			numOfNodes(n->left);
			numOfNodes(n->right);
			if (p->left != nullptr && p->right == nullptr)
			{
				p->numOfNode = p->left->numOfNode + 1;
			}
			else if (p->left == nullptr && p->right != nullptr)
			{
				p->numOfNode = p->right->numOfNode + 1;
			}
			else if (p->left != nullptr &&p->right != nullptr)
			{
				p->numOfNode = p->right->numOfNode + p->left->numOfNode + 2;
			}
			else
			{
				p->numOfNode = 0;
			}
		}
	}
	void setBF(Node *n)
	{
		Node* p = n;
		if (p!= nullptr)
		{
			setBF(p->left);
			setBF(p->right);
			if (p->left == nullptr && p->right==nullptr)
			{
				p->BF = 0;
			}
			else if (p->left == nullptr)
			{
				p->BF = -(p->right->height);
			}
			else if(p->right==nullptr)
			{
				p->BF = p->left->height;
			}
			else
			{
				p->BF = p->left->height - p->right->height;
			}
		}
	}
	void setHeight(Node* n)
	{
		Node* p = n;
		if (p != nullptr)
		{
			setHeight(p->left);
			setHeight(p->right);
			if (p->left == nullptr && p->right == nullptr)
			{
				p->height = 1;
			}
			else if (p->left == nullptr)
			{
				p->height = p->right->height + 1;
			}
			else if (p->right == nullptr)
			{
				p->height = p->left->height + 1;
			}
			else
			{
				if (p->left->height > p->right->height)
				{
					p->height = p->left->height + 1;
				}
				else
				{
					p->height = p->right->height + 1;
				}
			}
		}
	}
	Node* getNode(int v)
	{
		return new Node(v);
	}
	void delNoChild(Node *n)
	{
		if (n == root)
		{
			root = nullptr;
			return;
		}
		Node* p = n->parent;
		if (p->key < n->key)
		{
			p->right = nullptr;
		}
		else
		{
			p->left = nullptr;
		}
	}
	void delonlyOneChild(Node *n)
	{
		Node* p = n;
		if (p == root)
		{
			if (p->left == nullptr)
			{
				root = p->right;
				root->parent = nullptr;
				return;
			}
			else
			{
				root = p->left;
				root->parent = nullptr;
				return;
			}
		}
		if (p->left == nullptr)
		{
			if (p->parent->key > p->right->key)
			{
				p->right->parent = p->parent;
				p->parent->left = p->right;
			}
			else
			{
				p->right->parent = p->parent;
				p->parent->right = p->right;
			}
		}
		else
		{
			p->left->parent = p->parent;
			if (p->parent->key > p->left->key)
			{
				p->parent->left = p->left;
			}
			else
			{
				p->parent->right = p->left;
			}
		}

	}
	void delTwoChild(Node* n)
	{
		Node* p = n;
		if (p->right->height == p->left->height)
		{
			if (p->left->numOfNode <= p->right->numOfNode)
			{
				if (minNode(p->right)->right == nullptr)
				{
					p->key = minNode(p->right)->key;
					if (minNode(p->right)->parent == n)
					{
						minNode(p->right)->parent->right = nullptr;
						return;
					}
					minNode(p->right)->parent->left = nullptr;
				}
				else
				{
					p->key = minNode(p->right)->key;
					minNode(p->right)->right->parent = minNode(p->right)->parent;
					minNode(p->right)->parent->left = minNode(p->right)->right;
				}
			}
			else
			{
				if (maxNode(p->left)->left == nullptr)
				{
					p->key = maxNode(p->left)->key;
					maxNode(p->left)->parent->right = nullptr;
				}
				else
				{
					p->key = maxNode(p->left)->key;
					maxNode(p->left)->left->parent = maxNode(p->left)->parent;
					maxNode(p->left)->parent->left = maxNode(p->left)->left;
				}
			}
		}
		else if (p->left->height < p->right->height)
		{
			if (minNode(p->right)->right == nullptr)
			{
				p->key = minNode(p->right)->key;
				minNode(p->right)->parent->left = nullptr;
			}
			else
			{
				p->key = minNode(p->right)->key;
				if (minNode(p->right)->parent->key == p->key)
				{
					minNode(p->right)->right->parent = minNode(p->right)->parent;
					minNode(p->right)->parent->right = minNode(p->right)->right;
					return;
				}
				minNode(p->right)->right->parent = minNode(p->right)->parent;
				minNode(p->right)->parent->left = minNode(p->right)->right;
			}
		}
		else
		{
			if (maxNode(p->left)->left == nullptr)
			{
				p->key = maxNode(p->left)->key;
				maxNode(p->left)->parent->right = nullptr;
			}
			else
			{
				p->key = maxNode(p->left)->key;
				maxNode(p->left)->left->parent = maxNode(p->left)->parent;
				maxNode(p->left)->parent->left = maxNode(p->left)->left;
			}
		}
	}
	void checkbalance(int v)
	{
		Node* p = root;
		Node* old;
		while (p->key != v)
		{
			if (p->key <= v)
			{
				p = p->right;
			}
			else
			{
				p = p->left;
			}
		}
		old = p;
		while (p != root)
		{
			if (p->parent == nullptr)
			{
				if (p->BF == 1 || p->BF == 0 || p->BF == -1)
				{
					break;
				}
				else
				{
					if (p->BF <= -2)
					{
						return rotateTree(4, p, p->right);
					}
					else
					{
						return rotateTree(4, p, p->left);
					}
				}
			}
			old = p;
			p = p->parent;
			if (p->parent == nullptr)
			{
				cout << "NO" << " ";
				return;
			}
			if (p->parent->BF == -2 )
			{
				if(old->key<p->key)
				{
					return rotateTree(4, p, p->parent);
				}
				else
				{
					return rotateTree(3, p, p->parent);
				}
			}
			else if (p->parent->BF == 2)
			{
				if (old->key < p->key)
				{
					return rotateTree(1, p, p->parent);
				}
				else
				{
					return rotateTree(2, p, p->parent);
				}
			}
		}cout << "NO" << " ";
		return ;
	}
	void rotateTree(int i, Node* ppp,Node* pppp)
	{
		Node* p = pppp;
		Node* old = ppp;
		Node* pp = pppp->parent;
		if (i == 5)
		{
			cout << "NO" << " ";
		}
		else if (i == 1)
		{
			cout << "LL" << " ";
			if (pp == nullptr)
			{
				root = old;
				root->parent = NULL;
				p->left = old->right;
				if (p->left != nullptr)
				{
					p->left->parent = p;
				}
				old->right = p;
				old->right->parent = old;
				return;
			}
			if (pp->key > p->key)
			{
				pp->left = old;
				p->left = old->right;
				if (p->left != nullptr)
				{
					p->left->parent = p;
				}
				old->right = p;
				p->parent = old;
				old->parent = pp;
			}
			else
			{
				pp->right = old;
				p->left = old->right;
				if (p->left != nullptr)
				{
					p->left->parent = p;
				}
				old->right = p;
				p->parent = old;
				old->parent = pp;
			}
		}
		else if (i == 2)
		{
			cout << "LR" << " ";
			if (p == root)
			{
				root = old->right;
				p->left = root->right;
				if (p->left != nullptr)
				{
					p->left->parent = p;
				}
				old->right = root->left;
				if (old->right != nullptr)
				{
					old->right->parent = old;
				}
				root->left = old;
				old->parent = root;
				root->right = p;
				p->parent = root;
				root->parent = NULL;
				return;
			}
			if (pp->key > p->key)
			{
				pp->left = old->right;
				old->right = pp->left->left;
				if (old->right != nullptr)
				{
					old->right->parent = old;
				}
				pp->left->left = old;
				p->left = pp->left->right;
				if (p->left != nullptr)
				{
					p->left->parent = p;
				}
				pp->left->right = p;
				p->parent = pp->left;
				pp->left->parent = pp;
				old->parent = pp->left;
			}
			else
			{
				pp->right = old->right;
				old->right = pp->right->left;
				if (old->right != nullptr)
				{
					old->right->parent = old;
				}
				p->left = pp->right->right;
				if (p->left != nullptr)
				{
					p->left->parent = p;
				}
				pp->right->left = old;
				pp->right->left->parent = pp->right;
				pp->right->right = p;
				pp->right->right->parent = pp->right;
				pp->right->parent = pp;
			}
		}
		else if (i == 3)
		{
			cout << "RR" << " ";
			if (pp->key > p->key)
			{
				pp->left = old;
			}
			else
			{
				pp->right = old;
			}
			p->right = old->left;
			if (p->right != nullptr)
			{
				p->right->parent = p;
			}
			old->left = p;
			p->parent = old;
			old->parent=pp;
		}
		else
		{
			cout << "RL" << " ";
			if (p == root)
			{
				root = old->left;
				p->right = root->left;
				if (p->right != nullptr)
				{
					p->right->parent = p;
				}
				old->left = root->right;
				if (old->left != nullptr)
				{
					old->left->parent = old;
				}
				root->right = old;
				old->parent = root;
				root->left = p;
				p->parent = root;
				root->parent = NULL;
				return;
			}
			if (pp->key > p->key)
			{
				pp->left = old->left;
				p->right = pp->left->left;
				if (p->right != nullptr)
				{
					p->right->parent = p;
				}
				old->left = old->left->right;
				if (old->left != nullptr)
				{
					old->left->parent = old;
				}
				pp->left->left = p;
				pp->left->right = old;
				pp->left->parent = pp;
				pp->left->left->parent = pp->left;
				pp->left->right->parent = pp -> left;
			}
			else
			{
				pp->left = old->left;
				old->right = pp->left->left;
				if (old->right != nullptr)
				{
					old->right->parent = old;
				}
				p->left = pp->left->right;
				if (p->left != nullptr)
				{
					p->left->parent = p;
				}
				pp->left->left = p;
				pp->left->right = old;
				pp->left->parent = pp;
				p->parent = pp->left;
				old->parent = pp->left;
			}
		}
		while (root->parent != nullptr)
		{
			root = root->parent;
		}
	}
	void insertAVL(int v)
	{
		insert(v);
		checkbalance(v);
		inorder(root);
	}
	void insert(int v)
	{
		Node* p = root;
		Node* newNode = getNode(v);
		if (root == nullptr)
		{
			root = newNode;
			return;
		}
		else
		{
			while (p!=nullptr)
			{
				if (p->key <= v)
				{
					newNode->parent = p;
					p = p->right;
				}
				else
				{
					newNode->parent = p;
					p = p->left;
				}
			}
			if (newNode->parent->key <= v)
			{
				newNode->parent->right = newNode;
			}
			else
			{
				newNode->parent->left = newNode;
			}
		}
		setHeight(root);
		setBF(root);
	}
	void del(int v)
	{
		Node* p = root;
		while (v != p->key)
		{
			if (p->key < v)
			{
				p = p->right;
			}
			else
			{
				p = p->left;
			}
		}
		if (p->left != nullptr && p->right != nullptr)
		{
			delTwoChild(p);
		}
		else if (p->left == nullptr && p->right != nullptr)
		{
			delonlyOneChild(p);
		}
		else if (p->left != nullptr && p->right == nullptr)
		{
			delonlyOneChild(p);
		}
		else
		{
			delNoChild(p);
		}
		setHeight(root);
		setBF(root);
		inorder(root);
	}
};
int main()
{
	Tree t = Tree();
	int test[38] = { 40,11,77,33,20,90,99,70,88,80,66,10,22,30,44,55,50,60,100 ,28,18, 9,5,17,6,3,1,4,2,7,8,10,12,13,14,16,15};
	for (int i = 0; i < 37; i++)
	{
		t.insertAVL(test[i]);
		cout << endl;
	}
	return 0;
}