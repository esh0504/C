#include <iostream>
using namespace std;

int main(void)
{
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		int time, size;
		cin >> size >> time;
		int bacteria[10000];
		int bacteria_copy[10000];
		for (int j = 0; j < size; j++)
		{
			int numOfbacteria;
			cin >> numOfbacteria;
			bacteria[j] = numOfbacteria;
			bacteria_copy[j] = numOfbacteria;
		}
		for (int k = 0; k < time; k++)
		{
			for (int l = 0; l < size; l++)
			{
				if (l == 0)
				{
					if (bacteria[l + 1] < 3 || bacteria[l+1]>7) {
						bacteria_copy[l] -= 1;
					}
					else if(bacteria[l + 1] == 3) {
						continue;
					}
					else {
						bacteria_copy[l] += 1;
					}
				}
				else if (l == size - 1)
				{
					if (bacteria[l - 1] < 3 || bacteria[l - 1]>7) {
						bacteria_copy[l] -= 1;
					}
					else if (bacteria[l - 1] == 3) {
						continue;
					}
					else {
						bacteria_copy[l] += 1;
					}
				}
				else
				{
					if (bacteria[l - 1] +bacteria[l + 1] < 3 || bacteria[l - 1]+bacteria[l + 1]>7) {
						bacteria_copy[l] -= 1;
					}
					else if (bacteria[l - 1]+bacteria[l + 1] == 3) {
						continue;
					}
					else {
						bacteria_copy[l] += 1;
					}
				}
			}
			for (int p = 0; p < size; p++)
			{
				if (bacteria_copy[p] > 9)
				{
					bacteria_copy[p] = 9;
				}
				if (bacteria_copy[p] < 0)
				{
					bacteria_copy[p] = 0;
				}
				bacteria[p] = bacteria_copy[p];
			}

		}
		for (int o = 0; o < size; o++)
		{
			cout << bacteria[o] << " ";
		}
		cout << endl;
		
	}
}