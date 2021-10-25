#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    bool check = true;
    cin >> n >> m >> k;
    vector<int> v(m + 1);
    for (int i = 0; i < m; i++)
    {
        v[i] = i + 1;
    }
    v[m] = n + 1;
    for (int i = 0; i < k - 1; i++)
    {
        int pos = m - 1;
        while (v[pos + 1] - v[pos] <= 1 && pos >= 0)
        {
            pos--;
        }
        if (pos == -1)
        {
            check = false;
            cout << -1;
            break;
        }
        else
        {
            v[pos] = v[pos] + 1;
            for (int i = pos + 1; i < m; i++)
            v[i] = v[pos] + i - pos;
        }
    }
    if (check) 
        for (int i = 0; i < m; i++)
            cout << v[i] << " ";
    system("pause");
    return 0;
}