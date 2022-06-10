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

    // Destructor
    ~Node()
    {
        int val = this->data;
        if (this->next)
        {
            delete this->next;
            this->next = nullptr;
        }
    }
};

void printList(Node *&head)
{
    if (!head) // When List Empty
    {
        cout << "List Empty" << endl;
    }
    else
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

Node *insertAtEnd(Node *&head, int val)
{
    // Check Empty List
    if (!head)
        return head = new Node(val);

    // when "temp" is NULL, we CANNOT do "temp->next"
    // which is handled for Empty List

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

Node *deleteFirst(Node *&head)
{
    if (!head)
        cout << "NO NODES TO DELETE" << endl;
    else
    {
        Node *firstNode = head;
        // Move the head pointer to the next node
        head = head->next;
        delete firstNode;
    }
    return head;
}

Node *deleteLast(Node *&head)
{
    if (!head)
        return head;
    if (!head->next)
    {
        delete head;
        return head = nullptr;
    }
    Node *beforeLast = head;
    while (beforeLast->next->next)
        beforeLast = beforeLast->next;
    // Now, "beforeLast->next" is the Last node
    delete (beforeLast->next);
    beforeLast->next = nullptr;
    return head;
}

Node *deleteAtPosition(Node *&head, int pos)
{
    if (!head)
    {
        cout << "NO NODES TO DELETE" << endl;
        return head;
    }
    if (pos == 0)
    {
        Node *firstNode = head;
        head = head->next;
        delete firstNode;
        return head;
    }
    if ((!head->next && pos != 0) || pos < 0)
    {
        cout << "POSITION OUT OF BOUNDS" << endl;
        return head;
    }

    Node *curr = head;
    Node *prev = nullptr;
    int idx = 0;
    while (curr && idx < pos)
    {
        prev = curr;
        curr = curr->next;
        idx++;
    }
    if (!curr)
    {
        cout << "POSITION OUT OF BOUNDS" << endl;
        return head;
    }
    // Now, "prev->next" i.e. "curr" is
    // the node we want to  to Delete
    prev->next = curr->next;
    delete curr;

    return head;
}

int main()
{
    Node *head;

    // vector<int> v{10, 20, 30, 40};
    // vector<int> v{10};
    vector<int> v{};
    head = vectorToList(v);

    
    printList(head);    // View Input

    // head = deleteFirst(head);
    
    // head = deleteLast(head);

    head = deleteAtPosition(head, 0);

    
    printList(head);    // View Output

    return 0;
}

/*=========== CASES:: ===================

    // Empty List Case
    head = nullptr;

    // Single-Elem. List Case
    vector<int> v{10};
    head = vectorToList(v);

    // General Case
    vector<int> v{10, 20, 30, 40};
    head = vectorToList(v);
    Node *head = vectorToList(v);

=======================================*/