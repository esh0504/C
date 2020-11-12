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
	int min;
	friend class BNode;
	vector<int>::iterator iter;
	stack<BNode* > parentStack;
public:
	BTree(int n)
	{
		max = n;
		min = n / 2 - 1;
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
			int i;
			for (i = 0; i < tree->key.size()-1 ; i++)
			{
				if (key == tree->key[i])
				{
					return tree;
				}
				if (key > tree->key[i] && key <= tree->key[i + 1]) 
				{
					if (tree->key[i + 1] == key)
					{
						return tree;
					}
					if (!tree->childPointer.empty())
					{
						parentStack.push(tree);
						tree = tree->childPointer[i + 1];
						t = 1;
						break;
					}
				}
			}
			if (i == 0 && key == tree->key[i])
			{
				return tree;
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
		if (tree->childPointer.size() != 0)
		{
			for (int i = 0; i <= mid; i++)
			{
				Left->childPointer.push_back(tree->childPointer[i]);
			}
			for (int i = mid+1; i < tree->childPointer.size(); i++)
			{
				Right->childPointer.push_back(tree->childPointer[i]);
			}
		}
		
		for (int i = mid+1; i< tree->key.size(); i++)
		{
			Right->key.push_back(tree->key[i]);
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
			int ew = Left->key.size()-1;
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
		if (tmp->childPointer.size() != 0)
		{
			if (tmp->childPointer[0]->key.size() == 0)
			{
				tmp->childPointer.clear();
			}
		}
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
		if (parentStack.empty()&&nd->childPointer.size()==0)
		{
			vector<int>::iterator iterKey = nd->key.begin();
			for (int i = 0; i < nd->key.size(); i++)
			{
				if (nd->key[i] == v)
				{
					nd->key.erase(iterKey);
					return;
				}
				iterKey++;
			}
			return;
		}
		BNode* parent = parentStack.top();
		int i;
		for (i = 0; parent->key[i] < v; i++)
		{
			if (i == parent->key.size()-1)
			{
				i++;
				break;
			}
		}
		int j;
		vector<int>::iterator iterKey = nd->key.begin();
		for (j = 0; j < nd->key.size(); j++)
		{
			if (nd->key[j] == v)
			{
				nd->key.erase(iterKey);
				break;
			}
			iterKey++;
		}
 		while (!parentStack.empty())
		{
			parent=parentStack.top();
			parentStack.pop();
			check(parent);
		}
	}
	void check(BNode* p)
	{
		for (int i = 0; i < p->childPointer.size(); i++)
		{
			if (p->childPointer[i]->key.size() <= min)
			{
				BNode* Left;
				BNode* Right;
				if (i == 0)
				{
					Right = p->childPointer[i+1];
					if (Right->key.size() > min+1)
					{
						rightArrange(p, i);
					}
					else
					{
						rightMerge(p, i);
					}
				}
				else if (i == p->childPointer.size() - 1)
				{
					Left = p->childPointer[i - 1];
					if (Left->key.size() > min+1)
					{
						leftArrange(p, i);
					}
					else
					{
						leftMerge(p,i);
					}
				}
				else
				{
					Left = p->childPointer[i - 1];
					Right = p->childPointer[i + 1];
					if (Left->key.size() > min+1)
					{
						leftArrange(p, i);
					}
					else
					{
						if (Left->key.size() >= Right->key.size())
						{
							leftMerge(p, i);
						}
						else
						{
							if (Right->key.size() > min + 1)
							{
								rightArrange(p, i);
							}
							else
							{
								rightMerge(p, i);
							}
						}
					}
				}
			}
			
		}
		return;
	}
	void rightArrange(BNode* p,int i)
	{
		BNode* nd = p->childPointer[i];
		BNode* Right = p->childPointer[i + 1];
		int tmp=Right->key[0];
		int tmp2 = p->key[i];
		nd->key.push_back(tmp2);
		p->key[i] = tmp;
		vector<int>::iterator iterKey = Right->key.begin();
		Right->key.erase(iterKey);
		if (Right->childPointer.size() != 0)
		{
			vector<BNode*>::iterator iterPointer = Right->childPointer.begin();
			nd->childPointer.push_back(Right->childPointer[0]);
			Right->childPointer.erase(iterPointer);
		}
	}
	void leftArrange(BNode* p,int i)
	{
		BNode* nd = p->childPointer[i];
		BNode* Left = p->childPointer[i - 1];
		int tmp = Left->key.back();
		int tmp2 = p->key[i-1];
		p->key[i - 1] = tmp;
		vector<int>::iterator iterKey = nd->key.begin();
		nd->key.insert(iterKey, tmp2);
		Left->key.pop_back();
		if (Left->childPointer.size() != 0)
		{
			BNode* LeftChild=Left->childPointer.back();
			vector<BNode*>::iterator iterPointer = nd->childPointer.begin();
			nd->childPointer.insert(iterPointer, LeftChild);
			Left->childPointer.pop_back();
		}
	}
	void rightMerge(BNode* p,int i)
	{
		BNode* Right = p->childPointer[i + 1];
		BNode* nd = p->childPointer[i];
		nd->key.push_back(p->key[i]);
		for (int j = 0; j < Right->key.size(); j++)
		{
			nd->key.push_back(Right->key[j]);
		}
		vector<int>::iterator iterKey = p->key.begin();
		vector<BNode*>::iterator iterPointer = p->childPointer.begin();
		for (int j = 0; j < i; j++)
		{
			iterKey++;
			iterPointer++;
		}
		iterPointer++;
		p->childPointer.erase(iterPointer);
		p->key.erase(iterKey);
		if (Right->childPointer.size() != 0)
		{
			for (int j = 0; j < Right->childPointer.size(); j++)
			{
				nd->childPointer.push_back(Right->childPointer[j]);
			}
		}
		if (BTreeRoot->key.size() == 0)
		{
			BTreeRoot = nd;
		}
	}
	void leftMerge(BNode* p,int i)
	{
		BNode* nd = p->childPointer[i];
		BNode* Left = p->childPointer[i - 1];
		vector<int>::iterator iterKey = p->key.begin();
		vector<BNode*>::iterator iterPointer = p->childPointer.begin();
		Left->key.push_back(p->key[i-1]);
		for (int j = 0; j < nd->key.size(); j++)
		{
			Left->key.push_back(nd->key[j]);
		}
		for (int j = 0; j < i; j++)
		{
			iterKey++;
			iterPointer++;
		}
		iterKey--;
		iterPointer--;
		p->key.erase(iterKey);
		p->childPointer.erase(iterPointer);
		if (nd->childPointer.size() != 0)
		{
			for (int j = 0; j < nd->childPointer.size(); j++)
			{
				Left->childPointer.push_back(nd->childPointer[j]);
			}
		}
		nd = Left;
		p->childPointer[i-1] = nd;
		
		if (BTreeRoot->key.size() == 0)
		{
			BTreeRoot = nd;
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
		53, 57, 52, 56, 83, 81, 82, 84, 75, 89,
	};
	int delarr[70] =
	{
		66,10,22,30,44,55,50,60,100,28,
		18,9,5,17,6,3,1,4,2,7,
		8,73,12,13,14,16,15,25,24,28,
		40,11,77,33,20,90,99,70,88,80,
		45,49,42,43,41,47,48,46,63,68,
		53,57,52,56,83,81,82,84,75,89,
		61,62,64,69,67,65,54,59,58,51
	};
	BTree mis3 = BTree(2);
	BTree mis4 = BTree(3);
	for (int i = 0; i < 70; i++)
	{
 		mis3.Insert(arr[i]);
		mis4.Insert(arr[i]);
	}
	for (int i = 0; i < 70; i++)
	{
 		mis3.Del(delarr[i]);
		mis3.inorder(BTreeRoot);
		cout << endl;
	}
	for (int i = 0; i < 70; i++)
	{
		mis4.Del(delarr[i]);
		mis4.inorder(BTreeRoot);
		cout << endl;
	}

	
}
