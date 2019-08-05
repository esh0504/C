#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int main(void)
{
	int testnum;
	vector <int>art;
	cin >> testnum;
	for (int i = 0; i < testnum; i++)
	{
		int e;
		cin >> e;
		art.push_back(e);
	}
	sort(art.begin(), art.end());
	cout << art[0] << " " << art[testnum - 1];
}