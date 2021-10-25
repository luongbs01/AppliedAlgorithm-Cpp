#include <bits/stdc++.h>
using namespace std;

int n, K, Q;      // n clients, K trucks, each has capacity Q
int d[11];        // number of packages clients i needs
vector<int> v[6]; // indexes of clients which truck i has delivered so far
set< vector< vector<int> > > s;
int t[6]; // total packages truck i has delivered so far
long long ans;

void TRY(int k);
int Factorial(int n);

int main()
{
    cin >> n >> K >> Q;
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    TRY(1);
    cout << ans % 1000000007;
    system("pause");
}

void TRY(int k) // the k-th client -> d[k]
{
    if (k > n)
    {
        int check = 1;
        for (int i = 1; i <= K; i++)
            if (v[i].empty())
            {
                check = 0;
                break;
            }
        if (check == 1)
        {
            int temp = 1;
            vector< vector<int> > vec;
            for (int i = 1; i <= K; i++)
            {
                vec.push_back(v[i]);
                temp *= Factorial(v[i].size());
            }
            if (s.find(vec) != s.end()) return;
            else 
            {
                s.insert(vec);
                ans += temp;
            }
        }
    }
    else
    {
        for (int i = 1; i <= K; i++)
        { // choose one of K trucks
            if (t[i] + d[k] <= Q)
            {
                t[i] += d[k];
                v[i].push_back(k);
                TRY(k + 1);
                t[i] -= d[k];
                v[i].pop_back();
            }
        }
    }
}
int Factorial(int n)
{
    int ans = 1;
    for (int i = 2; i <= n; i++)
        ans *= i;
    return ans;
}
