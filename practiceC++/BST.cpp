#include <iostream>
using namespace std;

class Node
{
	friend class Tree;
private:
	int key;
	Node* left = nullptr;
	Node* right = nullptr;

	Node(int v)
	{
		key = v;
	}
};

class Tree
{
private:
	Node* root;
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
	
	Node* getNode(int v)
	{
		return new Node(v);
	}

	void insert(int v)
	{
		Node* p = root;
		Node* newNode = getNode(v);
		if (root == nullptr)
		{
			root = newNode;
			inorder(root);
			return;
		}
		else
		{
			while (p != nullptr)
			{
				if (p->key <= v)
				{
					if (p->right == nullptr) {
						p->right = newNode;
						inorder(root);
						return;
					}
					p = p->right;
				}
				else
				{
					if (p->left == nullptr) {
						p->left = newNode;
						inorder(root);
						return;
					}
					p = p->left;
				}
			}
		}
	}

	int  maxNum(int a, int b) {
		return a > b ? a : b;
	}

	int height(Node* n) {
		if (n == nullptr) {
			return 0;
		}
		int leftHeight = height(n->left) + 1;
		int rightHeight = height(n->right) + 1;
		return maxNum(leftHeight, rightHeight);
	}

	Node* getroot() {
		return root;
	}

	int noNodes(Node* n,int num) {
		int left=0;
		int right=0;
		if (n != nullptr)
		{
			left=noNodes(n->left, num+1);
			right=noNodes(n->right, num + 1);
		}

		return left + right;
	}

	void del(int v)
	{
		Node* p = root;
		Node* parent = nullptr;
		while (p->key!=v) {
			if (p->key < v) {
				parent = p;
				p = p->right;
			}
			else {
				parent = p;
				p = p->left;
			}
		}
		if (noNodes(p,0)==1) {
			root = nullptr;
			return;
		}

		else if (root->key == v) {
			int tmpkey = p->key;
			if (root->left == nullptr && root->right == nullptr) {
				root = NULL;
			}
			
			else if (height(p->left) > height(p->right)) {
				p->key = maxNode(p->left)->key;
				maxNode(p->left)->key = tmpkey;
				Node* tmpNode = root->left;
				Node* tmpParentNode = root;
				while (tmpNode->key != maxNode(p->left)->key) {
					tmpParentNode = tmpNode;
					tmpNode = tmpNode->right;
				}
				if (tmpNode->right == nullptr) {
					tmpParentNode->left = nullptr;
				}
				else {
					tmpParentNode->left=tmpNode->right;
				}
			}
			else if (height(p->left) < height(p->right)) {
				p->key = minNode(p->right)->key;
				minNode(p->right)->key = tmpkey;
				Node* tmpNode = p->right;
				Node* tmpParentNode = p;
				while (tmpNode->key != minNode(p->right)->key) {
					tmpParentNode = tmpNode;
					tmpNode = tmpNode->left;
				}
				if (tmpNode->right != nullptr) {
					if (tmpNode->right->key > tmpParentNode->key) {
						tmpParentNode->right = tmpNode->right;
					}
					else {
						tmpParentNode->left = tmpNode->right;
					}
				}
				else {
					tmpParentNode->left = nullptr;
					if (root->left==nullptr && tmpNode->left == nullptr && tmpNode->right == nullptr) {
						tmpParentNode->right = nullptr;
					}
				}
			}
			else {
				if (noNodes(p->left, 0) > noNodes(p->right, 0)) {
					p->key = maxNode(p->left)->key;
					maxNode(p->left)->key = tmpkey;
					Node* tmpNode = root->left;
					Node* tmpParentNode = root;
					while (tmpNode->key != maxNode(p->left)->key) {
						tmpParentNode = tmpNode;
						tmpNode = tmpNode->right;
					}
					tmpParentNode->right = nullptr;
				}
				else {
					p->key = minNode(p->right)->key;
					minNode(p->left)->key = tmpkey;
					Node* tmpNode = root->right;
					Node* tmpParentNode = root;
					while (tmpNode->key != minNode(p->right)->key) {
						tmpParentNode = tmpNode;
						tmpNode = tmpNode->left;
					}
					tmpParentNode->left = nullptr;
				}
			}
		}
		
		else if (p->left == nullptr && p->right == nullptr) {
			if (parent->key < v) {
				parent->right = nullptr;
			}
			else {
				parent->left = nullptr;
			}
		}
		else if (p->left != nullptr && p->right == nullptr) {
			if (parent->key < v) {
				parent->right = p->left;
			}
			else {
				parent->left = p->left;
			}
		}
		else if (p->left == NULL && p->right != nullptr) {
			if (parent->key < v) {
				parent->right = p->right;
			}
			else {
				parent->left = p->right;
			}
		}
		else {
			int tmpkey = p->key;
			if (height(p->left) > height(p->right)) {
				p->key = maxNode(p->left)->key;
				maxNode(p->left)->key = tmpkey;
				Node* tmpNode = p->left;
				Node* tmpParentNode = p;
				while (tmpNode->key != maxNode(p->left)->key) {
					tmpParentNode = tmpNode;
					tmpNode = tmpNode->right;
				}
				if (tmpNode->left != nullptr) {
					tmpParentNode->left = tmpNode->left;
				}
				else {
					tmpParentNode->right = tmpNode->left;
				}
				
			}
			else if (height(p->left) < height(p->right)) {
				p->key = minNode(p->right)->key;
				minNode(p->right)->key = tmpkey;
				Node* tmpNode = p->right;
				Node* tmpParentNode = p;
				while (tmpNode->key != minNode(p->right)->key) {
					tmpParentNode = tmpNode;
					tmpNode = tmpNode->left;
				}
				tmpParentNode->left = nullptr;
			}
			else {
				if (noNodes(p->left, 0) > noNodes(p->right, 0)) {
					p->key = maxNode(p->left)->key;
					maxNode(p->left)->key = tmpkey;
					Node* tmpNode = p->left;
					Node* tmpParentNode = p;
					while (tmpNode->key != maxNode(p->left)->key) {
						tmpParentNode = tmpNode;
						tmpNode = tmpNode->right;
					}
					tmpParentNode->right = nullptr;
				}
				else {
					p->key = minNode(p->right)->key;
					minNode(p->right)->key = tmpkey;
					Node* tmpNode = p->right;
					Node* tmpParentNode = p;
					while (tmpNode->key != minNode(p->right)->key) {
						tmpParentNode = tmpNode;
						tmpNode = tmpNode->left;
					}
					tmpParentNode->right = nullptr;
				}
			}
		}
		inorder(root);
	}
};
int main()
{
	Tree t = Tree();
	int test[20] = { 25,500,33,49,17,403,29,105,39,66,305,44,19,441,390,12,81,50,100,999 };
	for (int i = 0; i < 20; i++)
	{
		t.insert(test[i]);
		cout << endl;
	}
	for (int i = 0; i < 20; i++) {
		t.del(test[i]);
		cout << endl;
	}

	Tree t2 = Tree();
	for (int i = 0; i < 20; i++)
	{
		t2.insert(test[i]);
		cout << endl;
	}
	for (int i = 19; i >= 0; i--) {
		t2.del(test[i]);
		cout << endl;
	}

	return 0;
}