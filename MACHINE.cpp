#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, s, t, sizeOfArray = 0, temp = 0, ans = 0;
    bool hasAnswer = false;
    vector<pair<int, int>> sortedByStartingTime, sortedByTerminatingTime;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &s, &t);
        sizeOfArray = max(sizeOfArray, s);
        sortedByStartingTime.push_back(pair<int, int>(s, t));
        sortedByTerminatingTime.push_back(pair<int, int>(t, s));
    }
    sizeOfArray++;
    sort(sortedByTerminatingTime.begin(), sortedByTerminatingTime.end());
    reverse(sortedByTerminatingTime.begin(), sortedByTerminatingTime.end());
    vector<int> startFrom(sizeOfArray, 0), endBefore(sizeOfArray, 0);
    for (vector<pair<int, int>>::iterator it = sortedByStartingTime.begin(); it != sortedByStartingTime.end(); it++)
    {
        temp = max(temp, (*it).second - (*it).first);
        startFrom[(*it).first] = temp;
    }
    for (int i = sizeOfArray - 2; i >= 0; i--)
        if (startFrom[i] == 0)
            startFrom[i] = startFrom[i + 1];
    temp = 0;
    for (vector<pair<int, int>>::iterator it = sortedByTerminatingTime.begin(); it != sortedByTerminatingTime.end(); it++)
    {
        if ((*it).first + 1 < sizeOfArray)
        {
            temp = max(temp, (*it).first - (*it).second);
            endBefore[(*it).first + 1] = (*it).first - (*it).second;
        }
    }
    for (int i = 0; i < sizeOfArray; i++)
    {
        ans = max(ans, startFrom[i] + endBefore[i]);
        if (startFrom[i] != 0)
            hasAnswer = true;
    }
    if (hasAnswer)
        cout << ans;
    else
        cout << -1;
}