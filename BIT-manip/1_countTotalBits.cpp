#include <bits/stdc++.h>
using namespace std;

int countBits(const unsigned int n)
{
    if (n == 0)
        return 1;
    return log2(n) + 1;
}
/*
  ----------------------------------------------------------
    n     binary(n)     (int)log2(n)        log2(n)
  ----------------------------------------------------------
    0       0           -2147483648         -inf
    1       1               0               0
    2       10              1               1
    3       11              1               1.58496
    4       100             2               2
    5       101             2               2.32193
    6       110             2               2.58496
    7       111             2               2.80735
    8       1000            3               3
    9       1001            3               3.16993
    10      1010            3               3.32193
    11      1011            3               3.45943
    12      1100            3               3.58496
    13      1101            3               3.70044
    14      1110            3               3.80735
    15      1111            3               3.90689
    16      10000           4               4
    17      10001           4               4.08746
    18      10010           4               4.16993
    19      10011           4               4.24793
    20      10100           4               4.32193
  ----------------------------------------------------------
*/
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
        cout << i << "\thas\t" << countBits(i) << "\tbits" << endl;
    }

    // for (int i = 0; i < 21; i++)
    // {
    //     cout << i << "\t" << binaryForm(i) << "\t\t" << (int)log2(i) << "\t\t" << log2(i) << endl;
    // }

    return 0;
}