#include <bits/stdc++.h>
using namespace std;

// Time:    O(n^2)
// Space    O(1)
// Stable:  YES
// Online:

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
        int key = nums[minElemIdx];
        while (minElemIdx > i)
        {
            nums[minElemIdx] = nums[minElemIdx - 1];
            minElemIdx--;
        }
        nums[i] = key;
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