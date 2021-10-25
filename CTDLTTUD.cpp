#include <bits/stdc++.h>
using namespace std;

vector<int> v(10);
vector<int> mark(10, 0);
int n, ans = 0;

void TRY(int k);

int main()
{
    cin >> n;
    TRY(1);
    cout << ans;
    system("pause");
}

void TRY(int k)
{
    if (k > 6)
    {
        if (100000 * v[1] + 11101 * v[2] + 1001 * v[3] + 100 * v[4] + 10 * v[5] + 10 * v[6] == n)
            ans++;
    }
    else
    {
        if (k <= 2)
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
        else
        {
            for (int i = 0; i <= 9; i++)
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
}
