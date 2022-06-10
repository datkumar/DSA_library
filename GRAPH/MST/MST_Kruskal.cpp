#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v;
    int wt;
    Edge(int _u, int _v, int _wt) : u(_u), v(_v), wt(_wt) {}
    Edge(const Edge &e) : u(e.u), v(e.v), wt(e.wt) {}
};

bool compareEdgeWeight(Edge e1, Edge e2)
{
    return e1.wt < e2.wt;
}

int Find(int a, vector<int> &Parent)
{
    if (a == Parent[a])
        return a;

    return Parent[a] = Find(Parent[a], Parent);
}

void Union(int a, int b, vector<int> &Parent, vector<int> &Rank)
{
    int p1 = Find(a, Parent), p2 = Find(b, Parent);

    if (Rank[p1] < Rank[p2])
        Parent[p1] = p2;

    else if (Rank[p2] < Rank[p1])
        Parent[p2] = p1;

    else // Both have EQUAL Rank
    {
        Parent[p2] = p1; // Attach p2 to p1
        Rank[p1]++;      // Inc. Rank of p1
    }
}

vector<Edge> KruskalMST(int V, vector<Edge> &edges)
{
    // Create Parent[] & Rank[] arrays for DSU
    vector<int> Parent(V), Rank(V, 0);
    // At start, every node is parent of itself
    for (int i = 1; i < V; i++)
        Parent[i] = i;

    vector<Edge> mstEdges; // To store answer i.e. the MST

    // Sort Edges by their Weight
    sort(edges.begin(), edges.end(), compareEdgeWeight);
    // Iterate over the Sorted Edges
    for (auto curr_edge : edges)
    {
        // When the two ends of current edge DON'T have same Parent
        // i.e. they belong to DIFFERENT COMPONENTS
        if (Find(curr_edge.u, Parent) != Find(curr_edge.v, Parent))
        {
            // Add current edge to MST
            mstEdges.push_back(curr_edge);

            Union(curr_edge.u, curr_edge.v, Parent, Rank);
        }
    }
    return mstEdges;
}

int main()
{
    vector<Edge> edges;
    edges.push_back(Edge(0, 3, 10));
    edges.push_back(Edge(1, 4, 1));
    edges.push_back(Edge(1, 2, 2));
    edges.push_back(Edge(1, 5, 4));
    edges.push_back(Edge(2, 3, 3));
    edges.push_back(Edge(2, 4, 3));
    edges.push_back(Edge(2, 6, 7));
    edges.push_back(Edge(3, 4, 5));
    edges.push_back(Edge(3, 6, 8));
    edges.push_back(Edge(4, 5, 9));

    int V = 7;
    int E = edges.size();

    vector<Edge> mstEdges = KruskalMST(V, edges);

    int cost = 0;
    cout << "The MST includes the following edges::" << endl;
    cout << endl;
    cout << "wt" << "\tu,v" << endl;
    cout << endl;
    for (auto &edge : mstEdges)
    {
        cout << edge.wt << '\t' << edge.u << "," << edge.v << endl;
        cost += edge.wt;
    }
    cout << "\nTotal cost of MST: " << cost << endl;

    return 0;
}
