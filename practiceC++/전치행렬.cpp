#include <iostream>
using namespace std;
const int SIZE = 10;
void transposeSquareMatrix(int squreMatrix[][SIZE], int size);
void printSquareMatrix(int squareMatrix[][SIZE], int size);

int main(void)
{
	int t;
	unsigned int size;
	int squareMatrix[SIZE][SIZE];
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> size;
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++)
			{
				cin >> squareMatrix[j][k];
			}
		}
		transposeSquareMatrix(squareMatrix, size);
		printSquareMatrix(squareMatrix, size);
	}
	return 0;
}

void transposeSquareMatrix(int squareMatrix[][SIZE],int size)
{
	int tmp, tmp2;
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			tmp = squareMatrix[i][j];
			tmp2 = squareMatrix[j][i];
			squareMatrix[j][i] = tmp;
			squareMatrix[i][j] = tmp2;
		}
	}
}

void printSquareMatrix(int squareMatrix[][SIZE],int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << squareMatrix[i][j] << " ";
		}
		cout << endl;
	}
}
