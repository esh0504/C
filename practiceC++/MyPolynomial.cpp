#include "MyPolynomial.h"
#include "MyTerm.h"
#include <algorithm>
using namespace std;

myPolynomial::myPolynomial(int c, unsigned e)
{
	degree = e;
	numTerms = 1;
	terms.push_back(myTerm(c, e));
}
myPolynomial::myPolynomial(int nTerms, int mono[])
{
	numTerms = nTerms;
	for (int i = 0; i < nTerms * 2; i = i + 2)
	{
		terms.push_back(myTerm(mono[i], mono[i + 1]));
	}
	sort(terms.begin(), terms.end(), greater<myTerm>());
	degree = terms[0].getExp();
}
myPolynomial::myPolynomial(const myPolynomial &poly)
{
	terms.clear();
	numTerms = poly.numTerms;
	degree = poly.degree;
	terms = poly.terms;
}
bool myPolynomial::operator ==(const myPolynomial &poly) const
{
	if (numTerms != poly.numTerms)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < numTerms; i++)
		{
			if (terms[i] != poly.terms[i])
			{
				return false;
			}
		}
	}
	return true;
}
bool myPolynomial ::operator !=(const myPolynomial & poly) const
{
	if (numTerms == poly.numTerms)
	{
		for (int i = 0; i < numTerms; i++)
		{
			if (terms[i] == poly.terms[i])
			{
				return false;
			}
			return true;
		}

	}
	return true;
}
myPolynomial myPolynomial::operator+(const myPolynomial&poly) const
{
	int aPos = 0;
	int cnt = 0;
	int bPos = 0;
	myPolynomial newpoly;
	newpoly.numTerms = poly.numTerms + numTerms;
	if (terms[0].exp> poly.terms[0].exp)
	{
		newpoly.terms[0] = myTerm(terms[aPos].coeff, terms[aPos].exp);
		aPos++;
	}
	else if (terms[aPos].exp == poly.terms[bPos].exp)
	{
		newpoly.terms[0] = myTerm(terms[aPos].coeff + poly.terms[bPos].coeff, terms[aPos].exp);
		aPos++;
		bPos++;
		newpoly.numTerms--;
	}
	else
	{
		newpoly.terms[0] = myTerm(poly.terms[bPos].coeff, poly.terms[bPos].exp);
		bPos++;
	}
	while (aPos != numTerms && bPos != poly.numTerms)
	{
		if (terms[aPos].exp> poly.terms[bPos].exp)
		{
			newpoly.terms.push_back(terms[aPos]);
			aPos++;
		}
		else if (terms[aPos].exp == poly.terms[bPos].exp)
		{
			if (terms[aPos].coeff + poly.terms[bPos].coeff == 0)
			{
				newpoly.numTerms--;
				newpoly.numTerms--;
				aPos++;
				bPos++;
				continue;
			}
			myTerm t(terms[aPos].coeff + poly.terms[bPos].coeff, terms[aPos].exp);
			newpoly.terms.push_back(t);
			newpoly.numTerms--;
			aPos++;
			bPos++;
		}
		else
		{
			newpoly.terms.push_back(poly.terms[bPos]);
			bPos++;
		}
	}
	if (aPos == numTerms)
	{
		for (int i = bPos; i < poly.numTerms; i++)
		{
			newpoly.terms.push_back(poly.terms[i]);
		}
	}
	else
	{
		for (int i = aPos; i < numTerms; i++)
		{
			newpoly.terms.push_back(terms[i]);
		}
	}
	if (poly.degree > degree)
	{
		newpoly.degree = poly.degree;
	}
	else
	{
		newpoly.degree = degree;
	}
	sort(newpoly.terms.begin(), newpoly.terms.end(), greater<myTerm>());
	newpoly.degree = newpoly.terms[0].exp;
	return newpoly;
}
myPolynomial& myPolynomial::operator+=(const myPolynomial&poly)
{
	int aPos = 0;
	int cnt = 0;
	int bPos = 0;
	myPolynomial newpoly;
	newpoly.numTerms = poly.numTerms + numTerms;
	if (terms[0].exp> poly.terms[0].exp)
	{
		newpoly.terms[0] = myTerm(terms[aPos].coeff, terms[aPos].exp);
		
		aPos++;
	}
	else if (terms[aPos].exp == poly.terms[bPos].exp)
	{
		if (terms[aPos].coeff + poly.terms[bPos].coeff == 0)
		{
			aPos++;
			bPos++;
			newpoly.numTerms--;
			newpoly.terms[0] = myTerm(0,poly.terms[bPos].exp);
		}
		else
		{
			
			newpoly.terms[0] = myTerm(terms[aPos].coeff + poly.terms[bPos].coeff, terms[aPos].exp);
			aPos++;
			bPos++;
			newpoly.numTerms--;
		}
	}
	else
	{
		newpoly.terms[0] = myTerm(poly.terms[bPos].coeff, poly.terms[bPos].exp);
		bPos++;
	}
	while (aPos != numTerms && bPos != poly.numTerms)
	{
		if (terms[aPos].exp> poly.terms[bPos].exp)
		{
			if (newpoly.degree > terms[aPos].exp)
			{
				newpoly.degree = terms[aPos].exp;
			}
			newpoly.terms.push_back(terms[aPos]);
			aPos++;
		}
		else if (terms[aPos].exp == poly.terms[bPos].exp)
		{
			if (terms[aPos].coeff + poly.terms[bPos].coeff == 0)
			{
				newpoly.numTerms--;
				newpoly.numTerms--;
				aPos++;
				bPos++;
				continue;
			}
			myTerm t(terms[aPos].coeff + poly.terms[bPos].coeff, terms[aPos].exp);
			newpoly.terms.push_back(t);
			if (newpoly.degree < terms[aPos].exp)
			{
				newpoly.degree = terms[aPos].exp;
			}
			newpoly.numTerms--;
			aPos++;
			bPos++;
		}
		else
		{
			if (newpoly.degree < poly.terms[bPos].exp)
			{
				newpoly.degree = poly.terms[bPos].exp;
			}
			newpoly.terms.push_back(poly.terms[bPos]);
			bPos++;
		}
	}
	if (aPos == numTerms)
	{
		for (int i = bPos; i < poly.numTerms; i++)
		{
			newpoly.terms.push_back(poly.terms[i]);
		}
	}
	else
	{
		for (int i = aPos; i < numTerms; i++)
		{
			newpoly.terms.push_back(terms[i]);
		}
	}
	sort(newpoly.terms.begin(), newpoly.terms.end(), greater<myTerm>());
	this->degree = newpoly.terms[0].exp;
	this->numTerms = newpoly.numTerms;
	this->terms.clear();
	for (int i = 0; i < numTerms; i++)
	{
		this->terms.push_back(newpoly.terms[i]);
	}

	return *this;
}
myPolynomial myPolynomial::operator-(const myPolynomial&poly) const
{
	int aPos = 0;
	int cnt = 0;
	int bPos = 0;
	myPolynomial newpoly;
	newpoly.numTerms = poly.numTerms + numTerms;
	if (terms[0].exp> poly.terms[0].exp)
	{
		newpoly.terms[0] = myTerm(terms[aPos].coeff, terms[aPos].exp);
		aPos++;
	}
	else if (terms[aPos].exp == poly.terms[bPos].exp)
	{
		newpoly.terms[0] = myTerm(terms[aPos].coeff - poly.terms[bPos].coeff, terms[aPos].exp);
		aPos++;
		bPos++;
		newpoly.numTerms--;
	}
	else
	{
		newpoly.terms[0] = myTerm(poly.terms[bPos].coeff*-1, poly.terms[bPos].exp);
		bPos++;
	}
	while (aPos != numTerms && bPos != poly.numTerms)
	{
		if (terms[aPos].exp> poly.terms[bPos].exp)
		{
			newpoly.terms.push_back(terms[aPos]);
			aPos++;
		}
		else if (terms[aPos].exp == poly.terms[bPos].exp)
		{
			if (terms[aPos].coeff - poly.terms[bPos].coeff == 0)
			{
				newpoly.numTerms--;
				newpoly.numTerms--;
				aPos++;
				bPos++;
				continue;
			}
			myTerm t(terms[aPos].coeff - poly.terms[bPos].coeff, terms[aPos].exp);
			newpoly.terms.push_back(t);
			newpoly.numTerms--;
			aPos++;
			bPos++;
		}
		else
		{
			newpoly.terms.push_back(myTerm(poly.terms[bPos].coeff*-1, poly.terms[bPos].exp));
			bPos++;
		}
	}
	if (aPos == numTerms)
	{
		for (int i = bPos; i < poly.numTerms; i++)
		{
			newpoly.terms.push_back(myTerm(poly.terms[i].coeff*-1, poly.terms[i].exp));
		}
	}
	else
	{
		for (int i = aPos; i < numTerms; i++)
		{
			newpoly.terms.push_back(terms[i]);
		}
	}
	sort(newpoly.terms.begin(), newpoly.terms.end(), greater<myTerm>());
	newpoly.degree = newpoly.terms[0].exp;
	return newpoly;
}
myPolynomial& myPolynomial::operator-=(const myPolynomial &poly)
{

	int aPos = 0;
	int cnt = 0;
	int bPos = 0;
	myPolynomial newpoly;
	newpoly.numTerms = poly.numTerms + numTerms;
	if (terms[0].exp> poly.terms[0].exp)
	{
		newpoly.terms[0] = myTerm(terms[aPos].coeff, terms[aPos].exp);
		aPos++;
		newpoly.degree = terms[0].exp;
	}
	else if (terms[aPos].exp == poly.terms[bPos].exp)
	{
		if (terms[0].coeff - poly.terms[0].coeff == 0)
		{
			newpoly.numTerms--;
			newpoly.numTerms--;
			aPos++;
			bPos++;
		}
		else
		{
			newpoly.terms[0] = myTerm(terms[aPos].coeff - poly.terms[bPos].coeff, terms[aPos].exp);
			aPos++;
			bPos++;
			newpoly.degree = poly.terms[0].exp;
			newpoly.numTerms--;
		}
	}
	else
	{
		newpoly.terms[0] = myTerm(poly.terms[bPos].coeff*-1, poly.terms[bPos].exp);
		bPos++;
		newpoly.degree = poly.terms[0].exp;
	}
	while (aPos != numTerms && bPos != poly.numTerms)
	{
		if (terms[aPos].exp> poly.terms[bPos].exp)
		{
			newpoly.terms.push_back(terms[aPos]);
			if (newpoly.degree < terms[aPos].exp)
			{
				newpoly.degree = terms[aPos].exp;
			}
			aPos++;

		}
		else if (terms[aPos].exp == poly.terms[bPos].exp)
		{
			if (terms[aPos].coeff - poly.terms[bPos].coeff == 0)
			{
				newpoly.numTerms--;
				newpoly.numTerms--;
				aPos++;
				bPos++;
				continue;
			}
			myTerm t(terms[aPos].coeff - poly.terms[bPos].coeff, terms[aPos].exp);
			if (newpoly.degree < terms[aPos].exp)
			{
				newpoly.degree = terms[aPos].exp;
			}
			newpoly.terms.push_back(t);
			newpoly.numTerms--;
			aPos++;
			bPos++;

		}
		else
		{
			if (newpoly.degree < poly.terms[bPos].exp)
			{
				newpoly.degree = poly.terms[bPos].exp;
			}
			newpoly.terms.push_back(myTerm(poly.terms[bPos].coeff*-1, poly.terms[bPos].exp));
			bPos++;
		}
	}
	if (aPos == numTerms)
	{
		for (int i = bPos; i < poly.numTerms; i++)
		{
			newpoly.terms.push_back(myTerm(poly.terms[i].coeff*-1, poly.terms[i].exp));
		}
	}
	else
	{
		for (int i = aPos; i < numTerms; i++)
		{
			newpoly.terms.push_back(terms[i]);
		}
	}
	newpoly.degree = newpoly.terms[0].exp;
	this->degree = newpoly.degree;
	this->numTerms = newpoly.numTerms;
	this->terms.clear();
	for (int i = 0; i < this->numTerms; i++)
	{
		this->terms.push_back(newpoly.terms[i]);
	}
	return *this;
}
myPolynomial myPolynomial::operator*(const myPolynomial &poly) const
{
	myPolynomial newpoly;
	for (int i = 0; i < numTerms; i++)
	{
		for (int j = 0; j < poly.numTerms; j++)
		{
			if (i == 0 && j == 0)
			{
				newpoly.terms[0] = myTerm(terms[0].coeff*poly.terms[0].coeff, terms[0].exp + poly.terms[0].exp);
			}
			else
			{
				newpoly.terms.push_back(myTerm(terms[i].coeff*poly.terms[j].coeff, terms[i].exp + poly.terms[j].exp));
			}
		}
	}
	sort(newpoly.terms.begin(), newpoly.terms.end(), greater<myTerm>());
	myPolynomial newpoly2(newpoly.terms[0].coeff, newpoly.terms[0].exp);
	int cnt = 1;
	for (int i = 1; i < numTerms*poly.numTerms - 1; i++)
	{
		int coeff = newpoly.terms[i].coeff;
		unsigned exp = newpoly.terms[i].exp;
		if (newpoly.terms[i].exp != newpoly.terms[i + 1].exp)
		{
			if (newpoly.terms[i].coeff == 0)
			{
				continue;
			}
			newpoly2.terms.push_back(myTerm(newpoly.terms[i].coeff, newpoly.terms[i].exp));
			cnt++;
		}
		else
		{
			newpoly.terms[i + 1].coeff += coeff;
		}
	}
	newpoly2.terms.push_back(myTerm(newpoly.terms[numTerms*poly.numTerms - 1].coeff, newpoly.terms[numTerms*poly.numTerms - 1].exp));
	newpoly2.degree = poly.degree + degree;
	newpoly2.numTerms = cnt + 1;
	sort(newpoly2.terms.begin(), newpoly2.terms.end(), greater<myTerm>());
	newpoly2.degree = newpoly2.terms[0].exp;
	return newpoly2;
}
myPolynomial myPolynomial::operator*(int k)const
{
	if (k == 0)
	{
		return myPolynomial::ZERO;
	}
	myPolynomial newpoly(terms[0].coeff*k, terms[0].exp);
	newpoly.numTerms = numTerms;
	newpoly.degree = degree;
	for (int i = 1; i < numTerms; i++)
	{
		newpoly.terms.push_back(myTerm(terms[i].coeff*k, terms[i].exp));
	}
	return newpoly;
}
myPolynomial myPolynomial::operator-()const
{
	if (numTerms == 1)
	{
		if (terms[0].exp == 0)
		{
			return myPolynomial(terms[0].coeff*-1, (unsigned)0);
		}
		else {
			return myPolynomial(terms[0].coeff*-1, (unsigned)terms[0].exp);
		}
	}
	myPolynomial newpoly(terms[0].coeff*-1, terms[0].exp);
	newpoly.numTerms = numTerms;
	newpoly.degree = degree;
	for (int i = 1; i < numTerms; i++)
	{
		newpoly.terms.push_back(myTerm(-1 * terms[i].coeff, terms[i].exp));
	}
	return newpoly;
}
myPolynomial& myPolynomial::operator *= (int k)
{
	if (k == 0)
	{
		this->ZERO;
		return *this;
	}
	for (int i = 0; i < numTerms; i++)
	{
		this->terms[i].coeff = terms[i].coeff*k;
	}
	return *this;
}
myPolynomial& myPolynomial::operator *=(const myPolynomial &poly)
{
	myPolynomial newpoly;
	for (int i = 0; i < numTerms; i++)
	{
		for (int j = 0; j < poly.numTerms; j++)
		{
			if (i == 0 && j == 0)
			{
				newpoly.terms[0] = myTerm(terms[0].coeff*poly.terms[0].coeff, terms[0].exp + poly.terms[0].exp);
			}
			else
			{
				newpoly.terms.push_back(myTerm(terms[i].coeff*poly.terms[j].coeff, terms[i].exp + poly.terms[j].exp));
			}
		}
	}
	sort(newpoly.terms.begin(), newpoly.terms.end(), greater<myTerm>());
	myPolynomial newpoly2(newpoly.terms[0].coeff, newpoly.terms[0].exp);
	int cnt = 1;
	for (int i = 1; i < numTerms*poly.numTerms - 1; i++)
	{
		int coeff = newpoly.terms[i].coeff;
		unsigned exp = newpoly.terms[i + 1].exp;
		if (newpoly.terms[i] != newpoly.terms[i + 1])
		{
			if (newpoly.terms[i].coeff == 0)
			{
				continue;
			}
			newpoly2.terms.push_back(myTerm(newpoly.terms[i].coeff, newpoly.terms[i].exp));
			cnt++;
		}
		else
		{
			newpoly.terms[i + 1].coeff += coeff;
		}
	}
	newpoly2.terms.push_back(myTerm(newpoly.terms[numTerms*poly.numTerms - 1].coeff, newpoly.terms[numTerms*poly.numTerms - 1].exp));
	newpoly2.degree = poly.degree + degree;
	newpoly2.numTerms = cnt + 1;
	this->degree = newpoly2.degree;
	this->numTerms = newpoly2.numTerms;
	this->terms.clear();
	for (int i = 0; i < newpoly2.numTerms; i++)
	{
		this->terms.push_back(myTerm(newpoly2.terms[i].coeff, newpoly2.terms[i].exp));
	}
	for (int i = 0; i < newpoly2.numTerms; i++)
	{
		if (this->degree == 0)
		{
			if (this->terms[i].coeff != 0)
			{
				this->degree = terms[i].exp;
				break;
			}
		}
		else {
			break;
		}
	}

	return *this;
}

