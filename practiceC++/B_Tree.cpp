#include<stdio.h>
#include<stack>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct BTreeNode
{
	vector<BTreeNode*> childLeafs;
	vector<int> key;
} *BTreeRoot = new BTreeNode;
class BTree
{
	int max;
	friend class BTreeNode;
	stack<BTreeNode* > st;
public:
	BTree(int n)
	{
		max = n;
		BTreeNode* root = new BTreeNode;
		
	}
	BTreeNode* searchleaf(BTreeNode* tree, int key) 
	{
		while (!st.empty())
		{
			st.pop();
		}
		while (!tree->childLeafs.empty()) 
		{
			int t = 0;
			if (key < tree->key[0])
			{
				st.push(tree); 
				tree = tree->childLeafs[0];
				continue;
			}
			for (int i = 0; i < tree->key.size() -1; i++)
			{
				if (key >= tree->key[i] && key < tree->key[i + 1]) 
				{
					if (!tree->childLeafs.empty())
					{
						st.push(tree);
						tree = tree->childLeafs[i + 1];
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
				st.push(tree);
				tree = tree->childLeafs[tree->key.size()];
			}
		}
		return tree;
	}
	void BTreeSplit(stack<BTreeNode*> st, BTreeNode* tree) {
		BTreeNode* Left = new BTreeNode;
		BTreeNode* Right = new BTreeNode;
		BTreeNode* parent =new BTreeNode;
		stack <BTreeNode*> ps = st;
		if (!ps.empty())
		{
			parent = ps.top();
			ps.pop();
		}
		int middleInt = tree->key.size() / 2;
		int middle = tree->key[middleInt];
		for (int i = 0; i< middleInt; i++) 
		{
			Left->key.push_back(tree->key[i]);
		}
		for (int i = 0; i <tree->childLeafs.size(); i++)
		{
			Left->childLeafs.push_back(tree->childLeafs[i]);
			if (i > middleInt)
			{
				break;
			}
		}
		for (int i = middleInt+1; i< tree->key.size(); i++)
		{
			Right->key.push_back(tree->key[i]);
		}
		for (int i = middleInt+1; i < tree->childLeafs.size(); i++)
		{
			Right->childLeafs.push_back(tree->childLeafs[i]);
		}
		if (parent->key.size()==0) 
		{
			parent->key.push_back(middle);
			parent->childLeafs.push_back(Left);
			parent->childLeafs.push_back(Right);
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
				parent->childLeafs[n]=Left;
				parent->key.push_back(middle);
				if (n >= max-1)
				{
					parent->childLeafs[n + 1] = Right;
				}
				else
				{
					parent->childLeafs.push_back(Right);
					parent->childLeafs[n + 1] = Right;
				}
				
			}
			else 
			{
				parent->key.insert(parent->key.begin() + n, middle);
				parent->childLeafs[n] = Left;
				parent->childLeafs.insert(parent->childLeafs.begin() + n + 1, Right);
				parent->childLeafs[n + 1];
			}
			if (parent->key.size() > max) {
				BTreeSplit(ps, parent);
			}
		}
	}
	void BTreeInsert(int v) 
	{
		BTreeNode* temp = searchleaf(BTreeRoot, v);
		temp->key.push_back(v);
		sort(temp->key.begin(), temp->key.end());
		if (temp->key.size() > max) 
		{
			BTreeSplit(st, temp);
		}
	}
	void inorder(BTreeNode* root)
	{
		if (root == nullptr)
		{
			return;
		}
		for (int i = 0; i < root->key.size(); i++)
		{
			if (root->childLeafs.size()!=0)
			{
				inorder(root->childLeafs[i]);
				cout << root->key[i] << " ";
			}
			else
			{
				cout << root->key[i] << " ";
			}
		}
		if (root->childLeafs.size() != 0)
		{
			inorder(root->childLeafs[root->key.size()]);
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
	BTree t=BTree(3);
	for (int i = 0; i < 70; i++)
	{
 		t.BTreeInsert(arr[i]);
		t.inorder(BTreeRoot);
		cout << endl;
	}
}
