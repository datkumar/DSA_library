#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &curr, vector<int> &left, vector<int> &right)
{
    int i = 0, j = 0;
    int k = 0;

    while (i < left.size() && j < right.size())
    {
        // Next sorted present in LEFT sub-array
        if (left[i] <= right[j])
            curr[k++] = left[i++];

        // Next sorted present in RIGHT sub-array
        else
            curr[k++] = right[j++];
    }

    // "j" gone out of bounds but "i" remaining
    while (i < left.size())
        curr[k++] = left[i++];

    // "i" gone out of bounds but "j" remaining
    while (j < right.size())
        curr[k++] = right[j++];
}

void mergeSort(vector<int> &curr)
{
    if (curr.size() <= 1) // Base Case
        return;

    int n = curr.size();
    // "curr" has "n" elements from index [0] to [n-1]

    // Find "mid" index
    int mid = n / 2;

    // "mid" no. of elements should be part of left sub-array
    // i.e. from index [0] till [mid-1]
    vector<int> left(curr.begin(), curr.begin() + mid);

    // (n-mid) no. of elements should be part of right sub-array
    // i.e. from index [mid] to [n-1]
    vector<int> right(curr.begin() + mid, curr.end());

    mergeSort(left);  // sort left subarray
    mergeSort(right); // sort right subarray

    merge(curr, left, right); // Merging sorted "left" and "right" sub-arrays into "arr"
}

int main()
{
    // int N;
    // cout << "N: ";
    // cin >> N;
    // vector<int> arr(N);
    // for (auto &x : arr)
    //     cin >> x;
    // cout << endl;

    vector<int> arr = {30, 5, 51, 99, 50, 31, 35, 2, 98, 9, 78, 77, 9, 13, 100, 3, 99, 86, 61, 49};

    mergeSort(arr);

    cout << "\nSorted::" << endl;
    for (auto &x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
