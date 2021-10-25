#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, count = 0, temp;
    cin >> n;
    n = 1000 - n;
    int a[] = {500, 100, 50, 10, 5, 1};
    for (int i = 0; i < 6; i++)
    {
        temp = n / a[i];
        count += temp;
        n -= temp * a[i];
    }
    cout << count;
}