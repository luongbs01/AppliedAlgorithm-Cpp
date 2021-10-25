#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    int pos = n - 1;

    while (pos >= 0)
    {
        if (s[pos] == '1')
        {
            s[pos] = '0';
            pos--;
        }
        else
        {
            s[pos] = '1';
            break;
        }
    }
    if (pos == -1)
        cout << -1;
    else
        cout << s;
    system("pause");
    return 0;
}