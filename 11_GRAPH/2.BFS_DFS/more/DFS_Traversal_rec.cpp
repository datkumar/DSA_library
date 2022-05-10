// Program to Print BFS traversal from a given source vertex (DIRECTED Graph)
#include <iostream>
#include <list>
#include <stack>
#include <map>

using namespace std;

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    map<int, list<int>> Adj; // key = vertex ; value = Adj.-List of that vertex

    map<int, bool> visited; // key = vertex ; value = T/F(visited or not)

public:
    // Add an edge to graph
    void addEdge(int u, int v)
    {
        Adj[u].push_back(v); // Add v to u’s list.
    }

    // Prints BFS traversal from a given source s
    void DFS(int root);
};

// Print DFS traversal from a given source vertex 'root'
void Graph ::DFS(int root)
{
    // Mark the current node as visited & print it
    visited[root] = true;
    cout << root << " ";

    // Recur for all vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = Adj[root].begin(); i != Adj[root].end(); i++)
    {
        if (!visited[*i])
            DFS(*i);
    }
}

// Driver program
int main()
{
    // Create a graph
    Graph g;

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "BFS Traversal (starting from vertex 2) : ";
    g.DFS(2);

    return 0;
}