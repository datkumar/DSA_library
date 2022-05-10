// Program to demonstrate Adj. list representation of graphs

#include <iostream>
using namespace std;

// Structure to represent an Adjacency List Node
struct ListNode
{
    int dest;
    struct ListNode *next;
};

// A structure to represent an adjacency list
struct List
{
    struct ListNode *head; // Points to start of List
};

// Function to create a new Adj. List node
struct ListNode *newListNode(int dest)
{
    struct ListNode *newNode = new ListNode();
    // (struct ListNode *)malloc(sizeof(struct ListNode))
    newNode->dest = dest;
    newNode->next = NULL;

    return newNode;
}

// A graph is an array of adjacency lists.
// Size of array will be V (number of vertices)
// Structure to represent Graph.
struct Graph
{
    int n; // No. of Vertices
    struct List *array;
};

// A utility function that creates a graph of V vertices
struct Graph *createGraph(int n)
{
    struct Graph *G = (struct Graph *)malloc(sizeof(struct Graph));
    G->n = n;

    // Create an array of adjacency lists.
    // Size of array will be n
    G->array = (struct List *)malloc(n * sizeof(struct List));
    ;

    // Initialize each adjacency list as empty by
    // making head as NULL
    int i;
    for (i = 0; i < n; ++i)
        G->array[i].head = NULL;

    return G;
}

// Adds an edge to an undirected graph
void addEdge(struct Graph *graph, int src, int dest)
{
    // Add an edge from src to dest.  A new node is
    // added to the adjacency list of src.  The node
    // is added at the beginning
    struct ListNode *newNode = newListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since graph is undirected, add an edge from
    // dest to src also
    newNode = newListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to Print the Adj. list representation of Graph
void printGraph(struct Graph *graph)
{
    int v;
    for (v = 0; v < graph->n; v++)
    {
        struct ListNode *pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        cout << endl;
    }
}

// Driver program
int main()
{
    // No. of vertices
    int n = 5;

    //Create Graph
    struct Graph *G = createGraph(n);

    addEdge(G, 0, 1);
    addEdge(G, 0, 4);
    addEdge(G, 1, 2);
    addEdge(G, 1, 3);
    addEdge(G, 1, 4);
    addEdge(G, 2, 3);
    addEdge(G, 3, 4);

    // Print the Adj. List representation of the Graph
    printGraph(G);

    return 0;
}