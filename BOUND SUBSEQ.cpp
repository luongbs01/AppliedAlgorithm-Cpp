#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, M;
    long long T, ans;
    cin >> n >> m >> M;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        T = 0;
        for (int j = i; j < n; j++) {
            T += a[j];
            if (T >= m && T <= M)
                ans++;
        }
    }
    cout << ans;
}