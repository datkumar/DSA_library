#include <bits/stdc++.h>
using namespace std;

// To store no. of inversions
int inv_cnt = 0;

void merge(vector<int> &curr, vector<int> &left, vector<int> &right)
{
    int i = 0, j = 0;
    int k = 0;

    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
            curr[k++] = left[i++];

        else
        {
            inv_cnt += left.size() - i;  // IMP. Step
            curr[k++] = right[j++];
        }
    }

    while (i < left.size())
        curr[k++] = left[i++];

    while (j < right.size())
        curr[k++] = right[j++];
}

void mergeSort(vector<int> &curr)
{
    if (curr.size() <= 1) // Base Case
        return;

    int n = curr.size();

    int mid = n / 2;

    vector<int> left(curr.begin(), curr.begin() + mid);

    vector<int> right(curr.begin() + mid, curr.end());

    mergeSort(left);
    mergeSort(right);

    merge(curr, left, right);
}

int main()
{
    vector<int> arr = {468, 335, 1, 170, 225, 479, 359, 463, 465, 206, 146, 282, 328, 462, 492, 496, 443, 328, 437, 392, 105, 403, 154, 293, 383, 422, 217, 219, 396, 448, 227, 272, 39, 370, 413, 168, 300, 36, 395, 204, 312, 323};

    mergeSort(arr);

    cout << "\nSorted::" << endl;
    for (auto &x : arr)
        cout << x << " ";
    cout << endl;

    cout << "Inv. Count: " << inv_cnt << endl;

    return 0;
}
