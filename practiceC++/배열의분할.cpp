#include <iostream>
using namespace std;
const int SIZE = 10;
void rotateArray(int array[], int size);
void printArray(int array[], int size);
#include<vector>

int main(void)
{
	int t;
	unsigned int size;
	int array[SIZE];
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> size;
		for (int j = 0; j < size; j++)
		{
			cin >> array[j];
		}
		rotateArray(array, size);
		printArray(array, size);
	}
	return 0;
}

void rotateArray(int array[], int size)
{
	vector<int> vecodd;
	vector<int> vec;
	int odd = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] % 2 == 1)
		{
			odd++;
			vecodd.push_back(array[i]);
		}
		else
		{
			vec.push_back(array[i]);
		}
	}
	
	for (int i = 0; i < vecodd.size(); i++)
	{
		array[i] = vecodd[i];
	}
	for (int i = 0; i < vec.size(); i++)
	{
		array[odd + i] = vec[i];
	}
	
}

void printArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}