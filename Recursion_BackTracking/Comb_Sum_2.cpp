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
// NOT UNIQUE elem. always
// Can PICK elem. ONLY ONCE
void func(int idx, int rem, vector<int> &seq, int arr[], int n)
{
	if (rem == 0)
	{
		printSeq(seq);
		return;
	}
	for (int i = idx; i < n; i++)
	{
		if (i > idx && arr[i] == arr[i - 1])
			continue;

		if (arr[i] > rem)
			break;

		seq.push_back(arr[i]);
		func(i + 1, rem - arr[i], seq, arr, n);
		seq.pop_back();
	}
}

int main()
{
	int arr[] = {1,1,1,2,2};
	int target = 4;

	int n = sizeof(arr) / sizeof(arr[0]);

	sort(arr, arr + n);
	vector<int> currSeq = {};

	func(0, target, currSeq, arr, n);

	return 0;
}

/*

arr[] = {10, 1, 2, 7, 6, 1, 5}
target = 8

	1 1 6 
	1 2 5 
	1 7 
	2 6 


arr[] = {1,1,1,2,2}
target = 4

	1 1 2 
	2 2


*/