#include <bits/stdc++.h>
using namespace std;

bool checkCycle(int node, int par, vector<int> &vis, vector<int> Adj[])
{
    vis[node] = 1;
    for (auto it : Adj[node])
    {
        if (!vis[it]){
            cout<<"  dfs("<<it<<","<<node<<")"<<endl;
            if (checkCycle(it, node, vis, Adj))
                return true;
        }
        else if (it != par)
            return true;
    }
    return false;
}

bool isCycle(int V, vector<int> Adj[])
{
    vector<int> vis(V + 1, 0);
    for (int i = 1; i <= V; i++){
        if (!vis[i]){
            cout<<"\nVisit new Component from "<<i<<endl;
            if (checkCycle(i, -1, vis, Adj))
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

/* OUTPUT:

Visit new Component from 1
 node: 1, par: -1
  dfs(2)
 node: 2, par: 1
  dfs(4)
 node: 4, par: 2

Visit new Component from 3
 node: 3, par: -1
  dfs(5)
 node: 5, par: 3
  dfs(6)
 node: 6, par: 5
  dfs(7)
 node: 7, par: 6
  dfs(8)
 node: 8, par: 7
  dfs(9)
 node: 9, par: 8
  dfs(10)
 node: 10, par: 9

Graph contains Cycle

*/