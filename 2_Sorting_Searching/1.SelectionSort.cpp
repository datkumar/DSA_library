#include <bits/stdc++.h>
using namespace std;

/*
    Best Case:: Sorted Array => O(n^2)
    Worst Case:: Reverse Sorted Array => O(n^2)
*/

/*
    NOTE: 
    - Equal i.e. n(n-1)/2 Comparions in ALL Cases
    - O(n) swaps in ALL cases
*/

/*
    Time:    O(n^2)
    Space    O(1), so In-place
    Stable:  NO
*/


void selectionSort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        // index of min. elem. in current working sub-array
        int minElemIdx = i;
        // Find min. elem.'s index in current sub-array
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[minElemIdx])
                minElemIdx = j;
        }
        swap(nums[i], nums[minElemIdx]);
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

    selectionSort(nums);

    cout << "\nSorted::" << endl;
    for (auto &x : nums)
        cout << x << " ";
    cout << endl;

    return 0;
}