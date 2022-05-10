// A C++ Program to Detect Cycle in a Directed Graph
#include <iostream>
#include <list>
// #include <stack>
using namespace std;

class Graph
{
    int n;                                              // No. of vertices
    list<int> *adj;                                     // Pointer to an array containing adjacency lists
    bool isCyclicUtil(int v, bool visited[], bool *rs); // used by isCyclic()

public:
    // Constructor
    Graph(int n)
    {
        this->n = n;
        adj = new list<int>[n];
    }
    void addEdge(int u, int v) // to add an edge to graph
    {
        adj[u].push_back(v); // Add w to v’s list.
    }

    bool isCyclic(); // returns True if there is a cycle in this graph
};

// This function is a variation of DFSUtil()
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if (visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;

        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if (!visited[*i] && isCyclicUtil(*i, visited, recStack))
                return true;
            else if (recStack[*i])
                return true;
        }
    }
    recStack[v] = false; // remove the vertex from recursion stack
    return false;
}

// This function is a variation of DFS()
// Returns True if the graph contains a cycle, else False
bool Graph::isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion stack
    bool *visited = new bool[n];
    bool *recStack = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    // Call the recursive helper function to detect cycle in diff. DFS trees
    for (int i = 0; i < n; i++)
    {
        if (isCyclicUtil(i, visited, recStack))
            return true;
    }

    return false;
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    if (g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}