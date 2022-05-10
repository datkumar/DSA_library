#include <bits/stdc++.h>
using namespace std;

void printSeq(vector<int> seq)
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


void func(int idx, vector<int> currSeq, int arr[], int n)
{
    if (idx == n)
    {
        printSeq(currSeq);
        return;
    }

    // PICK current elem.
    currSeq.push_back(arr[idx]);
    // cout<<"f("<<idx<<",";
    // for(auto &x: currSeq) cout<<x<<" ";
    // cout <<")"<<endl;
    func(idx + 1, currSeq, arr, n); 
    
    currSeq.pop_back();

    // NOT Pick current elem.
    // cout<<"f("<<idx<<",";
    // for(auto &x: currSeq) cout<<x<<" ";
    // cout <<")"<<endl;
    func(idx+1,currSeq,arr,n);
}

int main()
{
    int n = 3;
    int arr[n] = {7, 8, 9};

    vector<int> currSeq = {};
    cout<<"f(0,-)"<<endl;
    func(0, currSeq, arr, n);

    return 0;
}

/*

7 8 9 
7 8 
7 9 
7 
8 9 
8 
9 
-

*/