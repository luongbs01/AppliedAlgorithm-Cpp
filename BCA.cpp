#include <bits/stdc++.h>
using namespace std;

int m, n, k, l, o;
int a[11][31];
vector<int> v[31];
int t[11];
int best = INT_MAX;

void TRY(int k);
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> l;
            a[i][l] = 1;
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> o >> l;
        v[o].push_back(l);
        v[l].push_back(o);
    }
    TRY(1);
    cout << best;
    system("pause");
}

void TRY(int k)
{
    for (int i = 1; i <= m; i++)
    {
        if (k > n)
        {   int maxx = 0;
            for (int i = 1; i <= m; i++)
                if (t[i] > maxx)
                    maxx = t[i];
            if (best > maxx)
                best = maxx;
        }
        else
        {
            if (a[i][k] == 1)
            {
                a[i][k] = 2;
                t[i] = t[i] + 1;
                for (int j = 0; j < v[k].size(); j++)
                    if (a[i][v[k][j]] == 1)
                        a[i][v[k][j]] = 2;
                if (t[i] < best) TRY(k + 1);
                a[i][k] = 1;
                t[i] = t[i] - 1;
                for (int j = 0; j < v[k].size(); j++)
                    if (a[i][v[k][j]] == 2)
                        a[i][v[k][j]] = 1;
            }
        }
    }
}