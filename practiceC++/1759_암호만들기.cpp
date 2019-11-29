#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Sol
{
private:
	int n, num;
	vector<char> v;
public:
	void set()
	{
		cin >> n >> num;
		for (int i = 0; i < num; i++)
		{
			char c;
			cin >> c;
			v.push_back(c);
		}
		sort(v.begin(), v.end());
	}
	void sol(int pos,string answer,int ja,int mo)
	{
		if (answer.size() == n)
		{
			if (ja < 2 || mo < 1)
			{
				return;
			}
			cout << answer << endl;
			return;
		}
		for (int i = pos; i < num; i++)
		{
			if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u')
			{
				sol(i + 1, answer + v[i], ja, mo + 1);
			}
			else
			{
				sol(i + 1, answer + v[i], ja + 1, mo);
			}	
		}
	}
};
int main(void)
{
	Sol s;
	s.set();
	s.sol(0, "", 0, 0);
	return 0;
}