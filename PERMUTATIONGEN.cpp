#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int v[10101];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    if (next_permutation(v, v + n))
        for (int i = 0; i < n; i++)
            cout << v[i] << " ";
    else
        cout << -1;
}