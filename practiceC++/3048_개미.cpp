#include <iostream>
#include <string>
using namespace std;

bool chk(string all, char k)
{
	for (int i = 0; i < all.size(); i++)
	{
		if (all[i] == k)
		{
			return true;
		}
	}
	return false;
}
string sol(int t,string left,string right,string all)
{
	
	for (int i = 0; i < t; i++)
	{
		string newString = "";
		for (int j = 0; j <= all.size()-1; j++)
		{
			if (chk(left,(char)all[j])&&chk(right,(char)all[j+1]))
			{
				newString += all[j + 1];
				newString += all[j];
				j++;
			}
			else if (j == all.size() - 2)
			{
				newString =newString+all[j]+ all[j + 1];
				j++;
			}
			else
			{
				newString += all[j];
			}
		}
		all = newString;
	}
	return all;
}

int main(void)
{
	string left, right,all;
	int time;
	int lenleft, lenright;
	string cpleft="";
	cin >> lenleft >> lenright;
	cin >> left >> right;
	cin >> time;
	for (int i = 0; i < lenleft; i++)
	{
		cpleft += left[lenleft - 1 - i];
	}
	left = cpleft;
	all = left + right;
	string answer = sol(time, left, right, all);
	cout << answer << endl;
	return 0;
}