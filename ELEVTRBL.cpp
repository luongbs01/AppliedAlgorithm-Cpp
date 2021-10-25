#include <bits/stdc++.h>
using namespace std;

int main()
{
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    vector<int> Adj[f + 1];
    vector<int> iDist(f + 1, -1);
    for (int i = 1; i <= f; i++)
    {
        if (i - d >= 1)
            Adj[i].push_back(i - d);
        if (i + u <= f)
            Adj[i].push_back(i + u);
    }
    queue<int> Q;
    Q.push(s);
    iDist[s] = 0;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int i = 0; i < Adj[u].size(); ++i)
        {
            int v = Adj[u][i];
            if (iDist[v] == -1)
            {
                Q.push(v);
                iDist[v] = 1 + iDist[u];
            }
        }
    }
    if (iDist[g] != -1)
        cout << iDist[g] << endl;
    else
        cout << "use the stairs";
}