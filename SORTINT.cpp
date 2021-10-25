#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n, a;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> a;
        v[i] = a;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    system("pause");
}