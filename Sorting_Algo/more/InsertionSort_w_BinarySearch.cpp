#include <bits/stdc++.h>
using namespace std;

/*
    A binary search based function to
    find the position where item should
    be inserted in a[low..high]
*/

int binarySearch(int a[], int item, int low, int high)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (item == a[mid])
            return mid + 1;
        else if (item > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
 
    return low;
}
 
// Function to sort an array a[] of size 'n'
void InsertionSort(int a[], int n)
{
    int i, loc, j, k, selected;
 
    for (i = 1; i < n; ++i) {
        j = i - 1;
        selected = a[i];
 
        // find location where selected should be inseretd
        loc = binarySearch(a, selected, 0, j);
 
        // Move all elements after location to create space
        while (j >= loc) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
    }
}
 

int main()
{
    int N;
    cout << "N: ";
    cin >> N;
    
    int nums[N];
    for (auto &x : nums)
        cin >> x;

    InsertionSort(nums,N);

    cout << "\nSorted::" << endl;
    for (auto &x : nums)
        cout << x << " ";
    cout << endl;

    return 0;
}