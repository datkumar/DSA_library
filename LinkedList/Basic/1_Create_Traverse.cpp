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

int main()
{
    // Pointer that points to Start of List
    Node *head;

    // Create & Insert Next
    head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    // View List
    printList(head);

    return 0;
}