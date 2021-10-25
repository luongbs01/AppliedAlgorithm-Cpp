#include <iostream>

using namespace std;

int k1, k2, ans = 0;

bool kt(string s)
{
    int len = s.size(), count1 = 0, count0 = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '1')
            count1++;
        else
            count0++;
        if (s[i] != s[i + 1])
        {
            if ((count0 >= 2))
                return false;
            if (count1 < k1 && s[i] == '1')
                return false;
            if (count1 > k2)
                return false;
            count0 = 0;
            count1 = 0;
        }
    }
    return true;
}

void dequy(int n, string s)
{
    if (n == 0)
    {
        if (kt(s))
            ans++;
    }
    else
    {   
        if (kt(s) == false && s.size() > k2) return;
        else 
        for (int i = 0; i <= 1; i++)
        {
            dequy(n - 1, s + char(i + '0'));
        }
    }
}
int main()
{
    int n;
    cin >> n >> k1 >> k2;
    dequy(n, "");
    cout << ans;
    system("pause");
}