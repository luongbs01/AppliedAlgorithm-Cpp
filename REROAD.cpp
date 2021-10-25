#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, ans = 1, q;
    cin >> n;
    vector<int> t(n);
    cin >> t[0];
    for (int i = 1; i < n; i++) {
        cin >> t[i];
        if (t[i] != t[i-1]) ans++;
    }
    cin >> q;
    int a, b, previous, after;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        previous = after = 0;
        a--;
        if (a == 0) {
            if (t[a] != t[a+1]) previous++;
            t[a] = b;
            if (t[a] != t[a+1]) after++;
            ans += (after-previous);
            cout << ans << endl;
        }
        else if (a == n-1) {
            if (t[a] != t[a-1]) previous++;
            t[a] = b;
            if (t[a] != t[a-1]) after++;
            ans += (after-previous);
            cout << ans << endl;
        }
        else {
            if (t[a] != t[a+1]) previous++;
            if (t[a] != t[a-1]) previous++;
            t[a] = b;
            if (t[a] != t[a+1]) after++;
            if (t[a] != t[a-1]) after++;
            ans += (after-previous);
            cout << ans << endl;
        }
    }
    system("pause");
}