#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v;
    int wt;
    Edge(const Edge &e) : u(e.u), v(e.v), wt(e.wt) {}
    Edge(int _u, int _v, int _wt) : u(_u), v(_v), wt(_wt) {}
    
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
        // Attach p2 to p1
        Parent[p2] = p1;
        Rank[p1]++;
    }
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

    sort(edges.begin(), edges.end(), compareEdgeWeight);

    // Init. Parent[] & Rank[] arrays
    vector<int> Parent(V);
    for (int i = 1; i < V; i++)
        Parent[i] = i;

    vector<int> Rank(V, 0);

    vector<Edge> mstEdges;
    for (auto edge : edges)
    {
        if (Find(edge.u, Parent) != Find(edge.v, Parent))
        {
            mstEdges.push_back(edge);
            Union(edge.u, edge.v, Parent, Rank);
        }
    }

    int cost = 0;
    for (int i = 0; i < mstEdges.size(); i++)
    {
        
        cout << mstEdges[i].wt << '\t' << mstEdges[i].u << "," << mstEdges[i].v << endl;
        cost += mstEdges[i].wt;
    }
    // for (auto &edge : mstEdges)
    // {
    //     cout << edge.wt << '\t' << edge.u << "," << edge.v << endl;
    //     cost += edge.wt;
    // }
    cout << "\nTotal cost of MST: " << cost << endl;

    return 0;
}
