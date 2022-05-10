#include <bits/stdc++.h>
using namespace std;

int oppositeColor(int color)
{
    return (1 - color);
}

bool isBiPart_dfs(int node, vector<int> Adj[], int color[])
{
    for (auto neighbor : Adj[node])
    {
        if (color[neighbor] == -1)
        {
            color[neighbor] = oppositeColor(color[node]);
            if (!isBiPart_dfs(neighbor, Adj, color))
                return false;
            else if (color[neighbor] == color[node])
                return false;
        }
        return true;
    }
}

bool checkBipartite(vector<int> Adj[], int V)
{
    int color[V];
    memset(color, -1, sizeof(color));
    for (int src = 1; src < V; src++)
        if (color[src] == -1)
        {
            color[src] = 1;
            if (!isBiPart_dfs(src, Adj, color))
                return false;
        }
    return true;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> Adj[V];
    
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    cout << "Checking...." << endl;
    if (checkBipartite(Adj, V))
        cout << "BIPARTITE" << endl;

    else
        cout << "NOT BIPARTITE" << endl;

    return 0;
}

/*

8 8
0 1
1 2
2 3
3 4
4 6
6 7
1 7
4 5


7 7
0 1
1 2
2 3
3 4
4 6
6 1
4 5

*/