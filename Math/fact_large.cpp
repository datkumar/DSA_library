#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int digit;
	Node *left;
	Node(int x)
	{
		digit = x;
		left = NULL;
	}
};

void multiplyBy(Node *tail, int num)
{
	Node *currNode = tail;
	Node *prevNode = tail;
	int carry = 0;
	while (currNode != NULL)
	{
		int temp = currNode->digit * num + carry;

		currNode->digit = temp % 10;
		carry = temp / 10;

		prevNode = currNode;
		currNode = currNode->left;
	}
	// If carry is greater than 0 then we create another node for it.
	while (carry > 0)
	{
		prevNode->left = new Node(carry % 10);
		carry = carry / 10;
		prevNode = prevNode->left;
	}
}

void addToStream(Node *tail, stringstream &ss)
{
	if (tail == NULL)
		return;
	addToStream(tail->left, ss);
	ss << tail->digit;
}

string fact(int n)
{
	if (n == 0 || n == 1)
		return "1";

	Node *tail = new Node(1);

	for (int i = 2; i <= n; i++)
		multiplyBy(tail, i);

	stringstream ss;
	addToStream(tail, ss);
	return ss.str();
}

int main()
{
	cout << fact(100) << endl;

	return 0;
}
