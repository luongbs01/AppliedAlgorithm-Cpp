#include <bits/stdc++.h>
using namespace std;

int numberOfPeople(double x, vector<double> s, int n);

double PI = acos(-1);

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n, f;
        cin >> n >> f;
        vector<double> r(n), s(n);
        for (int i = 0; i < n; i++)
        {
            cin >> r[i];
            s[i] = PI * r[i] * r[i];
        }
        sort(s.begin(), s.begin() + n);
        double low = 0, high = s[n - 1], mid;
        while (high - low > 0.000001)
        {
            mid = (high + low) / 2;
            if (numberOfPeople(mid, s, n) > f)
                low = mid;
            else
                high = mid;
        }
        printf("%.6f\n", low);
    }
}

int numberOfPeople(double x, vector<double> s, int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (int)(s[i] / x);
    }
    return ans;
}