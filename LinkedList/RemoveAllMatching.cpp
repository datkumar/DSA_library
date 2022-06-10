#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};
Node *insertAtEnd(Node *&head, int data);
Node *vectorToList(vector<int> &arr);
void printList(Node *&head);

Node *removeElements(Node *&head, int key)
{
    // Create dummy node which is before existing first node
    // of List (helpful when first node is to be deleted)
    Node *beforeHead = new Node(-1);
    beforeHead->next = head;

    Node *prev, *curr;
    // At start,
    prev = beforeHead, curr = head;

    while (curr)
    {
        if (curr->data == key) // KEY FOUND which is "curr" Node
        {
            Node *toDelete = curr;

            prev->next = curr->next;
            curr = curr->next;

            delete toDelete;
        }
        else // Move both ahead
        {
            prev = curr;
            curr = curr->next;
        }
    }
    // Restore correct head and delete the dummy node
    head = beforeHead->next;
    delete beforeHead;
    return head;
}

int main()
{
    vector<int> v{1, 2, 6, 1, 3, 4, 6, 1};

    Node *head = vectorToList(v);

    printList(head); // Input

    head = removeElements(head, 1);

    printList(head); // Output

    return 0;
}

// ===================================================
Node *insertAtEnd(Node *&head, int data)
{
    if (!head)
        return head = new Node(data);
    Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = new Node(data);
    return head;
}

Node *vectorToList(vector<int> &arr)
{
    Node *head = nullptr;
    for (int x : arr)
        head = insertAtEnd(head, x);
    return head;
}

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