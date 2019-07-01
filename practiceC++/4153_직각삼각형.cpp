#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int line[3];
	int x, y, z;
	cin >> x >> y >> z;
	line[0] = x;
	line[1] = y;
	line[2] = z;
	sort(line, line + 3);
	while (line[0] != 0 || line[1] != 0 || line[2] != 0)
	{
		if (line[0] * line[0] + line[1] * line[1] == line[2] * line[2])
		{
			cout << "right" << endl;
		}
		else {
			cout << "wrong" << endl;
		}
		cin >> x >> y >> z;
		line[0] = x; line[1] = y; line[2] = z;
		sort(line, line + 3);
	}
	return 0;
}