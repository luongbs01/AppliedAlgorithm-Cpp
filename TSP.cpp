#include <bits/stdc++.h>
using namespace std;
#define MAX 21

int n, m, c[MAX][MAX];
int cmin = INT_MAX;
int best = INT_MAX;
int curr;
int mark[MAX];
int x[MAX];

void input()
{
    cin >> n >> m;
    int j, k;
    for (int i = 1; i <= m; ++i)
    {
        cin >> j >> k;
        cin >> c[j][k];
        cmin = min(cmin, c[j][k]);
    }
}

void TRY(int k)
{
    if (k == n + 1)
    {
        if (curr + c[x[k - 1]][x[1]] < best && c[x[k - 1]][x[1]] > 0)
        {
            best = curr + c[x[k - 1]][x[1]];
        }
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            if (mark[i] == 0 && c[x[k - 1]][i] > 0 && curr + c[x[k - 1]][i] < best)
            {
                x[k] = i;
                mark[i] = 1;
                curr += c[x[k - 1]][i];
                if (curr + cmin * (n - k + 1) < best)
                    TRY(k + 1);
                mark[i] = 0;
                curr -= c[x[k - 1]][i];
            }
        }
    }
}

int main()
{
    input();
    x[1] = 1;
    TRY(2);
    cout << best;
    system("pause");
    return 0;
}