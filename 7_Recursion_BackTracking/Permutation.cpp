#include <bits/stdc++.h>
using namespace std;

void printSeq(vector<char> &seq)
{
	if (seq.empty())
		cout << "-";
	else
	{
		for (auto x : seq)
			cout << x << ",";
	}
	cout << endl;
}

/*
void func(int picked[], vector<int> &seq, int arr[], int n)
{
	if (seq.size() == n)
	{
		printSeq(seq);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!picked[i])
		{
			seq.push_back(arr[i]);
			picked[i]++;
			func(picked, seq, arr, n);
			picked[i]--;
			seq.pop_back();
		}
	}
}
*/

void func(int idx, vector<char> &arr)
{
	if (idx == arr.size())
	{
		printSeq(arr);
		return;
	}
	for (int i = idx; i < arr.size(); i++)
	{
		// cout<<"  swap "<<arr[i]<<", "<<arr[idx]<<endl;
		swap(arr[i],arr[idx]);

		func(idx + 1, arr);
		
		// cout<<"    back swap "<<arr[i]<<", "<<arr[idx]<<endl;
		swap(arr[i],arr[idx]);
	}
}

int main()
{
	// int arr[] = {1, 2, 3};
	// int n = sizeof(arr) / sizeof(arr[0]);
	// vector<int> seq;

	// int picked[n] = {0};
	// func(picked, seq, arr, n);
	

	// vector<int>arr = {1, 2, 3};
	vector<char> arr = {'a', 'b', 'c','d'};
	func(0, arr);


	return 0;
}

/*
-----------------------------

arr = {1, 2, 3}

1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

-----------------------------

arr = {'A', 'B', 'C'}

A B C 
A C B 
B A C 
B C A 
C B A 
C A B 

--------------------------------

arr = {'P', 'Q', 'R'}

P Q R 
P R Q 
Q P R 
Q R P 
R Q P 
R P Q


  swap P, P
  swap Q, Q
  swap R, R
P Q R 
    back swap R, R
    back swap Q, Q
  swap R, Q
  swap Q, Q
P R Q 
    back swap Q, Q
    back swap Q, R
    back swap P, P
  swap Q, P
  swap P, P
  swap R, R
Q P R 
    back swap R, R
    back swap P, P
  swap R, P
  swap P, P
Q R P 
    back swap P, P
    back swap P, R
    back swap P, Q
  swap R, P
  swap Q, Q
  swap P, P
R Q P 
    back swap P, P
    back swap Q, Q
  swap P, Q
  swap Q, Q
R P Q 
    back swap Q, Q
    back swap Q, P
    back swap P, R

-----------------------------

*/