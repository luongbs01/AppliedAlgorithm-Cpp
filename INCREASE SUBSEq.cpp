#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0; 
    cin >> n;
    vector<int> a(n), iMem(n, 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i])
                iMem[i] = max(iMem[i], iMem[j] + 1);
        }
        ans = max(ans, iMem[i]);
    }
    cout << ans;
}