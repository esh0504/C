#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

string input;
stack<char> s;
int main(void)

{
	cin >> input;
	long long result = 0;
	int temp = 1;
	bool impossible = false;
	for (int i = 0; i < input.size(); i++)
	{
		if (!check(input))
		{
			impossible = true;
			break;
		}
		if (input[i] == '(')
		{
			temp *= 2;
			s.push('(');
		}
		else if (input[i] == '[')
		{
			temp *= 3;
			s.push('[');
		}
		else if (input[i] == ')')
		{
			if (input[i - 1] == '(')
				result += temp;
			s.pop();
			temp /= 2;
		}
		else if (input[i] == ']')
		{
			if (input[i - 1] == '[')
				result += temp;
			s.pop();
			temp /= 3;
		}
	}
	if (impossible || !s.empty())
		cout << 0 << "\n";
	else
		cout << result << "\n";
	return 0;
}

bool check(string str)
{
	stack<char> stc;
	stack<char> stk;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ')')
		{
			if (stc.empty())
			{
				return false;
			}
			stc.pop();
		}
		else if (str[i] == '(')
		{
			stc.push('c');
		}
		if (str[i] == ']')
		{
			if (stk.empty())
			{
				return false;
			}
			stk.pop();
		}
		else if (str[i] == '[')
		{
			stk.push('d');
		}
	}
	return true;
}