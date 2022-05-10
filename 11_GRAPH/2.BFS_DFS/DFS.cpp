#include <bits/stdc++.h>
using namespace std;

void dfs(int curr, vector<vector<int>> &Adj, vector<bool> &visited, vector<int> &compDfs)
{
    compDfs.push_back(curr);
    visited[curr] = true;
    for (auto &neighbor : Adj[curr])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, Adj, visited, compDfs);
        }
    }
}

vector<vector<int>> dfsOfGraph(vector<vector<int>> &Adj)
{
    int V = Adj.size();
    vector<bool> visited(V, false);

    vector<vector<int>> ans;
    for (int node = 0; node < Adj.size(); node++)
    {
        if (!visited[node])
        {
            vector<int> dfsComp;
            dfs(node, Adj, visited, dfsComp);
            ans.push_back(dfsComp);
        }
    }

    return ans;
}

/*===================================================================================*/

int main()
{
    //-----------------------------------------

    int V = 12;
    vector<vector<int>> Adj(V);
    Adj[0] = {};
    Adj[1] = {2};
    Adj[2] = {1, 4};
    Adj[3] = {5};
    Adj[4] = {2};
    Adj[5] = {3, 6, 10};
    Adj[6] = {5, 7};
    Adj[7] = {6, 8};
    Adj[8] = {7, 9, 11};
    Adj[9] = {8, 10};
    Adj[10] = {5, 9};
    Adj[11] = {8};

    //-----------------------------------------

    cout << "DFS::" << endl;
    auto graphDFS = dfsOfGraph(Adj);
    for (auto &compDFS : graphDFS)
    {
        for (auto &node : compDFS)
            cout << node << " ";
        cout << endl;
    }
    cout << endl;

    //-----------------------------------------

    return 0;
}