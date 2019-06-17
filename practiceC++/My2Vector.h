#pragma once
#ifndef _MY_2Vector_H_
#define _MY_2Vector_H_
#include <iostream>

#include <iostream>

using namespace std;
class My2Vector
{
	
public:
	My2Vector();
	My2Vector(int coordX, int coordY);
	My2Vector operator+(My2Vector other);
	My2Vector operator*(int num);
	friend ostream& operator <<(ostream& os, const My2Vector& v);
private:
	int x, y;
};

#endif // !
