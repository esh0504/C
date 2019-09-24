#include <iostream>

using namespace std;

class Sol
{
private:
	int x, y,tx,ty;
public:
	void setMap()
	{
		cin >> x >> y;
		cin >> tx >> ty;
	}
	long long factorial(int x)
	{
		int answer = 1;
		if (x == 0)
		{
			return answer;
		}
		for (int i = 2; i <= x; i++)
		{
			answer *= i;
			if (answer > 1000007)
			{
				answer = answer % 1000007;
			}
		}
		return answer%1000007;
	}
	long long findway(int dx,int dy,int x,int y)
	{
		return (factorial((dy - y) + (dx - x)) /( factorial(dy - y)*factorial(dx - x)))%1000007;
	}
	void printAnswer()
	{
		cout << (findway(x, y, tx, ty)% 1000007 )*findway(tx, ty, 1, 1)%1000007 << endl;
	}
};
int main(void)
{
	Sol s;
	s.setMap();
	s.printAnswer();
	return 0;
}