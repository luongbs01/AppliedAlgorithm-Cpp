#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, tmp, ans = 0;
    vector<int> d, count(20, 0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        count[tmp]++;
    }
    ans += count[6];
    ans += count[5];
    count[1] = max(0, count[1] - count[5]);
    ans += count[4];
    count[2] = max(0, count[2] - count[4]);
    ans += count[3] / 2;
    count[3] %= 2;
    if (count[3] == 1) {
        ans++;
        if (count[2] > 0) {
            count[2]--;
            if (count[1] > 0) count[1]--;
        }
        else {
            count[1] = max(0, count[1] - 3);
        }
    }
    if (count[2] > 0) {
        ans += count[2] / 3;
        count[2] %= 3;
        if (count[2] > 0) {
            ans++;
            count[1] -= max(0, 6 - count[2] * 2);
        }
    }
    if (count[1] > 0) {
        ans += count[1] / 6;
        count[1] %= 6;
        if (count[1] > 0)
            ans++;
    }
    cout << ans;
    system("pause");
}