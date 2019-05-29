#ifndef _MYCOMPLEX_H_
#define _MYCOMPLEX_H_
#include <iostream>
#include <fstream>
#include <cstdlib> 
using namespace std;
class myComplex {
public:
	// Constructor (생성자)
	myComplex(int real = 0, int imag = 0);
	// Copy constructor (복사 생성자)
	myComplex(const myComplex& number);
	// Accessor functions (접근자)
	int getRealPart() const;
	int getImaginaryPart() const;
	// Mutator functions (변경자)
	void setRealPart(int real);
	void setImaginaryPart(int imag);
	void set(int real, int imag);
	// Overloaded binary operators
	myComplex operator +(const myComplex& number) const;
	myComplex operator +(int value) const;
	// Overloaded assignment operators
	myComplex& operator =(const myComplex& number);
	myComplex& operator =(int value);
	// Overloading relational operators
	bool operator ==(const myComplex& number) const;
	// Overloaded unary operators
	myComplex operator -(); // unary minus
	myComplex operator ++(int);
	myComplex operator *=(int num);
	myComplex operator += (int num);
	myComplex operator -=(int num);
	myComplex operator --(int);
	myComplex operator -(const myComplex& number) const;
	myComplex operator *(const myComplex& number) const;
	myComplex operator +=(myComplex& number);
	myComplex operator -=(const myComplex& number);
	myComplex operator *=(const myComplex& number);
	myComplex operator ++();
	myComplex operator --();
	myComplex operator ~();
	myComplex operator *(int value);
	
	
	bool operator >(const myComplex& number) const;
	bool operator !=(const myComplex& number) const;
	bool operator >=(const myComplex& number) const;
	bool operator <(const myComplex& number) const;
	bool operator <=(const myComplex& number) const;
	
	
	friend ostream &operator <<(ostream& outstream, const myComplex& number);
	friend istream &operator >>(istream& instream, myComplex& number);
private:
	int realPart;
	int imaginaryPart;
	int norm() const;
};



#endif

// Constructor
myComplex::myComplex(int real, int imag)
{
	realPart = real;
	imaginaryPart = imag;
}

// Copy constructor
myComplex::myComplex(const myComplex& number)
{
	realPart = number.realPart;
	imaginaryPart = number.imaginaryPart;
}
// Accessor functions
int myComplex::getRealPart() const
{
	return realPart;
}
int myComplex::getImaginaryPart() const
{
	return imaginaryPart;
}
// Mutator functions
void myComplex::setRealPart(int real)
{
	realPart = real;
}
void myComplex::setImaginaryPart(int imag)
{
	imaginaryPart = imag;
}
void myComplex::set(int real, int imag)
{
	realPart = real;
	imaginaryPart = imag;
}
// Overloaded binary operators
myComplex myComplex::operator +(const myComplex& number) const
{
	int newReal = realPart + number.realPart;
	int newImag = imaginaryPart + number.imaginaryPart;
	return myComplex(newReal, newImag);
}
myComplex myComplex::operator++(int)
{
	myComplex prev(this->realPart, this->imaginaryPart);
	this->realPart++;
	return prev;
}
myComplex myComplex::operator--(int)
{
	myComplex prev(this->realPart, this->imaginaryPart);
	this->realPart--;
	return prev;
}
myComplex myComplex::operator +(int value) const
{
	return myComplex(value) + (*this);
}
// Assignment operators
myComplex myComplex::operator -(const myComplex& number) const
{
	int newReal = realPart - number.realPart;
	int newlmag = imaginaryPart - number.imaginaryPart;
	return myComplex(newReal, newlmag);
}
myComplex myComplex::operator *(const myComplex& number) const
{
	int newReal = realPart * number.realPart - imaginaryPart * number.imaginaryPart;
	int newlmag = realPart * number.imaginaryPart + number.realPart*imaginaryPart;
	return myComplex(newReal, newlmag);
}
myComplex myComplex::operator*(int number)
{
	int newReal = number * realPart;
	int newImg = number * imaginaryPart;
	return myComplex(newReal, newImg);
}
myComplex operator*(int value, const myComplex& number)
{
	int realPart=number.getRealPart();
	int imaginaryPart = number.getImaginaryPart();
	int newReal = value * realPart;
	int newImg = value * imaginaryPart;
	return myComplex(newReal,newImg);
}
myComplex operator+(int value, const myComplex& number)
{
	int realPart = number.getRealPart();
	int imaginaryPart = number.getImaginaryPart();
	int newReal = value + realPart;
	return myComplex(newReal, imaginaryPart);
}
myComplex operator-(int value, const myComplex& number)
{
	int realPart = number.getRealPart();
	int imaginaryPart = number.getImaginaryPart()*-1;
	int newReal = value - realPart;
	return myComplex(newReal, imaginaryPart);
}
myComplex myComplex::operator+=(myComplex& number)
{
	this->realPart = this->realPart + number.realPart;
	this->imaginaryPart = this->imaginaryPart + number.imaginaryPart;
	return *this;
}
myComplex myComplex::operator += (int num)
{
	this->realPart = num + this->realPart;
	return *this;
}
myComplex myComplex::operator-=(const myComplex& number)
{
	this -> realPart = this->realPart - number.realPart;
	this -> imaginaryPart = this->imaginaryPart - number.imaginaryPart;
	return *this;
}
myComplex myComplex::operator -= (int num)
{
	this->realPart = this->realPart-num;
	return *this;
}
myComplex myComplex::operator *= (int num)
{
	this->realPart = num * this->realPart;
	this->imaginaryPart = num * this->imaginaryPart;
	return *this;
}

