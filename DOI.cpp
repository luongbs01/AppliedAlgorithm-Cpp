#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, count = 1, pos = 1, doi = INT_MIN, lung = INT_MIN;
    bool inc;
    cin >> n;
    vector<int> change(n);
    vector<int> v;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    change[0] = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if ((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]))
        {
            if (a[i] > a[i - 1] && a[i] > a[i + 1] && pos == 1)
                inc = true;
            else
                inc = false;
            change[pos] = i;
            pos++;
        }
    }
    change[pos++] = n - 1;
    for (int i = 1; i < pos - 1; i++)
    {
        v.push_back(min(change[i] - change[i - 1], change[i + 1] - change[i]));
    }
    for (int i = 1; i < v.size(); i += 2)
        doi = max(doi, v[i]);
    for (int i = 0; i < v.size(); i += 2)
        lung = max(lung, v[i]);
    if (doi == INT_MIN)
        doi = 0;
    if (lung == INT_MIN)
        lung = 0;
    if (!inc)
        cout << doi << " " << lung;
    else
        cout << lung << " " << doi;
}