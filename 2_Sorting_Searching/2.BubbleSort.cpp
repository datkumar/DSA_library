#include <bits/stdc++.h>
using namespace std;

/*
    NOTE:
    - Max. (n-1) rounds
    - Min. (n-1) comparisons
*/

/*
    Best Case:: Sorted Array => O(n).....Single pass and flag would return sorted
    Worst Case:: Reverse Sorted Array => O(n^2)
*/

/*
    Time:    O(n^2)
    Space    O(1), so In-place
    Stable:  YES.....Equal elements NOT swapped, so their order maintained
*/

void bubbleSort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) // i = 0 TO (n-2)
    {
        bool swapped = false; // Flag to check if array is sorted
        /*
            After every "i"th iteration, elements ahead of (n-1-i)th 
            index are in their correct sorted place.
            So, only need to check till index (n-i-1-1) i.e. (n-2-i)th index
        */
        for (int j = 0; j < n - 1 - i; j++) // j = 0 TO (n-2)-i
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) // NO SWAPS occured for this round.
            return;   // So, Array is sorted. No more rounds required
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

    bubbleSort(nums);

    cout << "\nSorted::" << endl;
    for (auto &x : nums)
        cout << x << " ";
    cout << endl;

    return 0;
}