myComplex myComplex::operator*=(const myComplex& number)
{
	int originReal = realPart;
	int originImg = imaginaryPart;
	this->realPart = realPart * number.realPart - imaginaryPart * number.imaginaryPart;
	this->imaginaryPart = originReal * number.imaginaryPart + originImg*number.realPart;
	return *this;
}
myComplex& myComplex::operator =(const myComplex& number)
{
	this->realPart = number.realPart;
	this->imaginaryPart = number.imaginaryPart;
	return *this;
}
myComplex& myComplex::operator =(int value)
{
	realPart = value;
	imaginaryPart = 0;
	return *this;
}
// Overloading comparison operators
bool myComplex::operator ==(const myComplex& number) const
{
	return (realPart == number.realPart) &&
		(imaginaryPart == number.imaginaryPart);
}
bool myComplex::operator !=(const myComplex& number) const
{
	return (realPart != number.realPart || imaginaryPart != number.imaginaryPart);
}
bool myComplex::operator >(const myComplex& number) const
{
	return norm() > number.norm();
}
bool myComplex::operator <(const myComplex& number) const
{
	return norm() < number.norm();
}
bool myComplex::operator <=(const myComplex& number) const
{
	return norm() <= number.norm();
}
bool myComplex::operator >=(const myComplex& number) const
{
	return norm() >= number.norm();
}
// Overloaded unary operators
myComplex myComplex::operator -() // unary minus
{
	return myComplex(-realPart, -imaginaryPart);
}
myComplex myComplex::operator ++()
{
	this->realPart = this->realPart + 1;
	return *this;
}
myComplex myComplex::operator --()
{
	this->realPart = this->realPart - 1;
	return *this;
}

myComplex myComplex ::operator ~()
{
	return myComplex(realPart, -imaginaryPart);
}
// private function
int myComplex::norm() const
{
	return realPart * realPart + imaginaryPart * imaginaryPart;
}
ostream &operator <<(ostream &outStream, const myComplex& number)
{
	outStream << "(" << number.realPart << "," << number.imaginaryPart << ")";
	return outStream;
}


istream &operator >>(istream &inStream, myComplex& number)
{
	inStream >> number.realPart >> number.imaginaryPart;
	return inStream;
}

