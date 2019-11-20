#include<stdio.h>
#include<stack>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct BNode
{
	vector<BNode*> childPointer;
	vector<int> key;
} *BTreeRoot = new BNode;
class BTree
{
	int max;
	friend class BNode;
	stack<BNode* > parentStack;
public:
	BTree(int n)
	{
		max = n;
		BNode* root = new BNode;
		
	}
	BNode* search(BNode* tree, int key) 
	{
		while (!parentStack.empty())
		{
			parentStack.pop();
		}
		while (!tree->childPointer.empty()) 
		{
			int t = 0;
			if (key < tree->key[0])
			{
				parentStack.push(tree);
				tree = tree->childPointer[0];
				continue;
			}
			for (int i = 0; i < tree->key.size() -1; i++)
			{
				if (key == tree->key[i])
				{
					return tree;
				}
				if (key > tree->key[i] && key < tree->key[i + 1]) 
				{
					if (!tree->childPointer.empty())
					{
						parentStack.push(tree);
						tree = tree->childPointer[i + 1];
						t = 1;
						break;
					}
				}
			}
			if (t == 1)
			{
				continue;
			}
			if (key > tree->key[tree->key.size() - 1]) {
				parentStack.push(tree);
				tree = tree->childPointer[tree->key.size()];
			}
		}
		return tree;
	}
	void childSplit(stack<BNode*> st, BNode* tree) {
		BNode* Left = new BNode;
		BNode* Right = new BNode;
		BNode* parent =new BNode;
		stack <BNode*> ps = st;
		if (!ps.empty())
		{
			parent = ps.top();
			ps.pop();
		}
		int mid = tree->key.size() / 2;
		int middle = tree->key[mid];
		for (int i = 0; i< mid; i++) 
		{
			Left->key.push_back(tree->key[i]);
		}
		for (int i = 0; i <tree->childPointer.size(); i++)
		{
			Left->childPointer.push_back(tree->childPointer[i]);
			if (i > mid)
			{
				break;
			}
		}
		for (int i = mid+1; i< tree->key.size(); i++)
		{
			Right->key.push_back(tree->key[i]);
		}
		for (int i = mid+1; i < tree->childPointer.size(); i++)
		{
			Right->childPointer.push_back(tree->childPointer[i]);
		}
		if (parent->key.size()==0) 
		{
			parent->key.push_back(middle);
			parent->childPointer.push_back(Left);
			parent->childPointer.push_back(Right);
			BTreeRoot = parent;
		}
		else 
		{
			int n = 0;
			if (middle < parent->key[0])
			{
				n = 0;
			}
			for (int i = 0; i < parent->key.size() - 1; i++) 
			{
				if (middle >= parent->key[i] && middle < parent->key[i + 1]) 
				{
					n = i + 1;
				}
			}
			if (middle> parent->key[parent->key.size() - 1])
			{
				n = parent->key.size();
			}
			if (n == parent->key.size()) 
			{
				parent->childPointer[n]=Left;
				parent->key.push_back(middle);
				if (n >= max-1)
				{
					parent->childPointer.push_back(Right);
					parent->childPointer[n + 1] = Right;
				}
				else
				{
					parent->childPointer.push_back(Right);
					parent->childPointer[n + 1] = Right;
				}
				
			}
			else 
			{
				parent->key.insert(parent->key.begin() + n, middle);
				parent->childPointer[n] = Left;
				parent->childPointer.insert(parent->childPointer.begin() + n + 1, Right);
				parent->childPointer[n + 1];
			}
			if (parent->key.size() > max) {
				childSplit(ps, parent);
			}
		}
	}
	void Insert(int v) 
	{
		BNode* tmp = search(BTreeRoot, v);
		for (int i = 0; i < tmp->key.size(); i++)
		{
			if (v == tmp->key[i])
			{
				return;
			}
		}
		tmp->key.push_back(v);
		sort(tmp->key.begin(), tmp->key.end());
		if (tmp->key.size() > max) 
		{
			childSplit(parentStack, tmp);
		}
	}
	void Del(int v)
	{
		BNode* tmp = search(BTreeRoot, v);
		for (int i = 0; i < tmp->key.size(); i++)
		{
			if (tmp->key[i] == v)
			{
				break;
			}
			if (i == tmp->key.size() - 1)
			{
				return;
			}
		}
		if (tmp->childPointer.empty())
		{
			delLeaf(tmp,v);
		}
		else
		{
			delIn(tmp, v);
		}
	}
	void rearrange(BNode* nd,int t)
	{

	}
	void delIn(BNode* nd, int v)
	{
		BNode* trailNode;
		BNode* delNode = nd;
		int tmpi;
		int tmp;
		for (int i = 0; i < nd->key.size(); i++)
		{
			if (nd->key[i] == v)
			{
				tmpi = i;
				trailNode = nd->childPointer[i + 1];
				parentStack.push(nd);
				while (!trailNode->childPointer.empty())
				{
					parentStack.push(trailNode);
					trailNode = trailNode->childPointer[0];
				}
				break;
			}
		}
		tmp = nd->key[tmpi];
		nd->key[tmpi] = trailNode->key[0];
		trailNode->key[0] = tmp;
		delLeaf(trailNode, v);
	}
	void delLeaf(BNode* nd, int v)
	{
		BNode* tmp;
		BNode* parent = parentStack.top();
		parentStack.pop();
		if (nd->key.size() > (max / 2))
		{
			for (int i = 1; i < nd->key.size(); i++)
			{
				tmp->key.push_back(nd->key[i]);
			}
			parent->childPointer[0] = tmp;
			return;
		}
		else
		{

		}
	}
	void inorder(BNode* root)
	{
		if (root == nullptr)
		{
			return;
		}
		for (int i = 0; i < root->key.size(); i++)
		{
			if (root->childPointer.size()!=0)
			{
				inorder(root->childPointer[i]);
				cout << root->key[i] << " ";
			}
			else
			{
				cout << root->key[i] << " ";
			}
		}
		if (root->childPointer.size() != 0)
		{
			inorder(root->childPointer[root->key.size()]);
		}	
	}
};



int main(void)
{
	int arr[70] = 
	{
		40, 11, 77, 33, 20, 90, 99, 70, 88, 80,
		66, 10, 22, 30, 44, 55, 50, 60, 100, 28,
		18, 9, 5, 17, 6, 3, 1, 4, 2, 7,  8,
		73, 12, 13, 14, 16, 15, 25, 24, 28,
		45, 49, 42, 43, 41, 47, 48, 46, 63, 68,
		61, 62, 64, 69, 67, 65, 54, 59, 58, 51,
		53, 57, 52, 56, 83, 81, 82, 84, 75, 89
	};
	BTree t=BTree(4);
	for (int i = 0; i < 70; i++)
	{
 		t.Insert(arr[i]);
		t.inorder(BTreeRoot);
		cout << endl;
	}
}
