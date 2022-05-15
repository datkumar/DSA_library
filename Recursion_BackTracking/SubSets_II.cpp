#include <bits/stdc++.h>
using namespace std;

void printSeq(vector<int> &seq)
{
	if (seq.empty())
		cout << "{}";
	else
	{
		for (auto x : seq)
			cout << x << " ";
	}
	cout << endl;
}

void func(int idx, vector<int> &seq, int arr[], int n)
{
	// ans.push_back(seq);
	printSeq(seq);
	for (int i = idx; i < n; i++)
	{
		if (i != idx && arr[i] == arr[i - 1])
			continue;
		seq.push_back(arr[i]);
		func(i + 1, seq, arr, n);
		seq.pop_back();
	}
}

int main()
{
	int arr[] = {1, 1, 2, 2, 3};

	int n = sizeof(arr) / sizeof(arr[0]);

	sort(arr, arr + n);
	vector<int> currSeq = {};

	func(0, currSeq, arr, n);

	return 0;
}

/*
arr[] = {1, 1, 2, 2, 3}
n = 5

{}
1 
1 1 
1 1 2 
1 1 2 2 
1 1 2 2 3 
1 1 2 3 
1 1 3 
1 2 
1 2 2 
1 2 2 3 
1 2 3 
1 3 
2 
2 2 
2 2 3 
2 3 
3

*/