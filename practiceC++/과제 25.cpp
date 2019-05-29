#ifndef _MYRATIONAL_H_
#define _MYRATIONAL_H_
#include <iostream>
#include <fstream>
#include <cstdlib>
#include<algorithm>
using namespace std;
class myRational
{
public:
	myRational(long num = 0, long den = 1);//완
	myRational(const myRational& rat);//완
	long getNumerator() const;//완
	long getDenominator() const;//완
	myRational reciprocal() const;//완
	myRational operator+(const myRational& rat) const;//완
	myRational operator*(const myRational& rat) const;//완
	myRational operator/(const myRational& rat) const;//완
	myRational operator-(const myRational& rat) const;//완
	myRational operator+(int num) const;//완
	myRational operator*(int num) const;//완
	myRational operator-(int num) const;//완
	myRational operator/(int num) const;//완
	myRational operator++(int);//완
	myRational operator--(int);//완
	myRational operator++();//완
	myRational operator--();//완
	myRational operator-();//완
	bool operator >(const myRational& rat) const;//완
	bool operator >=(const myRational& rat) const;//완
	bool operator <(const myRational& rat) const;//완
	bool operator <=(const myRational& rat) const;//완
	bool operator ==(const myRational& rat) const;//완
	bool operator !=(const myRational& rat) const;//완
	myRational operator+= (int num);//완
	myRational operator+= (const myRational& rat);//완
	myRational operator-= (int num);//완
	myRational operator-= (const myRational& rat);//완
	myRational operator*= (int num);//완
	myRational operator*= (const myRational& rat);//완
	myRational operator/= (int num);//완
	myRational operator/= (const myRational& rat);//완
	myRational& operator=(const long value);//완
	myRational& operator=(const myRational& rat);//완
	friend ostream &operator <<(ostream& outstream,const myRational& rat);
	friend istream &operator >>(istream& instream,myRational& rat);
	
private:
	
	// 분수는 항상 내부적으로 기약분수로 표현하며, 또한 항상 _den>0 이다. long _num; // numerator
	long _den;// denominator
	long gcd(long m, long n); // 최대공약수
	void reduce();
	long _num;
};
#endif
myRational::myRational(long num, long den)
{
	_num = num;
	_den = den;
	this->reduce();
}
myRational::myRational(const myRational& rat)
{
	_num = rat._num;
	_den = rat._den;
}
long myRational::getNumerator() const
{
	return _num;
}
long myRational::getDenominator() const
{
	return _den;
}
myRational myRational::reciprocal() const
{
	return myRational(_den, _num);
}
myRational myRational::operator+(const myRational& rat) const
{
	myRational new_rat(_num*rat._den+rat._num*_den,_den*rat._den);
	return new_rat;
}
myRational myRational::operator*(const myRational& rat) const
{
	myRational new_rat(_num*rat._num, _den*rat._den);
	return new_rat;
}
myRational myRational::operator/(const myRational& rat) const
{
	myRational new_rat(_num*rat._den, _den*rat._num);
	return new_rat;
}
myRational myRational::operator-(const myRational& rat) const
{
	myRational new_rat(_num*rat._den-_den*rat._num,_den*rat._den);
	return new_rat;
}
myRational myRational::operator +(int num) const
{
	myRational new_rat(_num+_den*num,_den);
	return new_rat;
}
myRational myRational::operator *(int num) const
{
	myRational new_rat(_num*num, _den);
	return new_rat;
}
myRational myRational::operator -(int num) const
{
	myRational new_rat(_num-_den*num, _den);
	return new_rat;
}
myRational myRational::operator /(int num) const
{
	myRational new_rat(_num,_den*num);
	return new_rat;
}
myRational operator+(long value, const myRational& rat)
{
	long num = rat.getNumerator();
	long den = rat.getDenominator();
	return myRational(num+ den * value, den);
}
myRational operator-(long value, const myRational& rat)
{
	long num = rat.getNumerator();
	long den = rat.getDenominator();
	return myRational(den*value-num, den);
}
myRational operator*(long value, const myRational& rat)
{
	long num = rat.getNumerator();
	long den = rat.getDenominator();
	myRational newRat(num*value, den);
	return newRat;
}
myRational operator/(long value, const myRational& rat)
{
	long num = rat.getNumerator();
	long den = rat.getDenominator();
	myRational newRat(value*den,num);
	return newRat;
}

