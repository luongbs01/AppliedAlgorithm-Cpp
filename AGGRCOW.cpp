#include <bits/stdc++.h>
using namespace std;

bool check(long long mid, vector<long long> coordinate, int c, int n);

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, c;
        cin >> n >> c;
        vector<long long> coordinate(n + 1);
        for (int j = 1; j <= n; j++)
            cin >> coordinate[j];
        sort(coordinate.begin() + 1, coordinate.begin() + n + 1);
        long long low = 0, high = coordinate[n] - coordinate[1], mid;
        while (low <= high)
        {
            mid = (high + low) / 2;
            if (check(mid, coordinate, c, n))
                low = mid + 1;
            else
                high = mid;
        }
        cout << low << endl;
    }
}

bool check(long long mid, vector<long long> coordinate, int c, int n)
{
    int count = 1, curr = 1;
    for (int i = 2; i <=  c; i++)
    {
        if (coordinate[i] - coordinate[curr] >= mid) {
            curr = i;
            count++;
        }
    }
    if (count == c)
        return true;
    else
        return false;
}