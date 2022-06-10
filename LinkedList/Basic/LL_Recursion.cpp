#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    // Data members Declaration
    int data;
    Node *next;

    // Member Initialization with Parameterized Constructor
    Node(int val) : data(val), next(nullptr){};
};

Node *insertAtEnd(Node *&head, int data);
Node *vectorToList(vector<int> &arr);

void print(Node *&node)
{
    if (!node)
    {
        cout << endl;
        return;
    }
    cout << node->data << " ";
    print(node->next);
}

int len(Node *&node)
{
    if (!node)
        return 0;
    return 1 + len(node->next);
}

int main()
{
    Node *head;

    vector<int> v{10, 20, 30, 40};
    head = vectorToList(v);

    print(head);

    cout << "Length: " << len(head) << endl;
       
    return 0;
    
}

Node *insertAtEnd(Node *&head, int val)
{
    if (!head)
        return head = new Node(val);
    Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = new Node(val);
    return head;
}

Node *vectorToList(vector<int> &arr)
{
    Node *head = nullptr;
    for (int x : arr)
        head = insertAtEnd(head, x);
    return head;
}