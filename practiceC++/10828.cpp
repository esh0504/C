#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
	int TestCase;
	stack <int> stack;
	cin >> TestCase;
	for (int i = 0; i < TestCase; i++)
	{
		string str;
		cin >> str;
		if (str == "push")
		{
			int num;
			cin >> num;
			stack.push(num);
		}
		else if (str == "pop")
		{
			if (stack.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << stack.top() << endl;
				stack.pop();
			}
		}
		else if (str == "size")
		{
			cout << stack.size() << endl;
		}
		else if (str == "empty")
		{
			if (stack.empty())
			{
				cout << 1 << endl;
			}
			else
			{
				cout << 0 << endl;
			}
		}
		else if (str == "top")
		{
			if (stack.empty())
			{
				cout << -1 << endl;
			}
			else
			{
				cout << stack.top() << endl;
			}
		}

	}
}