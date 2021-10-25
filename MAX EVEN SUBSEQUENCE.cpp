#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    long long ans = LONG_LONG_MIN;
    cin >> n;
    vector<long long> a(n), iMem(n), jMem(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        vector<long long> iMem(n);
        iMem[i] = a[i];
        if (iMem[i] % 2 == 0)
            ans = max(ans, iMem[i]);
        for (int j = i + 1; i < n; i++)
        {
            iMem[j] = max(a[j], iMem[j - 1] + a[j]);
            if (iMem[j] % 2 == 0)
                ans = max(ans, iMem[j]);
        }
    }

    if (ans > LONG_LONG_MIN)
        cout << ans;
    else
        cout << "NOT_FOUND";
}