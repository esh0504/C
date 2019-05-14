#include <iostream>
#include<cmath>
using namespace std;

int main(void)
{
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		int x[300], y[300];
		int ggokji;
		cin >> ggokji;
		for (int j = 0; j < ggokji; j++)
		{
			int x_jwa, y_jwa;
			cin >> x_jwa >> y_jwa;
			x[j] = x_jwa;
			y[j] = y_jwa;
		}
		int sum = 0;
		for (int j = 0; j < ggokji-1; j++)
		{
			sum += (x[j]+x[j+1])*(y[j+1]-y[j]);	
		}
		sum += (x[ggokji - 1] + x[0])*(y[0] - y[ggokji - 1]);

		int answer=1;
		if (sum < 0)
		{
			answer = -1;
			sum = sum * -1;
			
		}
		cout << sum <<" "<< answer << endl;

	}
}