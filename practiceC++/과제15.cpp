#include <iostream>
using namespace std;

int main(void)
{
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		int x11, y11, x21, y21, pan1,x12,y12,x22,y22,answer;
		cin >> x11 >> y11 >> x21 >> y21;
		cin >> x12 >> y12 >> x22 >> y22;
		if (x11==x21)
		{
			pan1 = 1;
		}
		else {
			pan1 = 0;
		}
		if (pan1 == 0)
		{
			if (x11 > x21)
			{
				int tem = x11;
				x11 = x21;
				x21 = tem;
			}
			if (y12 > y22)
			{
				int tem = y12;
				y12 = y22;
				y22 = tem;
			}
		}
		else {
			if (y11 > y21)
			{
				int tem = y11;
				y11 = y21;
				y21 = tem;
			}
			if (x12 > x22)
			{
				int tem = x12;
				x12 = x22;
				x22 = tem;
			}
		}
		if (pan1 == 0)
		{
			if (x11 < x12 && x12 < x21) 
			{
				if (y12 < y11 && y11 < y22)
				{
					answer = 1;
				}
				else if (y11 == y12 || y11 == y22)
				{
					answer = 2;
				}
				else {
					answer = 0;
				}
			}
			else if (x12 == x11 || x12 == x21)
			{
				if (y12 < y11 && y11 < y22)
				{
					answer = 2;
				}
				else if (y11 == y12 || y11 == y22)
				{
					answer = 2;
				}
				else {
					answer = 0;
				}
			}
			else
			{
				answer = 0;
			}
		}
		else {
			if (y11 < y22 && y22< y21) {
 				if (x12 < x11 && x11 < x22)
				{
					answer= 1;
				}
				else if (x12 == x11 || x22 == x11)
				{
					answer= 2;
				}
				else {
					answer= 0;
				}
			}
			else if (y11 == y22 || y22 == y21)
			{
				if (x21 < x11 && x11 < x22)
				{
					answer = 2;
				}
				else if (x21 == x11 || x22 == x11)
				{
					answer = 2;
				}
				else {
					answer = 0;
				}
			}
			else
			{
				answer = 0;
			}
			
		}
		cout << answer << endl;
			
	}
	return 0;
}