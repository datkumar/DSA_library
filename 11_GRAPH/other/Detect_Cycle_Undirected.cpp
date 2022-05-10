// Program to Detect Cycle in an Undirected Graph
#include <iostream>
#include <list>
#include <limits.h>
using namespace std;

// Class for an undirected graph
class Graph
{
    int n;          // No. of vertices
    list<int> *adj; // Pointer to an array containing adjacency lists
    bool isCyclicUtil(int v, bool visited[], int parent);

public:
    // Constructor
    Graph(int n)
    {
        this->n = n;
        adj = new list<int>[n];
    }
    // To add an edge to graph
    void addEdge(int u, int v)
    {
        adj[u].push_back(v); // Add v to u’s list.
        adj[v].push_back(u); // Add u to v’s list.
    }
    // Returns true if there is a cycle
    bool isCyclic();
};

// A recursive function that uses visited[] and 'parent' vertex
// to detect cycle in subgraph reachable from vertex 'v'
bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++)
    {

        // If an adjacent vertex is not visited,
        // then recur for that adjacent
        if (!visited[*i])
        {
            if (isCyclicUtil(*i, visited, v))
                return true;
        }

        // If an adjacent vertex is visited and is not parent of current vertex,
        // then there exists a cycle in the graph.
        else if (*i != parent)
            return true;
    }
    return false;
}

// Returns True if the graph contains a cycle, else False
bool Graph::isCyclic()
{

    // Mark all the vertices as not-visited and not part of recursion
    // stack
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    // Call the recursive helper function
    // to detect cycle in different DFS trees
    for (int u = 0; u < n; u++)
    {

        // Don't recur for u if
        // it is already visited
        if (!visited[u])
            if (isCyclicUtil(u, visited, -1))
                return true;
    }
    return false;
}

// Driver program
int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);

    g1.isCyclic() ? cout << "Graph contains cycle\n" : cout << "Graph doesn't contain cycle\n";

    Graph g2(3);

    g2.addEdge(0, 1);
    g2.addEdge(1, 2);

    g2.isCyclic() ? cout << "Graph contains cycle\n" : cout << "Graph doesn't contain cycle\n";

    return 0;
}