#include <bits/stdc++.h>
using namespace std;

int a[1005], t[1005];

int main()
{
    int n, T, D;
    cin >> n >> T >> D;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    int iMem[1005][105];
    iMem[0][0] = 0;
    a[0] = 0;
    t[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= T; k++)
        {
            for (int j = i - 1; j >= max(0, i - D); j--)
            {
                if (k >= t[i])
                {
                    iMem[i][k] = max(iMem[i][k], iMem[j][k - t[i]] + a[i]);
                }
            }
        }
    }
    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, iMem[i][T]);
    }
    cout << ans;
}