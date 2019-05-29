#include<fstream>
#include <string>
#include <iostream>
using namespace std;

int main(void)
{
	string in_line;
	ifstream in("box.txt");
	while (getline(in, in_line)) {
		cout << in_line << endl;
	}
	in.close();
}