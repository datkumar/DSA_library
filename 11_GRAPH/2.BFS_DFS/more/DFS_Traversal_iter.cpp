#include <iostream>
#include <list>
#include <vector>
#include <stack>

using namespace std;

// This class represents a directed graph using adjacency
// list representation
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

    // Prints DFS traversal from a given source node 'root'
    void DFS(int root);
};

// Prints all not yet visited vertices reachable from s
void Graph::DFS(int root)
{
    // Initially mark all verices as not visited
    vector<bool> visited(n, false); //Creates vector of size 'n' & initialises all to false

    // Create a stack for DFS
    stack<int> Stk;

    // Push the current source node.
    Stk.push(root);

    while (!Stk.empty())
    {
        // Pop a vertex from Stack and Print it
        root = Stk.top();
        Stk.pop();

        // Stack may contain same vertex twice
        // So we need to print the popped item ONLY IF it is NOT VISITED.
        if (!visited[root])
        {
            cout << root << " ";
            visited[root] = true;
        }

        // Get all adjacent vertices of the popped vertex s
        // If a adjacent has not been visited, then push it into the Stack
        for (auto i = l[root].begin(); i != l[root].end(); i++)
        {
            if (!visited[*i])
                Stk.push(*i);
        }
    }
}

// Driver program to test methods of graph class
int main()
{
    Graph g(5); // Total 5 vertices in graph
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);

    cout << "DFS Traversal (starting from vertex 2) : ";
    g.DFS(0);

    return 0;
}