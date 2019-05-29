#include<iostream>
using namespace std;
class Animal
{
public:
	void wag();
	void bite();
	void speak()const;
private:
	Animal()
	{
		cout << "animal" << endl;
	}
};
class Cat
{
public:
	void wag();
	void bite();
	void speak()const;
	~Cat();
private:

};
class Dog 
{
public:
	void wag();
	void bite();
	void speak()const;
	~Dog();
private:

};
Dog::~Dog()
{
	cout << "Dog" << endl;
}
void Dog::wag()
{
	cout << "Dog wag" << endl;
}
void Dog::bite()
{
	cout << "Dog bite()" << endl;
}
void Dog::speak() const
{
	cout << "Dog speak" << endl;
}	
class Rectangle
{
public:
	Rectangle() {
		edge = 4;
	}
}
void move(Shape& s, int sx, int sv)
{
	s.setOrigin(sx, sy);
}

int main()
{
	Rectangle r;
	move(r, 0, 0);
	Circle c;
	move(c, 10, 10);
	return 0;
	
}
}