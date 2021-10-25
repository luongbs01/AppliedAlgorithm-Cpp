#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, ans = 0;
    cin >> n >> m;
    n++;
    m++;
    vector<int> X(n);
    vector<int> Y(m);
    vector<int> iMem[n];
    for (int i = 0; i < n; i++)
        iMem[i].resize(m, 0);
    for (int i = 1; i < n; i++)
        cin >> X[i];
    for (int i = 1; i < m; i++)
        cin >> Y[i];
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (X[i] == Y[j])
            {
                iMem[i][j] = max(max(iMem[i - 1][j], iMem[i][j - 1]), iMem[i - 1][j - 1] + 1);
            }
            else
            {
                iMem[i][j] = max(iMem[i - 1][j], iMem[i][j - 1]);
            }
            ans = max(ans, iMem[i][j]);
        }
    }
    cout << ans;
}