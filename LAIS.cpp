#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0; 
    cin >> n;
    vector<int> a(n), iMem(n, 1);
    cin >> a[0];
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < i; j++) {
            if (abs(a[j]) < abs(a[i]) && a[j] * a[i] < 0)
                iMem[i] = max(iMem[i], iMem[j] + 1);
        }
        ans = max(ans, iMem[i]);
    }
    cout << ans;
    system("pause");
}