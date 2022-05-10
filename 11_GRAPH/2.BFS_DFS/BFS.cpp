#include <bits/stdc++.h>
using namespace std;

void printQueue(queue<int> Q)
{
    cout << "Q:: ";
    while (!Q.empty())
    {
        cout << Q.front() << " ";
        Q.pop();
    }
    cout << "-" << endl;
}

void bfs(int src, vector<int> Adj[], vector<int> &vis, vector<int> &ans)
{
    cout << "\nVisiting new Component from " << src << endl;
    queue<int> Q;
    Q.push(src);
    vis[src] = 1;
    printQueue(Q);
    while (!Q.empty())
    {
        printQueue(Q);
        int curr = Q.front();
        Q.pop();
        
        cout << " Visiting " << curr << endl;
        ans.push_back(curr);
        printQueue(Q);
        
        for (auto neighbor : Adj[curr])
        {
            if (!vis[neighbor])
            {
                Q.push(neighbor);
                vis[neighbor] = 1;
                printQueue(Q);
            }
        }
    }
}

vector<int> bfsAllComp(int V, vector<int> Adj[])
{
    vector<int> ans;
    vector<int> vis(V + 1, 0);
    for (int i = 1; i <= V; i++)
        if (!vis[i])
            bfs(i, Adj, vis, ans);
    cout << endl
         << endl;
    return ans;
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
        {8}};

    vector<int> ans = bfsAllComp(V, Adj);
    for (int x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}

/*
    OUTPUT: 1 2 4 3 5 6 10 7 9 8 11

(base) kumar@:2.BFS_DFS$ g++ BFS.cpp 
(base) kumar@:2.BFS_DFS$ ./a.out 

Visiting new Component from 1
Q:: 1 -
Q:: 1 -
 Visiting 1
Q:: -
Q:: 2 -
Q:: 2 -
 Visiting 2
Q:: -
Q:: 4 -
Q:: 4 -
 Visiting 4
Q:: -

Visiting new Component from 3
Q:: 3 -
Q:: 3 -
 Visiting 3
Q:: -
Q:: 5 -
Q:: 5 -
 Visiting 5
Q:: -
Q:: 6 -
Q:: 6 10 -
Q:: 6 10 -
 Visiting 6
Q:: 10 -
Q:: 10 7 -
Q:: 10 7 -
 Visiting 10
Q:: 7 -
Q:: 7 9 -
Q:: 7 9 -
 Visiting 7
Q:: 9 -
Q:: 9 8 -
Q:: 9 8 -
 Visiting 9
Q:: 8 -
Q:: 8 -
 Visiting 8
Q:: -
Q:: 11 -
Q:: 11 -
 Visiting 11
Q:: -


1 2 4 3 5 6 10 7 9 8 11 


*/