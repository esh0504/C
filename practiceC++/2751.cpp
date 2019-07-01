#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
	int arr[1000001] = { 0, }, i = 0, count = 0;
	cin >> count;
	for (i = 0; i < count; i++)
		cin >> arr[i];
	sort(arr, arr + count);
	for (i = 0; i < count; i++)
		cout << arr[i] << "\n";
	return 0;
}
