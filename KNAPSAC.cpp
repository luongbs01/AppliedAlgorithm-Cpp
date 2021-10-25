#include <bits/stdc++.h>
#define ii pair<int, int>
#define MAX 31
using namespace std;
int n, b, best, curr, a, c, max_scale;
vector<ii> v;
int mark[MAX];
void TRY();
int main()
{
    cin >> n >> b;
    int a, c;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> c;
        v.push_back(make_pair(a, c));
        max_scale = (c / a > max_scale) ? c / a : max_scale;
    }
    TRY();
    cout << best;
    return 0;
}

void TRY()
{
    for (int i = 0; i < n; i++)
    {
        if (a + v[i].first <= b)
        {
            if (mark[i] == 0)
            {
                mark[i] = 1;
                a += v[i].first;
                curr += v[i].second;
                if (curr + max_scale * (b - a) > best) TRY();
                mark[i] = 0;
                a -= v[i].first;
                curr -= v[i].second;
            }
        }
        else
        {
            best = max(best, curr);
        }
    }
}