#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long k, pos = 1;
    int n;
    cin >> n >> k;
    int v[10101];
    for (int i = 0; i < n; i++)
        v[i] = i + 1;
    while (next_permutation(v, v + n) && pos < k - 1)
        pos++;
    if (pos == k - 1 && n > 1)
        for (int i = 0; i < n; i++)
            cout << v[i] << " ";
    else
        cout << -1;
}