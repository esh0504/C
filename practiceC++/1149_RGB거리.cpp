#include <iostream>
#include<cstring>
using namespace std;

class Sol
{
private:
	
	int numOfHouse;
	int **rgb;
	int r;
	int red[1001];
	int green[1001];
	int blue[1001];

public:
	void set()
	{

		cin >> numOfHouse;
		rgb = new int*[numOfHouse];
		for (int i = 0; i < numOfHouse; i++)
		{
			rgb[i] = new int[3];
			memset(rgb[i], 0, sizeof(rgb[i]));
			for (int h = 0; h < 3; h++)
			{
				cin >> r;
				rgb[i][h] = r;
			}
		}
		red[1] = rgb[0][0];
		green[1] = rgb[0][1];
		blue[1] = rgb[0][2];
	}
	int min(int a, int b)
	{
		return a > b ? b : a;
	}
	void sol()
	{
		for (int i = 2; i <= numOfHouse; i++)
		{
			red[i] = min(green[i - 1] + this->rgb[i - 1][0], blue[i - 1] + this->rgb[i - 1][0]);
			green[i] = min(blue[i - 1] + this->rgb[i - 1][1], red[i - 1] + this->rgb[i - 1][1]);
			blue[i] = min(green[i - 1] + this->rgb[i - 1][2], red[i - 1] + this->rgb[i - 1][2]);
		}
	}
	void print()
	{
		int answer;
		if (red[numOfHouse] > blue[numOfHouse])
		{
			if (blue[numOfHouse] > green[numOfHouse])
			{
				answer = green[numOfHouse];
			}
			else
			{
				answer = blue[numOfHouse];
			}
		}
		else
		{
			if (red[numOfHouse] > green[numOfHouse])
			{
				answer = green[numOfHouse];
			}
			else
			{
				answer = red[numOfHouse];
			}
		}
		cout << answer << endl;
	}
};

int main(void)
{
	Sol s;
	s.set();
	s.sol();
	s.print();
	return 0;
}