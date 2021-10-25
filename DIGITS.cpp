#include <bits/stdc++.h>
using namespace std;

vector<int> v(10);
vector<int> mark(10, 0);
int n, ans;

void TRY(int k);

int main()
{
    cin >> n;
    TRY(1);
    cout << ans;
    system("pause");
    return 0;
}

void TRY(int k)
{
    if (k > 7)
    {
        if ((1000 * v[4] + 100 * (v[1] + v[5] - v[7]) + 10 * (v[2] + v[6] - 6) + (2 * v[3] - 2)) == n)
            ans++;
    }
    else
    {
        for (int i = 1; i <= 9; i++)
        {
            if (mark[i] == 0)
            {
                mark[i] = 1;
                v[k] = i;
                TRY(k + 1);
                mark[i] = 0;
            }
        }
    }
}