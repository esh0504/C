#include <iostream>

using namespace std;

class Sol
{
private:
	int n,km;
	int answer;
	int count = 0;
	int arr[1001] = { 0 };
public:
	void setNum()
	{
		cin >> n>>km;
		for (int i = 2; i <= n; i++)
		{
			arr[i] = i;
		}
	}
	void sol()
	{
		for (int i = 2; i <= n; i++)
		{
			if (answer != 0)
			{
				break;
			}
			if (count == km)
			{
				break;
			}
			if (arr[i] == 0)
			{
				continue;
			}
			for (int k = 1; k <= n;  k++)
			{
				int sum = k * i;
				if (sum > n)
				{
					break;
				}
				if (arr[sum] == 0)
				{
					continue;
				}
				count++;
				if (count == km)
				{
					answer = arr[sum];
					break;
				}
				arr[sum] = 0;
			}
		}	
	}
	void printAnswer()
	{
		cout << answer << endl;
	}
};

int main(void)
{
	Sol s;
	s.setNum();
	s.sol();
	s.printAnswer();
	return 0;
}