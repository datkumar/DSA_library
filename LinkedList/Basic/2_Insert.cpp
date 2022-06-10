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

Node *insertAtStart(Node *&head, int val)
{
    Node *newNode = new Node(val);

    newNode->next = head;
    head = newNode;
    // Above code handles Empty list & Single-elem. List cases
    return head;
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

Node *InsertAtPosition(Node *&head, int pos, int val)
{
    if (pos < 0 || (head == nullptr && pos != 0))
    {
        cout << "POSITION OUT OF BOUNDS" << endl;
        return head;
    }
    if (pos == 0) // Insert at Start
    {
        Node *newHead = new Node(val);
        newHead->next = head;
        return head = newHead;
    }

    int idx = 0;
    Node *temp = head;

    while (temp && idx < pos - 1)
        temp = temp->next, idx++;

    if (!temp)
    {
        cout << "POSITION OUT OF BOUNDS" << endl;
        return head;
    }
    Node *newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

int main()
{
    Node *head;

    // head = insertAtStart(head, 7);
    // printList(head);

    // head = insertAtEnd(head, 9);
    // printList(head);

    vector<int> v{10, 20, 30, 40};
    head = vectorToList(v);

    // View Input
    printList(head);

    head = InsertAtPosition(head, 4, 5);

    // View Output
    printList(head);

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