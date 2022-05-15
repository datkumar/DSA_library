#include <bits/stdc++.h>
using namespace std;

bool checkCycle(int src, int V, vector<int> Adj[], vector<int> &vis)
{
    queue<pair<int, int>> Q;

    vis[src] = true;
    Q.push({src, -1});
    cout << "\nVisiting new Component from " << src << endl;

    while (!Q.empty())
    {
        int node = Q.front().first;
        int par = Q.front().second;
        cout << " node: " << node << ", par: " << par << endl;
        Q.pop();
        for (auto it : Adj[node])
        {
            if (!vis[it])
            {
                cout << "Visiting " << it << endl;
                vis[it] = true;
                Q.push({it, node});
            }
            else if (par != it)
            {
                cout << "CYCLE detected in this Component" << endl;
                return true;
            }
        }
    }
    cout << "NO CYCLE in this component" << endl;
    return false;
}

bool isCycle(int V, vector<int> Adj[])
{
    vector<int> vis(V, 0);
    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
        {
            if (checkCycle(i, V, Adj, vis))
                return true;
        }
    }

    return false;
}

int main()
{
    int V = 11;
    vector<int> Adj[V + 1] = {
        {},
        {2},
        {1, 4},
        {5},
        {2},
        {3, 6, 10},
        {5, 7},
        {6, 8},
        {7, 9, 11},
        {8, 10},
        {5, 9},
        {8}
    };

    bool ans = isCycle(V, Adj);
    if (ans)
        cout << "\nGraph contains Cycle" << endl;
    else
        cout << "\nGraph does NOT contain Cycle" << endl;

    return 0;
}


/*

Visiting new Component from 1
 node: 1, par: -1
Visiting 2
 node: 2, par: 1
Visiting 4
 node: 4, par: 2
NO CYCLE in this component

Visiting new Component from 3
 node: 3, par: -1
Visiting 5
 node: 5, par: 3
Visiting 6
Visiting 10
 node: 6, par: 5
Visiting 7
 node: 10, par: 5
Visiting 9
 node: 7, par: 6
Visiting 8
 node: 9, par: 10
CYCLE detected in this Component

Graph contains Cycle

*/