#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ans = INT_MIN;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());
    for (int i = 0; i < n; i++)
        ans = max(ans, t[i] + i + 1);
    cout << ans + 1;
}