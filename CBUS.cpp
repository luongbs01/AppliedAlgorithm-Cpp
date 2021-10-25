#include <bits/stdc++.h>
using namespace std;

int c[23][23];
int mark[12]; //danh dau cac diem da di qua
int n, k, a;
int best = INT_MAX; //chi phi nho nhat
int curr; //chi phi hien tai
int x[12];

void TRY(int t);
int main()
{
    cin >> n >> k;
    for (int i = 0; i <= 2 * n; i++)
        for (int j = 0; j <= 2 * n; j++)
            cin >> c[i][j];
    x[0] -= n;
    TRY(1);
    cout << best;
    system("pause");
    return 0;
}

void TRY(int t)
{
    for (int i = 1; i <= n; i++)
    {
        if (t > n)
        {
            if (curr + c[x[t - 1] + n][0] < best) 
                best = curr +  c[x[t - 1] + n][0];
        }
        else
        {
            if (mark[i] == 0)
            {
                x[t] = i;
                mark[i] = 1;
                curr += c[x[t - 1] + n][i] + c[i][i + n];
                if (curr < best) TRY(t + 1);
                curr -= (c[x[t - 1] + n][i] + c[i][i + n]);
                mark[i] = 0;
            }
        }
    }
}