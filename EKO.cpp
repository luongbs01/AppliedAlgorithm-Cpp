#include <bits/stdc++.h>
using namespace std;

long long amountOfWood(long long m, vector<long long> h, int n);

int main()
{
    int n;
    long long m, max_height = 0;
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    vector<long long> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
        max_height = max(max_height, h[i]);
    }
    long long low = 0, high = max_height, mid;
    while (high - low > 1)
    {
        mid = (high + low) / 2;
        if (amountOfWood(mid, h, n) >= m)
            low = mid;
        else
            high = mid;
    }
    cout << low;
}

long long amountOfWood(long long m, vector<long long> h, int n)
{
    long long ans = 0;
    for (int i = 0; i < n; i++)
        if (h[i] - m > 0)
            ans += (h[i] - m);
    return ans;
}