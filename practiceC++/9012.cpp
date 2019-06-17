#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
	int TC;
	cin >> TC;
	for (int i = 0; i < TC; i++)
	{
		string str;
		cin >> str;
		stack<char> st;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == ')')
			{
				if (st.empty())
				{
					st.push('c');
					break;
				}
				st.pop();
			}
			else if (str[i] == '(')
			{
				st.push('c');
			}
		}
		if (!st.empty())
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
		}
	}
}