myRational myRational::operator++(int)
{
	myRational prev(_num, _den);
	this->_num += this->_den;
	return prev;
}
myRational myRational::operator--(int)
{
	myRational prev(_num,_den);
	this->_num -= this->_den;
	return prev;
}
myRational myRational::operator++()
{
	this->_num = _den + _num;
	return *this;
}
myRational myRational::operator--()
{
	this->_num = _num - _den;
	return *this;
}
myRational myRational::operator-()
{
	return myRational(_num*-1, _den);
}
bool myRational::operator >(const myRational& rat) const
{
	myRational copy_rat(_num, _den);
	if (rat._num*copy_rat._num < 0)
	{
		if (_num < 0)
		{
			return false;
		}
		return true;
	}
	myRational dev_rat=copy_rat / rat;
	if (dev_rat._den < 0)
	{
		dev_rat._den *= -1;
	}
	if (dev_rat._num < 0)
	{
		dev_rat._num *= -1;
	}
	if (dev_rat._den >= dev_rat._num)
	{
		return false;
	}
	return true;
	

}
bool myRational::operator >=(const myRational& rat) const
{
	myRational copy_rat(_num, _den);
	if (rat._num*copy_rat._num < 0)
	{
		if (_num < 0)
		{
			return false;
		}
		return true;
	}
	myRational dev_rat = copy_rat / rat;
	if (dev_rat._den < 0)
	{
		dev_rat._den *= -1;
	}
	if (dev_rat._num < 0)
	{
		dev_rat._num *= -1;
	}
	if (dev_rat._den > dev_rat._num)
	{
		return false;
	}
	return true;
}
bool myRational::operator <(const myRational& rat) const
{
	
	myRational copy_rat(_num, _den);
	if (rat._num*copy_rat._num < 0)
	{
		if (_num < 0)
		{
			return true;
		}
		return false;
	}
	myRational dev_rat = copy_rat / rat;
	if (dev_rat._den < 0)
	{
		dev_rat._den *= -1;
	}
	if (dev_rat._num < 0)
	{
		dev_rat._num *= -1;
	}
	if (dev_rat._den <= dev_rat._num)
	{
		return false;
	}
	return true;
}
bool myRational::operator <=(const myRational& rat) const
{
	myRational copy_rat(_num, _den);
	if (rat._num*copy_rat._num < 0)
	{
		if (_num < 0)
		{
			return true;
		}
		return false;
	}
	myRational dev_rat = copy_rat / rat;
	if (dev_rat._den < 0)
	{
		dev_rat._den *= -1;
	}
	if (dev_rat._num < 0)
	{
		dev_rat._num *= -1;
	}
	if (dev_rat._den < dev_rat._num)
	{
		return false;
	}
	return true;
}
bool myRational::operator ==(const myRational& rat) const
{
	myRational copy_rat(_num, _den);
	myRational dev_rat = copy_rat / rat;
	if (dev_rat._den < 0)
	{
		dev_rat._den *= -1;
	}
	if (dev_rat._num < 0)
	{
		dev_rat._num *= -1;
	}
	if (dev_rat._den == dev_rat._num)
	{
		return true;
	}
	return false;
}
bool myRational::operator !=(const myRational& rat) const
{
	myRational copy_rat(_num, _den);
	myRational dev_rat = copy_rat / rat;
	if (dev_rat._den < 0)
	{
		dev_rat._den *= -1;
	}
	if (dev_rat._num < 0)
	{
		dev_rat._num *= -1;
	}
	if (dev_rat._den == dev_rat._num)
	{
		return false;
	}
	return true;
}
myRational myRational::operator+= (int num)
{
	this->_num += _den*num;
	this->reduce();
	return *this;
}
myRational myRational::operator+= (const myRational& rat)
{
	this->_num = _num*rat._den + _den*rat._num;
	this->_den *= rat._den;
	this->reduce();
	return *this;
}
myRational myRational::operator-= (int num)
{
	this->_num -= _den*num;
	this->reduce();
	return *this;
}
myRational myRational::operator-= (const myRational& rat)
{
	this->_num = _num*rat._den - _den*rat._num;
	this->_den *= rat._den;
	this->reduce();
	return *this;
}
myRational myRational::operator*= (int num)
{
	this->_num *= num;
	this->reduce();
	return *this;
}
myRational myRational::operator*= (const myRational& rat)
{
	this->_den *= rat._den;
	this->_num *= rat._num;
	this->reduce();
	return *this;
}
myRational myRational::operator/= (const myRational& rat)
{
	this->_den *=rat._num;
	this->_num *= rat._den;
	this->reduce();
	return *this;
}
myRational myRational::operator/= (int num)
{
	this->_den *= num;
	this->reduce();
	return *this;
}

