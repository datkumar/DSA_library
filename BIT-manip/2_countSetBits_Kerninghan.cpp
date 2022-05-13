#include <bits/stdc++.h>
using namespace std;

// ==================================================================================

/*
    Kerninghan Algo.(Iterative)
    Time: O(S) .... O(N) in Worst-case  ,   Space: O(1)
*/
int countSetBits(const unsigned int n)
{
    int cnt = 0;
    int temp = n;
    // This loop runs only 'S' times
    while (temp > 0)
    {
        temp &= (temp - 1);
        cnt++;
    }
    return cnt;
}

// ==================================================================================

/*
    Kerninghan Algo.(Recursive)
    Time: O(S) .... O(N) in Worst-case
    Space: O(1) Aux. but O(S) Rec. Stack space
*/
// int func(int n)
// {
//     if (n == 0)
//         return 0;
//     return 1 + func(n & (n - 1));
// }
// int countSetBits(const unsigned int n)
// {
//     return func(n);
// }

// ==================================================================================

string binaryForm(const unsigned int N)
{
    if (N == 0)
        return "0";

    int n = N;
    string ans;
    while (n > 0)
    {
        if (n & 1)
            ans.push_back('1');
        else
            ans.push_back('0');
        n >>= 1;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    for (int i = 0; i <= 20; i++)
    {
        cout << i << "\t" << binaryForm(i) << "\t\t" << countSetBits(i) << endl;
    }
    return 0;
}
/*
  ------------------------------------------
    n     binary(n)      SET bit count
  ------------------------------------------
    0       0               0
    1       1               1
    2       10              1
    3       11              2
    4       100             1
    5       101             2
    6       110             2
    7       111             3
    8       1000            1
    9       1001            2
    10      1010            2
    11      1011            3
    12      1100            2
    13      1101            3
    14      1110            3
    15      1111            4
    16      10000           1
    17      10001           2
    18      10010           2
    19      10011           3
    20      10100           2
    ------------------------------------------
*/