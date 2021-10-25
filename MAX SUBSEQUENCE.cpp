#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ans;
    cin >> n;
    vector<int> a(n), iMem(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    iMem[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        iMem[i] = max(a[i], iMem[i - 1] + a[i]);
        ans = max(ans, iMem[i]);
    }
    cout << ans;
}