#pragma once
#include<vector>
#include<cstdlib>
#include<iostream>
using namespace std;
class GameLogic
{
	int step;
	int push;
	int **map;
	vector< pair<int, int> > destination;
	int R;
	int C;
	int numDestination;
public:
	GameLogic(int **map, int R, int C);
	void Move(int direction);
	bool isGameclear();
	void printMap();
	int getStep();
	int getPush();
	bool isMap(int i, int j);
};
