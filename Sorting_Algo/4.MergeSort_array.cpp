#include <bits/stdc++.h>
using namespace std;

/* 
Merge two sorted subarrays::
    left part  => temp[low] to temp[mid]
    right part => temp[mid+1] to temp[high]
*/
void merge(int arr[], int temp[], int low, int mid, int high)
{
    int i = low, j = mid + 1;
    int k = low;

    // while there are elements in the left and right runs
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];

        else
            temp[k++] = arr[j++];
    }

    // copy remaining elements
    while (i <= mid)
        temp[k++] = arr[i++];

    // no need to copy the second half (since the remaining items
    // are already in their correct position in the temporary array)

    // copy back to the original array to reflect sorted order
    for (int k = low; k <= high; k++)
        arr[k] = temp[k];
}

void mergeSort(int arr[], int temp[], int low, int high)
{
    if (high <= low) // Base Case
        return;

    int mid = (low + high) / 2;

    mergeSort(arr, temp, low, mid);

    mergeSort(arr, temp, mid + 1, high);

    merge(arr, temp, low, mid, high);
}

int main()
{
    int arr[] = {30, 5, 51, 99, 50, 31, 35, 2, 98, 9, 78, 77, 9, 13, 100, 3, 99, 86, 61, 49};

    int N = end(arr) - begin(arr);

    int temp[N];
    copy(begin(arr), end(arr), temp);

    mergeSort(arr, temp, 0, N - 1);

    cout << "Sorted::" << endl;
    for (auto itr = begin(arr); itr != end(arr); itr++)
        cout << *itr << " ";
    cout << endl;

    return 0;
}