void testSimpleCase();
void testDataFromFile();
int main(void)
{
	testSimpleCase();
	testDataFromFile();
	return 0;
}
void testSimpleCase()
{
	myComplex c0, c1(1), c2(2, 2);
	myComplex c3(c2);
	myComplex c4, c5, c6, c7, c8, c9;
	// test constructor
	cout << c0 << endl << c1 << endl << c2 << endl;
	// test copy constructor
	cout << c3 << endl;
	// test accessor function
	cout << c3 << endl;
	// test mutator function
	c3.set(3, 3);
	cout << c3 << endl;
	c3.setRealPart(4);
	cout << c3 << endl;
	c3.setImaginaryPart(4);
	cout << c3 << endl;
	// test binary operators
	c4 = c1 + c3;
	c5 = c1 - c3;
	c6 = c4 * c5;
	cout << c4 << endl << c5 << endl << c6 << endl;
	c7 = c6 + 2;
	c8 = c6 - 2;
	c9 = c6 * 2;
	cout << c7 << endl << c8 << endl << c9 << endl;
	c7 += c4;
	c8 -= c5;
	c9 *= c6;
	cout << c7 << endl << c8 << endl << c9 << endl;
	c7 += 2;
	c8 -= 2;
	c9 *= 2;
	cout << c7 << endl << c8 << endl << c9 << endl;
	// test comparison operators
	cout << (c8 != c9) << " " << (c8 == c9) << endl;
	cout << (c8 > c9) << " " << (c8 >= c9) << " " << (c8 < c9) << " " << (c8 <= c9) <<
		endl;
	c7 = c8 = c9;
	cout << (c8 != c9) << " " << (c8 == c9) << endl;
	cout << (c8 > c9) << " " << (c8 >= c9) << " " << (c8 < c9) << " " << (c8 <= c9) << endl;
	// test prefix operators
	c7 = -myComplex(2, 3);
	c8 = (++c7) * 2;
	c9 = 2 * (c7++);
	cout << c7 << " " << c8 << " " << c9 << endl;
	c7 = ~myComplex(2, 3);
	c8 = (--c7) * 2;
	c9 = 2 * (c7--);
	cout << c7 << " " << c8 << " " << c9 << endl;
	// test expressions with myComplex numbers
	c1 = myComplex(1, 2);
	c2 = myComplex(2, 3);
	c3 = myComplex(4, 5);
	c4 = myComplex(5, 6);
	c5 = myComplex(6, 7);
	c6 = 3;
	cout << -(c1*c2) - 2 * c3 + ~c4 * c5 * 3 + 2 - c6 << endl;
}
void testDataFromFile()
{
	ifstream inStream;
	int numTestCases;
	cin >> numTestCases;
	for (int i = 0; i<numTestCases; i++)
	{
		myComplex c1, c2, c3, c4;
		myComplex c5, c6, c7, c8, c9;
		cin >> c1 >> c2 >> c3 >> c4;
		cout << c1 << " " << c2 << " " << c3 << " " << c4 << endl;
		cout << (2 + c1 + 3) + (2 - c2 - 3) * (2 * c3 * 3) - (2 * c4 - 3) << endl;
		c5 = c6 = c7 = c8 = c1;
		cout << (c5 == c2) << " " << (c5 != c2) << endl;
		cout << (c5 > c2) << " " << (c5 >= c2) << " " << (c5 < c2) << " " << (c5 <= c2)
			<< endl;
		cout << (c5 == c6) << " " << (c5 != c6) << endl;
		cout << (c5 > c6) << " " << (c5 >= c6) << " " << (c5 < c6) << " " << (c5 <= c6)
			<< endl;
		c5 += c2;
		c6 -= c3;
		c7 *= c4;
		c8 = c2.getRealPart();
		c9 = c3.getImaginaryPart();
		cout << c5 << " " << c6 << " " << c7 << " " << c8 << " " << c9 << endl;
		c7 = -c6;
		c8 = (++c7) * 2;
		c9 = 2 * (c7++);
		cout << c7 << " " << c8 << " " << c9 << endl;
		c7 = ~c6;
		c8 = (++c7) * 2;
		c9 = 2 * (c7++);
		cout << c7 << " " << c8 << " " << c9 << endl;
	}
	inStream.close();
}