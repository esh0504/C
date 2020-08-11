#include <iostream>
#include <vector>
using namespace std;

class CCTV
{
private:
	vector <vector<int>> Copy_map;
	int n;
	int size = 0;
public:
	CCTV(vector<vector<int>> map)
	{
		Copy_map = map;
	}
	void one_up(int row,int col)
	{
		for (int i = 0; i < row; i++)
		{
			if (Copy_map[i][col] == 0)
			{
				Copy_map[i][col] = 100;
			}
			if (Copy_map[i][col] == 6)
			{
				break;
			}
		}
	}
	void one_down(int row, int col)
	{
		for (int i = row; i < Copy_map.size(); i++)
		{
			if (Copy_map[i][col] == 0)
			{
				Copy_map[i][col] = 100;
			}
			if (Copy_map[i][col] == 6)
			{
				break;
			}
		}
	}
	void one_left(int row, int col)
	{
		for (int i = 0; i < col; i++)
		{
			if (Copy_map[row][i] == 0)
			{
				Copy_map[row][i] = 100;
			}
			if(Copy_map[])
		}
	}
};