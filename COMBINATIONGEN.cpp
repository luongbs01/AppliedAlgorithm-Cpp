#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(m + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
    }
    v[m] = n + 1;
    int pos = m - 1;
    while (v[pos + 1] - v[pos] <= 1 && pos >= 0)
    {
        pos--;
    }
    if (pos == -1)
        cout << -1;
    else
    {
        v[pos] = v[pos] + 1;
        for (int i = pos + 1; i < m; i++)
            v[i] = v[pos] + i - pos;
        for (int i = 0; i < m; i++)
            cout << v[i] << " ";
    }
    system("pause");
    return 0;
}