long myPolynomial::operator()(int x)const
{
	long answer = 0;
	for (int i = 0; i < numTerms; i++)
	{
		long cnt = 1;
		for (int k = 0; k < terms[i].exp; k++)
		{
			cnt *= x;
		}
		cnt = terms[i].coeff*cnt;
		answer += cnt;
	}
	return answer;
}
int myPolynomial::getDegree() const
{
	if (terms[0].coeff == 0)return -1;
	return degree;
}
unsigned myPolynomial::getNumTerms() const
{
	return this->numTerms;
}
myPolynomial myPolynomial::ddx() const
{
	if (numTerms == 1)
	{
		if (terms[0].exp == 0)
		{
			return ZERO;
		}
		else
		{
			return myPolynomial(terms[0].coeff*terms[0].exp, terms[0].exp - 1);
		}
	}
	myPolynomial newpoly(terms[0].coeff*terms[0].exp, terms[0].exp - 1);
	newpoly.numTerms = newpoly.terms.capacity();
	for (int i = 1; i < numTerms; i++)
	{
		myTerm t(terms[i].ddx());
		if (terms[i].exp == 0 || t.coeff == 0)
		{
			continue;
		}
		newpoly.numTerms++;
		newpoly.terms.push_back(t);
	}
	sort(newpoly.terms.begin(), newpoly.terms.end(), greater<myTerm>());
	newpoly.degree = newpoly.terms[0].exp;
	return newpoly;
}
myPolynomial operator *(int k, const myPolynomial &poly)
{
	if (k == 0)
	{
		return myPolynomial::ZERO;
	}
	int coeff = poly.terms[0].getCoeff();
	unsigned exp = poly.terms[0].getExp();
	myPolynomial newpoly(coeff*k, exp);
	newpoly.degree = poly.degree;
	newpoly.numTerms = poly.numTerms;

	for (int i = 1; i < poly.numTerms; i++)
	{
		int coeff = poly.terms[i].getCoeff();
		unsigned exp = poly.terms[i].getExp();
		myTerm t(coeff*k, exp);
		newpoly.terms.push_back(t);
	}

	return newpoly;
}
void myPolynomial::setCoeff(int k)
{
	this->terms[0].coeff = k;
}

