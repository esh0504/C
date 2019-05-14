#include <iostream>
using namespace std;

int main(void)
{
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		int x1, x2, x3, y1, y2, y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		int area = (x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1);
		int cnt = 0;
		if (area < 0)
		{
			cnt = -1;
			area *= -1;
		}
		else if (area > 0)
		{
			cnt = 1;
		}
		cout << area << " " << cnt << endl;
	}
	return 0;
}