#include <cstdlib>
#include <iostream>
#include "My2Vector.h"
My2Vector::My2Vector() :x(0), y(0)
{
}
My2Vector::My2Vector(int coordX,int coordY):x(coordX),y(coordY){}
My2Vector My2Vector::operator+(My2Vector other)
{
	My2Vector ans;
	ans.x = other.x + this->x;
	ans.y = other.y + this->y;
	return ans;
}
My2Vector My2Vector::operator*(int num)
{
	My2Vector ans;
	ans.x = num * this->x;
	ans.y = num * this->y;
	return ans;
}

ostream& operator <<(ostream &os, const My2Vector& v)
{
	os << "(" << v.x << "," << v.y << ")";
	return os;
}