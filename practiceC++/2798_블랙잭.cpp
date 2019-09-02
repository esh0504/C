#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool check(int count, int numOfCards, int num, int cards[])
{
	sort(cards, cards + numOfCards);
	if (cards[1] > num)
	{
		return true;
	}
	cards[count] = cards[0] + cards[1];
	cards[0] = num + 10;
	cards[1] = num + 10;
	count++;
	return false;
}

int main(void)
{
	int numOfCards, number;
	int cards[101];
	int cnt = numOfCards;
	cin >> numOfCards >> number;
	for (int i = 0; i < numOfCards; i++)
	{
		int k;
		cin >> k;
		if (k > number)
		{
			continue;
		}
		else if (k == number)
		{
			cout << number << endl;
			return 0;
		}
		cards[i]=k;
	}
	while (check(int cnt, int numOfCards, int number, int cards[]))
	{
		check(int cnt, int numOfCards, int number, int cards[]);
	}
	sort(cards, cards + numOfCards);
	cout << cards[0] << endl;
	return 0;

}