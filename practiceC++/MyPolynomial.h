#include <fstream>
#include <iostream>
#include <cstdlib>
#ifndef _MYPOLYNOMIAL_H_
#define _MYPOLYNOMIAL_H_
#include "MyTerm.h"
#include <vector>
using namespace std;

class myPolynomial
{
public:
	myPolynomial(int c = 0, unsigned e = 0);//완
	myPolynomial(int nTerms, int mono[]);//완
	// copy constructor
	myPolynomial(const myPolynomial &poly);//완
	// overloaded operators
	bool operator == (const myPolynomial &poly) const;//완
	bool operator != (const myPolynomial &poly) const;//완
	myPolynomial& operator += (const myPolynomial &poly);//완
	myPolynomial& operator -= (const myPolynomial &poly);//완
	myPolynomial& operator *= (const myPolynomial &poly);//완
	myPolynomial& operator *= (int k);//완
	myPolynomial operator -() const;//완
	myPolynomial operator *(int k) const;//완
	myPolynomial operator +(const myPolynomial &poly) const;//완
	myPolynomial operator -(const myPolynomial &poly) const;//완
	myPolynomial operator *(const myPolynomial &poly) const;//완
	void setCoeff(int k);
	long operator() (int x) const; // evaluate the polynomial 완
	int getDegree() const; // get a degree of the polynomial 완
	unsigned getNumTerms() const; // number of terms in the polynomial 완
	myPolynomial ddx() const; // derivative of a polynomial 완
							  // friend operators and functions
	friend myPolynomial operator *(int k, const myPolynomial &poly); //완
	friend ostream& operator <<(ostream& outStream, const myPolynomial &poly); //완
	static const myPolynomial ZERO; // P(x) = 0
	static const myPolynomial ONE; // P(x) = 1
	static const myPolynomial X; // P(x) = x
private:
	int degree;// maximum expnent
	int numTerms;
	vector <myTerm> terms;
	/********************* add your code here ********************************/
};
#endif _MYPOLYNOMIAL_H_