myRational& myRational::operator=(const myRational& rat)
{
	this->_num = rat._num;
	this->_den = rat._den;
	return *this;
}
myRational& myRational::operator=(const long value)
{
	this->_den = 1;
	this->_num = value;
	this->reduce();
	return *this;
}

ostream &operator <<(ostream &outStream, const myRational& r)
{
	if (r._num == 0 || r._den==0)
		outStream << 0;
	else if (r._den == 1)
		outStream << r._num;
	else
		outStream << r._num << "/" << r._den;
 return outStream;
}

istream &operator >>(istream &inStream, myRational& r)
{
	inStream >> r._num >> r._den;
	if (r._den == 0)
	{
		r._num = 0;
		r._den = 1;
	}
	r.reduce();
	return inStream;
}
long myRational::gcd(long m, long n)
{
	if (m == n)
		return n;
	else if (m < n)
		return gcd(m, n - m);
	else
		return gcd(m - n, n);
}
void myRational::reduce()
{
	if (_num == 0 || _den == 0)
	{
		_num = 0;
		_den = 1;
		return;
	}
	if (_den < 0)
	{
		_den *= -1;
		_num *= -1;
	}
	if (_num == 1)
		return;
	int sgn = (_num < 0 ? -1 : 1);
	long g = gcd(sgn * _num, _den);
	_num /= g;
	_den /= g;
}
void testSimpleCase();
void testDataFromFile();
int main()
{
	testSimpleCase();
	testDataFromFile();
	return 0;
}
void testSimpleCase()
{
	myRational frac1(2), frac2(3, 2), frac3(6, 4), frac4(12, 8), frac5, frac6, frac7;
	cout << frac1 << " " << frac2 << " " << frac3 << " "<< frac4 << " " << frac5 << endl;
	cout << frac1.getNumerator() << " " << frac1.getDenominator() << endl;
	// Check arithmetic operators
	cout << frac1 * frac2 << " "<< frac1 + frac3 << " "<< frac2 - frac1 << " "<< frac3 / frac2 << endl;
	// Check comparison operators
	cout << ((frac1 < frac2) ? 1 : 0) << " "
		<< ((frac1 <= frac2) ? 1 : 0) << " "
		<< ((frac1 > frac2) ? 1 : 0) << " "
		<< ((frac1 >= frac2) ? 1 : 0) << " "
		<< ((frac1 == frac2) ? 1 : 0) << " "
		<< ((frac1 != frac2) ? 1 : 0) << " "
		<< ((frac2 < frac3) ? 1 : 0) << " "
		<< ((frac2 <= frac3) ? 1 : 0) << " "
		<< ((frac2 > frac3) ? 1 : 0) << " "
		<< ((frac2 >= frac3) ? 1 : 0) << " "
		<< ((frac2 == frac3) ? 1 : 0) << " "
		<< ((frac2 != frac3) ? 1 : 0) << endl;
	cout << (frac6 = frac3) << " ";
	cout << (frac6 += frac3) << " ";
	cout << (frac6 -= frac3) << " ";
	cout << (frac6 *= frac3) << " ";
	cout << (frac6 /= frac3) << endl;
	cout << -frac6 << endl;
	frac6 = (++frac4) + 2;
	frac7 = 2 + (frac4++);
	cout << frac4 << " " << frac6 << " " << frac7 << endl;
	frac6 = (--frac4) - 2;
	frac7 = 2 - (frac4--);
	cout << frac4 << " " << frac6 << " " << frac7 << endl;
	cout << 2 * frac3 << " " << frac3 * 2 << " "
		<< 2 / frac3 << " " << frac3 / 2 << endl;
}
void testDataFromFile()
{
	int test;
	cin >> test;
	for (int testCase = 0; testCase < test; testCase++)
	{
		int numOfNum;
		cin >> numOfNum;
		
		myRational box[10] = { myRational(30,1) };
		for (int i = 0; i < numOfNum; i++)
		{
			long num, den;
			cin >> num >> den;
			myRational frac(num, den);
			box[i] = frac;
		}
		sort(box, box+numOfNum);
		for (int i = 0; i < numOfNum; i++)
		{
			if (box[i].getDenominator() == 1)
			{
				cout << box[i].getNumerator() << " ";
			}
			else
			{
				cout << box[i].getNumerator() << "/" << box[i].getDenominator() << " ";
			}
		}
		
		cout << endl;
	}
}