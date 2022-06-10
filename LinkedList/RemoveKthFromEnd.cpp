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

Node *RemoveKthFromEnd(Node *&head, int K)
{
    Node *beforeHead = new Node(-1);
    beforeHead->next = head;

    Node *slow = beforeHead;
    Node *fast = head;

    for (int i = 0; i < K - 1; i++)
        fast = fast->next;

    while (fast->next)
        slow = slow->next, fast = fast->next;

    Node *toDel = slow->next;
    slow->next = slow->next->next;
    delete toDel;

    head = beforeHead->next;
    delete beforeHead;

    return head;
}

int main()
{
    vector<int> v{60, 50, 40, 30, 20, 10};
    // vector<int> v{10,20};
    Node *head = vectorToList(v);

    printList(head); // Input

    int K = 1;
    cout << "K = " << K << endl;
    head = RemoveKthFromEnd(head, K);

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