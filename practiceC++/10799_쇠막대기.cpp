#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Sol
{
private:
	string str;
	int answer = 0;
	stack <char> st;
	char ls[1000001];
public:
	void set()
	{
		cin >> str;
		for (int i = 0; i < str.size(); i++)
		{
			ls[i] = str[i];
		}
	}
	void sol()
	{
		for (int i = 0; i < str.size(); i++)
		{
			if (ls[i] == '(')
			{
				st.push('(');
			}
			else
			{
				if (ls[i - 1] == '(')
				{
					st.pop();
					answer += st.size();
				}
				else
				{
					st.pop();
					answer++;
				}
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
	s.set();
	s.sol();
	s.printAnswer();
	return 0;
}