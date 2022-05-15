// Representation of Undirected Graph using vector

#include <iostream>
#include <vector>
using namespace std;

// Add an edge in Undirected Graph.
void AddEdge(vector<int> Adj[], int u, int v)
{
    Adj[u].push_back(v);
    Adj[v].push_back(u);
}

// Print the Adj. List representation of Graph
void PrintGraph(vector<int> Adj[], int n)
{
    cout << "\nAdjacency Lists of Vertices:" << endl;
    for (int v = 0; v < n; v++)
    {
        cout << "vertex " << v << " :  ";

        for (auto x : Adj[v]) //Traverse list of that vertex
            cout << x << " -> ";

        cout << "-" << endl;
    }
}

// Driver code
int main()
{
    // No. of Vertices
    int n = 5;

    //Create Graph
    vector<int> Adj[n];

    AddEdge(Adj, 0, 1);
    AddEdge(Adj, 0, 4);
    AddEdge(Adj, 1, 2);
    AddEdge(Adj, 1, 3);
    AddEdge(Adj, 1, 4);
    AddEdge(Adj, 2, 3);
    AddEdge(Adj, 3, 4);

    PrintGraph(Adj, n);

    return 0;
}