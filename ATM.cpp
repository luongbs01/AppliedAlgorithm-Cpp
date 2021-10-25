#include <bits/stdc++.h>
using namespace std;

void process(unsigned long long w, unsigned long long c);

unsigned long long soTo[10] = {0, 1, 1, 1, 2, 1, 2, 2, 2, 3};
unsigned long long soCach[10] = {0, 1, 1, 1, 2, 1, 2, 1, 1, 2};

int main()
{
    unsigned long long T;
    cin >> T;
    for (unsigned long long i = 0; i < T; i++)
    {
        unsigned long long w;
        unsigned long long c;
        cin >> w >> c;
        if (w / 1000 * 1000 != w || w <= 0)
        {
            cout << 0 << endl;
        }
        else
        {
            if (c > floor(log10(w / 1000)))
                c = floor(log10(w / 1000));
            process(w, c);
        }
    }
}

void process(unsigned long long w, unsigned long long c)
{
    unsigned long long temp, n = 0, s = 1;
    vector<unsigned long long> value;
    for (unsigned long long i = 0; i <= c; i++)
    {
        value.push_back(pow(10, i) * 1000);
        value.push_back(pow(10, i) * 2000);
        value.push_back(pow(10, i) * 3000);
        value.push_back(pow(10, i) * 5000);
    }
    c = 0;
    while (value[c] <= w)
        c++;
    reverse(value.begin(), value.begin() + c);
    temp = w / value[0];
    s *= 1;
    n += temp;
    w -= temp * value[0];
    if (w / 1000 != 0)
        c = floor(log10(w / 1000));
    for (unsigned long long i = c; i >= 0; i--)
    {
        temp = w / pow(10, i) / 1000;
        n += soTo[temp];
        if (soCach[temp] != 0)
            s *= soCach[temp];
        w -= temp * pow(10, i) * 1000;
        if (w == 0) break;
    }
    cout << n << ' ' << s << endl;
}