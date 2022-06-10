#include <bits/stdc++.h>
using namespace std;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

#define MP make_pair
#define INF INT_MAX

/* Optimal Prim's MST (using Min-Heap) */
vector<int> primsMST(int V, vector<pair<int, int>> Adj[])
{
    // Create & initialize the 3 arrays: key[], mst[], parent[]
    vector<int> key(V, INF), inMST(V, false), parent(V, -1);

    // pair => { key[node] , node}
    min_heap<pair<int, int>> mH;

    // Src. node='0' has key=0. Add it to Heap
    key[0] = 0;
    mH.push({0, 0});

    for (int cnt = 0; cnt < V - 1; cnt++)
    {
        int curr = mH.top().second;
        inMST[curr] = true;
        mH.pop();

        for (auto &[neighbor, edge_wt] : Adj[curr])
        {
            if (!inMST[neighbor] && edge_wt < key[neighbor])
            {
                parent[neighbor] = curr;
                key[neighbor] = edge_wt;
                mH.push({key[neighbor], neighbor});
            }
        }
    }
    return parent;
}

int main()
{
    /*  Example 2:: =============================================*/

    int V = 6, E = 9;
    vector<pair<int, int>> Adj[V];

    Adj[0] = {MP(1, 2), MP(3, 1), MP(4, 4)};
    Adj[1] = {MP(0, 2), MP(2, 3), MP(3, 3), MP(5, 3)};
    Adj[2] = {MP(1, 3), MP(3, 5), MP(5, 8)};
    Adj[3] = {MP(0, 1), MP(1, 3), MP(2, 5), MP(4, 9)};
    Adj[4] = {MP(0, 4), MP(3, 9)};
    Adj[5] = {MP(1, 7), MP(2, 8)};

    /*===========================================================*/
    /*  Print Graph i.e. "Adj" */

    // for (auto node = 0; node < V; node++)
    // {
    //     cout << "Node: " << node << endl;
    //     for (auto &itr : Adj[node])
    //     {
    //         cout << "\tnb = " << itr.first << "\twt = " << itr.second << endl;
    //     }
    // }
    /*===========================================================*/

    // Print Answer
    auto parent = primsMST(V, Adj);
    for (int i = 0; i < V; i++)
        cout << i << " has parent " << parent[i] << " in MST" << endl;

    return 0;
}

/* Example 1:: =============================================*/

// int V = 5, E = 6;
// vector<pair<int, int>> Adj[V];

// Adj[0] = {MP(1, 2), MP(3, 6)};
// Adj[1] = {MP(0, 2), MP(2, 3), MP(3, 8), MP(4, 5)};
// Adj[2] = {MP(1, 3), MP(4, 7)};
// Adj[3] = {MP(0, 6), MP(1, 8)};
// Adj[4] = {MP(1, 5), MP(2, 7)};

/* Brute Prim's MST (Traverse key[] array every time) */
// vector<int> primsMST(int V, vector<pair<int, int>> Adj[])
// {
//     // Create & initialize the 3 arrays: key[], mst[], parent[]
//     vector<int> key(V, INF), inMST(V, false), parent(V, -1);

//     key[0] = 0;

//     for (int cnt = 0; cnt < V - 1; cnt++)
//     {
//         int minKey = INT_MAX;
//         int curr;

//         // Find new "curr" node which is NOT part of MST
//         // and has the SMALLEST cost edge
//         for (int node = 0; node < V; node++)
//         {
//             if (!inMST[node] && key[node] < minKey)
//             {
//                 minKey = key[node];
//                 curr = node;
//             }
//         }
//         // Add "curr" node to MST
//         inMST[curr] = true;

//         for (auto &itr : Adj[curr])
//         {
//             int neighbor = itr.first;
//             int edge_wt = itr.second;
//             if (!inMST[neighbor] && edge_wt < key[neighbor])
//             {
//                 key[neighbor] = edge_wt;
//                 parent[neighbor] = curr;
//             }
//         }
//     }

//     return parent;
// }
