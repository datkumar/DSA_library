#include <bits/stdc++.h>
using namespace std;

void dfsComp(int node, vector<int> Adj[], vector<int> &vis, vector<int> &dfs){
    dfs.push_back(node);
    vis[node] = 1;
    for (auto it : Adj[node])
        if (!vis[it]){
            cout<<"   dfs("<<it<<")"<<endl;
            dfsComp(it, Adj, vis, dfs);
        }
}
vector<int> DFS_of_Graph(int V, vector<int> Adj[]){
    vector<int> dfs;
    vector<int> vis(V + 1, 0);
    for (int i = 1; i <= V; i++)
        if (!vis[i]){
            cout<<"dfsComp("<<i<<")"<<" called"<<endl;
            dfsComp(i, Adj, vis, dfs);
        }
    return dfs;
}


int main(){
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
    vector<int> ans = DFS_of_Graph(V, Adj);
    for (int x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}

// OUTPUT:
// 1 2 4 3 5 6 7 8 9 10 11 

/*OUTPUT:

dfsComp(1) called
   dfs(2)
   dfs(4)
dfsComp(3) called
   dfs(5)
   dfs(6)
   dfs(7)
   dfs(8)
   dfs(9)
   dfs(10)
   dfs(11)
1 2 4 3 5 6 7 8 9 10 11

*/