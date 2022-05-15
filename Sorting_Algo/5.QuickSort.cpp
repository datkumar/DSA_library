#include <bits/stdc++.h>
using namespace std;

// Pick Pivot and place it at it's correct (sorted) position
// Thus, we split the working array into two parts around the pivot
int partition(vector<int> &arr, int low, int high)
{
    // Pick LAST elem. of working array as Pivot
    int pivot = arr[high];

    // Indicates index of elem. JUST BEFORE
    // the Pivot's correct index (found so far)
    int before_p = low - 1;

    for (int j = low; j <= high; j++)
    {
        // Found an elem. SMALLER than Pivot,
        // So place it in LEFT part
        if (arr[j] < pivot)
        {
            before_p++;
            swap(arr[j], arr[before_p]);
        }
    }
    /* 
    NOTE::
        Correct position of Pivot is (before_p + 1)
    */
    // Place Pivot at it's correct position
    swap(arr[before_p + 1], arr[high]);

    // return Pivot i.e. Partition index
    return (before_p + 1);
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    // Pivot placed at it's correct position
    // and it's sorted positoin's index returned
    int p = partition(arr, low, high);

    quickSort(arr, low, p - 1);  // Sort elem. LEFT of pivot
    quickSort(arr, p + 1, high); // Sort elem. RIGHT of pivot
}

int main()
{
    // int N;
    // cout << "N: ";
    // cin >> N;
    // vector<int> nums(N);
    // for (auto &x : nums)
    //     cin >> x;

    vector<int> nums = {5, 7, 3, 4, 1, 2};
    // vector<int> nums = {30, 5, 51, 99, 50, 31, 35, 2, 98, 9, 78, 77, 9, 13, 100, 3, 99, 86, 61, 49};

    quickSort(nums, 0, nums.size() - 1);

    cout << "\nSorted::" << endl;
    for (auto &x : nums)
        cout << x << " ";
    cout << endl;

    return 0;
}