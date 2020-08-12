#include <iostream>

using namespace std;


int result = 0;

bool prom(int i,int *arr)
{
    for (int j = 0; j < i; j++)
    {
        if (arr[j] == arr[i] || abs(arr[i] - arr[j]) == (i - j))
            return false;
    }
    return true;
}
void sol(int i,int *arr,int n)
{
    if (i == n)
        result++;
    else
    {
        for (int j = 0; j < n; j++)
        {
            arr[i] = j;
            if (prom(i,arr))
                sol(i + 1,arr,n);
        }
    }
}

int main()
{
    int n;
    int arr[15];
    cin >> n;
    sol(0, arr,n);
    cout << result << endl;
    return 0;
}