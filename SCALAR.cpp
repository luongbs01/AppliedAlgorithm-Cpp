#include <bits/stdc++.h>
using namespace std;

long long ans(long long n)
{
    long long answer = 0;
    vector<long long> x(n);
    vector<long long> y(n);
    for (long long i = 0; i < n; i++)
        cin >> x[i];
    for (long long i = 0; i < n; i++)
        cin >> y[i];
    sort(x.begin(), x.begin() + n);
    sort(y.begin(), y.begin() + n);
    for (long long i = 0; i < n; i++)
    {
        answer += x[i] * y[n - i - 1];
    }
    return answer;
}

int main()
{
    long long T, n, answer;
    cin >> T;
    for (long long i = 0; i < T; i++)
    {
        cin >> n;
        answer = ans(n);
        cout << "Case #" << i + 1 << ": " << answer << endl;
    }
}