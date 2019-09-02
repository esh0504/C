#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

class Solution
{
private:
	int n = 0;
	int arr[1000001] = { 0 };
public:
	void setNum()
	{
		cin >> n;
	}
	void solution()
	{
		arr[1] = 0;
		for (int i = 2; i <= n; i++)
		{
			arr[i] = arr[i - 1] + 1;
			if (i % 3 == 0)
			{
				arr[i] = min(arr[i], arr[i / 3] + 1);
			}
			if (i % 2 == 0)
			{
				arr[i] = min(arr[i], arr[i / 2] + 1);
			}
		}
		
	}
	void printAnswer()
	{
		cout << arr[n] << endl;
	}
};
int main(void)
{
	Solution sol;
	sol.setNum();
	sol.solution();
	sol.printAnswer();
	return 0;
}