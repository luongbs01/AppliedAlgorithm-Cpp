#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int c);
vector<int> Adj[2005];
vector<int> color(2005, -1);
bool ans;

int main()
{
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int bugs, interactions;
        cin >> bugs >> interactions;
        for (int j = 1; j <= bugs; j++)
        {
            Adj[j].clear();
            color[j] = -1;
        }
        int first, second;
        for (int j = 1; j <= interactions; j++)
        {
            cin >> first >> second;
            Adj[first].push_back(second);
            Adj[second].push_back(first);
        }
        ans = true;
        for (int j = 1; j <= bugs; j++)
        {
            if (color[j] == -1)
            {
                dfs(j, 0);
            }
        }
        cout << "Scenario #" << i + 1 << ":" << endl;
        if (ans)
            cout << "No suspicious bugs found!" << endl;
        else
            cout << "Suspicious bugs found!" << endl;
    }
}

void dfs(int u, int c)
{ //tham dinh u, to mau c
    color[u] = c;
    for (int i = 0; i < Adj[u].size(); i++)
    {
        int v = Adj[u][i];
        if (color[v] != -1 && color[u] == color[v])
        {
            ans = false;
            return;
        }
        if (color[v] == -1)
        {
            dfs(v, 1 - c);
        }
    }
}