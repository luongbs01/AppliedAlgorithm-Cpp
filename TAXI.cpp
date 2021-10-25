#include <bits/stdc++.h>
using namespace std;

int c[23][23];
int mark[12]; //danh dau cac diem da di qua
int n;
int best = INT_MAX; //chi phi nho nhat
int curr; //chi phi hien tai
int x[12];

void TRY(int k);
int main()
{
    cin >> n;
    for (int i = 0; i <= 2 * n; i++)
        for (int j = 0; j <= 2 * n; j++)
            cin >> c[i][j];
    x[0] -= n;
    TRY(1);
    cout << best;
    return 0;
}

void TRY(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (k > n)
        {
            if (curr + c[x[k - 1] + n][0] < best) 
                best = curr +  c[x[k - 1] + n][0];
        }
        else
        {
            if (mark[i] == 0)
            {
                x[k] = i;
                mark[i] = 1;
                curr += c[x[k - 1] + n][i] + c[i][i + n];
                if (curr < best) TRY(k + 1);
                curr -= (c[x[k - 1] + n][i] + c[i][i + n]);
                mark[i] = 0;
            }
        }
    }
}