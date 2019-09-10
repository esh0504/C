#include <iostream>
#include <algorithm>
using namespace std;

class Sol 
{
private:
	int numOfPerson;
	int answer = 0;
	int sum = 0;
	int d[1001];
public:
	void Set()
	{
		cin >> numOfPerson;
		for (int i = 0; i < numOfPerson; i++)
		{
			int n;
			cin >> n;
			d[i] = n;
		}
		sort(d, d + numOfPerson);
	}
	void solution()
	{
		for (int i = 0; i < numOfPerson; i++)
		{
			sum += d[i];
			answer += sum;
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
	s.Set();
	s.solution();
	s.printAnswer();
	return 0;
}