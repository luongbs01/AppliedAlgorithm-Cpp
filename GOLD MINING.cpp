#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, L1, L2, temp, ans = 0;
    cin >> n >> L1 >> L2;
    vector<int> a(n);
    vector<int> iMem(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    for (int i = 0; i < L1; i++) 
        iMem[i] = a[i];
    for (int i = L1; i < L2; i++) {
        temp = 0;
        for (int j = 0; j < i; j++) 
            temp = max(temp, iMem[j]);
        iMem[i] = temp + a[i];
        ans = max(ans, iMem[i]);
    }
    for (int i = L2; i < n; i++) {
        temp = 0;
        for (int j = i - L2; j <= i - L1; j++) 
            temp = max(temp, iMem[j]);
        iMem[i] = temp + a[i];
        ans = max(ans, iMem[i]);
    }
    cout << ans;
}