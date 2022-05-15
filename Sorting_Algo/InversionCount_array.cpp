#include <bits/stdc++.h>
using namespace std;

// Merge two sorted subarrays::
// left part  => arr[low] to arr[mid]
// right part => arr[mid+1] to arr[high]
int merge(int arr[], int temp[], int low, int mid, int high)
{
    int i = low, j = mid + 1;
    int k = low;

    int temp_inv_cnt = 0;

    // while there are elements in the left and right runs
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];

        else
        {
            temp[k++] = arr[j++];
            temp_inv_cnt += (mid - i + 1); // IMP. STEP
        }
    }

    // copy remaining elements
    while (i <= mid)
        temp[k++] = arr[i++];

    /* no need to copy the second half (since the remaining items
       are already in their correct position in the temporary array) */

    // copy back to the original array to reflect sorted order
    for (int i = low; i <= high; i++)
        arr[i] = temp[i];

    return temp_inv_cnt;
}

int mergeSort(int arr[], int temp[], int low, int high)
{
    if (high <= low) // Base Case
        return 0;


    int mid = (low + ((high - low) >> 1));
    int inv_cnt = 0;

    // split/merge left half
    inv_cnt += mergeSort(arr, temp, low, mid);

    // split/merge right half
    inv_cnt += mergeSort(arr, temp, mid + 1, high);

    // merge the two half runs
    inv_cnt += merge(arr, temp, low, mid, high);

    return inv_cnt;
}

int main()
{
    int arr[] = {468, 335, 1, 170, 225, 479, 359, 463, 465, 206, 146, 282, 328, 462, 492, 496, 443, 328, 437, 392, 105, 403, 154, 293, 383, 422, 217, 219, 396, 448, 227, 272, 39, 370, 413, 168, 300, 36, 395, 204, 312, 323};

    int N = sizeof(arr) / sizeof(arr[0]);

    int temp[N];
    for (int i = 0; i < N; i++)
        temp[i] = arr[i];

    cout << "N: " << N << endl;
    int inv_cnt = mergeSort(arr, temp, 0, N - 1);

    cout << "Inv. count: " << inv_cnt << endl;


    return 0;
}
