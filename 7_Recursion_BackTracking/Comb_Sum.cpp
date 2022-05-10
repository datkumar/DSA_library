#include <bits/stdc++.h>
using namespace std;

void printSeq(vector<int> &seq)
{
	if (seq.empty())
		cout << "-";
	else
	{
		for (auto x : seq)
			cout << x << " ";
	}
	cout << endl;
}

// Sum of combination must be equal to Target
// UNIQUE elem.
// Can PICK elem. MULTIPLE times
void func(int idx, int rem, vector<int> &seq, int arr[], int n)
{
	if (idx == n)
	{
		if (rem == 0)
		{
			printSeq(seq);
				}
		return;
	}
	if (arr[idx] <= rem)
	{
		seq.push_back(arr[idx]);
		func(idx, rem - arr[idx], seq, arr, n);
		seq.pop_back();
	}
	func(idx + 1, rem, seq, arr, n);
}

int main()
{
	int arr[] = {2, 3, 5};
	int target = 8;

	int n = sizeof(arr) / sizeof(arr[0]);

	vector<int> seq = {};

	func(0, target, seq, arr, n);

	return 0;
}

/*

arr[] = {2, 3, 5};
target = 8;

2 2 2 2 
2 3 3 
3 5 


*/