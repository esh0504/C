#include<iostream>
#include<string>
using namespace std;
#include<string>

int main(void)
{
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		string num;
		string answer="";
		string answer2 = "";
		
		cin >> num;
		for (int i = num.size()-1; i>=0; i--)
		{
			answer += num[i];
		}
		int count = 0;
		for (int i =0; i<num.size(); i++)
		{
			if (answer[i] == '0') {
				count += 1;
				continue;
			}
			break;
		}
		for (int i = count; i < num.size(); i++)
		{
			answer2 += answer[i];
		}

		cout << answer2 << endl;
	}
}