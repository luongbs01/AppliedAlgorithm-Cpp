#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int iMem[105][505];
    iMem[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = a[i]; j <= m; j++)
        {
            for (int k = 1; k <= j; k++)
            {
                if (k % a[i] == 0)
                {
                    iMem[i][j] = (iMem[i][j] + iMem[i - 1][j - k]) % (1000000007);
                }
            }
        }
    }
    cout << iMem[n][m];
}