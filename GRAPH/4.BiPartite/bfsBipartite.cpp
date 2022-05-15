#include <bits/stdc++.h>
using namespace std;

void printQueue(queue<int> Q)
{
    cout << " Q:: ";
    while (!Q.empty())
    {
        cout << Q.front() << " ";
        Q.pop();
    }
    cout << "-" << endl;
}

int oppositeColor(int color)
{
    return (1 - color);
}

bool isBipartite(int src, vector<int> Adj[], int color[])
{
    queue<int> Q;
    Q.push(src);
    color[src] = 1;
    cout << "source " << src << " colored 1" << endl;
    while (!Q.empty())
    {
        int curr = Q.front();
        cout << "curr = " << curr << endl;
        Q.pop();
        printQueue(Q);
        for (auto neighbor : Adj[curr])
        {
            if (color[neighbor] == -1)
            {
                cout << "  neighbor = " << neighbor << endl;
                color[neighbor] = oppositeColor(color[curr]);
                cout << "  " << neighbor << " colored " << color[neighbor] << endl;
                Q.push(neighbor);
                printQueue(Q);
            }
            else if (color[neighbor] == color[curr])
            {
                cout << "MISMATCH FOUND" << endl;
                return false;
            }
        }
    }
    return true;
}

bool checkBipartite(vector<int> Adj[], int V)
{
    int color[V];
    memset(color, -1, sizeof(color)); // Mark ALL as NOT Colored
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1) // if NOT Colored
        {
            if (!isBipartite(i, Adj, color))
                return false;
        }
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

Checking....
source 0 colored 1
curr = 0
 Q:: -
  neighbor = 1
  1 colored 0
 Q:: 1 -
curr = 1
 Q:: -
  neighbor = 2
  2 colored 1
 Q:: 2 -
  neighbor = 7
  7 colored 1
 Q:: 2 7 -
curr = 2
 Q:: 7 -
  neighbor = 3
  3 colored 0
 Q:: 7 3 -
curr = 7
 Q:: 3 -
  neighbor = 6
  6 colored 0
 Q:: 3 6 -
curr = 3
 Q:: 6 -
  neighbor = 4
  4 colored 1
 Q:: 6 4 -
curr = 6
 Q:: 4 -
curr = 4
 Q:: -
  neighbor = 5
  5 colored 0
 Q:: 5 -
curr = 5
 Q:: -
BIPARTITE


*/

/*
7 7
0 1
1 2
2 3
3 4
4 6
6 1
4 5

Checking....
source 0 colored 1
curr = 0
 Q:: -
  neighbor = 1
  1 colored 0
 Q:: 1 -
curr = 1
 Q:: -
  neighbor = 2
  2 colored 1
 Q:: 2 -
  neighbor = 6
  6 colored 1
 Q:: 2 6 -
curr = 2
 Q:: 6 -
  neighbor = 3
  3 colored 0
 Q:: 6 3 -
curr = 6
 Q:: 3 -
  neighbor = 4
  4 colored 0
 Q:: 3 4 -
curr = 3
 Q:: 4 -
MISMATCH FOUND
NOT BIPARTITE

*/