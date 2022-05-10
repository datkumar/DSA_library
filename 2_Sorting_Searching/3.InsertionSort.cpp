#include <bits/stdc++.h>
using namespace std;

/*
    # Insertion Sort is an ONLINE Algorithm i.e. it can process input part-by-part without needing whole input at once.
*/

/*
    Best Case:: Sorted Array => O(n) ..... (n-1) comparisons
    Worst Case:: Reverse Sorted Array => O(n^2) ....... n(n-1)/2
*/

/*
    Time:    O(n^2)Stable
    Space    O(1), so In-place
    Stable:  YES ..... equal elements shifted in the same order as they were
*/


/*
    Assume Left-side is already sorted.
    At every iteration, pick one element 
    from Right-side and insert it in it's
    correct position into Left-side 
*/
void insertionSort(vector<int> &arr)
{
    int n = arr.size();

    // i=0 will have only one element and can be assumed sorted
    // So start from i=1 till i=n-1
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];  // Currently picked elem. from Right-side

        int j = i - 1;      // Start from elem. prev. to curr.

        // Shift all elem. higher than "curr"
        // one place ahead
        while (j >= 0 && curr < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // Correct sorted posistion of "curr" is index (j+1)
        arr[j + 1] = curr;
    }
}

int main()
{
    int N;
    cout << "N: ";
    cin >> N;
    vector<int> nums(N);
    for (auto &x : nums)
        cin >> x;

    cout << endl;
    insertionSort(nums);

    cout << "\nSorted::" << endl;
    for (auto &x : nums)
        cout << x << " ";
    cout << endl;

    return 0;
}