#include <bits/stdc++.h>
using namespace std;
#define MAX 105

int n, r, c[MAX][MAX];
int best = INT_MAX;
int curr;
int mark[MAX];
int x[MAX];
int y[MAX];
int dem;
//# Ðoc du lieu vào
void input()
{
    cin >> n >> r;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> c[i][j];
        }
    cin.ignore(32767, '\n');
}

void prepare()
{
    best = INT_MAX;
    curr = 0;
    for (int i = 0; i < MAX; i++)
    {
        mark[i] = 0;
        x[i] = 0;
        y[i] = 0;
    }
    int j = 1;
    string s, temp;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            temp += s[i];
        }
        if (s[i] == ' ' || i == s.size() - 1)
        {
            y[j] = atoi(temp.c_str());
            j++;
            temp = "";
        }
    }
    dem = j - 1;
    x[1] = y[1];
}
//# Thuat toán quay lui
void TRY(int k)
{
    if (k == dem)
    {
        if (curr + c[x[k - 1]][y[dem]] < best && (c[x[k - 1]][y[dem]] > 0))
        {
            best = curr + c[x[k - 1]][y[dem]];
        }
    }
    else
    {
        for (int i = 2; i < dem; i++)
        {
            if (mark[y[i]] == 0 && c[x[k - 1]][y[i]] > 0 && curr + c[x[k - 1]][y[i]] < best)
            {
                x[k] = y[i];
                mark[y[i]] = 1;
                curr += c[x[k - 1]][y[i]];
                TRY(k + 1);
                mark[y[i]] = 0;
                curr -= c[x[k - 1]][y[i]];
            }
        }
    }
}

int main()
{
    input();
    for (int i = 0; i < r; i++)
    {
        prepare();
        TRY(2);
        if (best == INT_MAX)
            cout << 0 << endl;
        else
            cout << best << endl;
    }
    return 0;
}