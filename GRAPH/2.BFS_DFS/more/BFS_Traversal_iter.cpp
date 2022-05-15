// Program to Print BFS traversal from a given source vertex (DIRECTED Graph)
#include <iostream>
#include <list>
#include <queue>

using namespace std;

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int n;        // number of vertices
    list<int> *l; // Pointer to an array containing Adj. lists

public:
    // Constructor
    Graph(int n)
    {
        this->n = n;
        l = new list<int>[n];
    }

    // Add an edge to graph
    void addEdge(int u, int v)
    {
        l[u].push_back(v); // Add v to u’s list.
    }

    // Prints BFS traversal from a given source node 'root'
    void BFS(int root);
};

// Print BFS traversal from a given source vertex 'root'
void Graph ::BFS(int root)
{
    // Mark all the vertices as NOT-visited
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    // Create a Queue for BFS
    queue<int> Q;

    // Mark the current node as visited and enqueue it
    visited[root] = true;
    Q.push(root);

    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
    while (!Q.empty())
    {
        // Print first vertex from queue and De-queue it
        root = Q.front();
        cout << root << " ";
        Q.pop();

        // Get all adjacent vertices of the De-queued vertex 'root'
        // If a adjacent has not been visited, then mark it visited and En-queue it
        for (i = l[root].begin(); i != l[root].end(); i++)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                Q.push(*i);
            }
        }
    }
}

// Driver program
int main()
{
    // Create a graph
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "BFS Traversal (starting from vertex 2) : ";
    g.BFS(2);

    return 0;
}