ostream& operator <<(ostream &outStream, const myPolynomial& poly)
{
	if (poly == myPolynomial::ZERO || poly.numTerms == 0)
		return outStream << 0;
	else if (poly == myPolynomial::ONE)
		return outStream << 1;
	else if (poly == myPolynomial::X)
		return outStream << "x";
	if (poly.numTerms == 1)
	{
		int coeff = poly.terms[0].getCoeff();
		unsigned exp = poly.terms[0].getExp();
		if (coeff == 0)
		{
			return outStream << 0;
		}
		else if (coeff == 1 && poly.degree != 1 && poly.degree != 0)
		{
			return outStream << "x^" << exp;
		}
		if (poly.degree == 0)
		{
			return outStream << coeff;
		}
		else
		{
			if (poly.degree == 1)
			{
				if (coeff > 0)
				{
					return outStream << coeff << "x";
				}
				else
				{
					return outStream << coeff << "x";
				}
			}
			else
			{
				return outStream << coeff << "x^" << exp;
			}
		}
	}
	for (int i = 0; i <poly.numTerms; i++)
	{
		int coeff = poly.terms[i].getCoeff();
		unsigned exp = poly.terms[i].getExp();
		if (coeff == 0)
		{
			continue;
		}
		else
		{
			if (poly.degree == exp && exp != 0 && exp != 1)
			{
				if (coeff == 1)
				{
					outStream << "x" << "^" << exp;
				}
				else if (coeff == -1)
				{
					outStream << "-x" << "^" << exp;
				}
				else {
					outStream << coeff << "x" << "^" << exp;
				}
			}
			else if (coeff < 0 && exp != 0 && exp != 1)
			{
				if (coeff == -1)
				{
					outStream << "-x" << "^" << exp;
				}
				else {
					outStream << coeff << "x" << "^" << exp;
				}
			}
			else if (coeff > 0 && exp != 0 && exp != 1)
			{
				if (coeff == 1)
				{
					outStream << "+x" << "^" << exp;
				}
				else {
					outStream << "+" << coeff << "x" << "^" << exp;
				}

			}
			else if (exp == 0)
			{
				if (coeff < 0)
				{
					outStream << coeff;
				}
				else
				{
					outStream << "+" << coeff;
				}
			}
			else if (exp == 1)
			{
				if (coeff == 1)
				{
					outStream << "+x";
				}
				else if (coeff == -1)
				{
					outStream << "-x";
				}
				else if (coeff>0)
				{
					outStream << "+" << coeff << "x";
				}
				else {
					outStream << coeff << "x";
				}

			}

		}
	}
	/********************* add your code here ********************************/
	return outStream;
}
const myPolynomial myPolynomial::ZERO(0); // the zero polynomial P(x) = 0
const myPolynomial myPolynomial::ONE(1, (unsigned)0); // the monomial P(x) = 1
const myPolynomial myPolynomial::X(1, 1); // the monomial P(x) = x