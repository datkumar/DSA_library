#include <bits/stdc++.h>
using namespace std;


// =====================================================
/*
    "unsigned int" has at max. 32 bits
    log2(32) = 5

    So suitable word size = 5 bits
    i.e.,  k = 5

    Total possible words = 2^5 = 32
*/
/*
    Using WHILE loop and word-size k=5
*/
int Table[32];
void init()
{
    Table[0] = 0;
    for (int i = 1; i < 32; i++)
    {
        Table[i] = (i & 1) + Table[i >> 1];
    }
}
int countSetBits(unsigned int n)
{
    init();
    int cnt = 0;
    while (n > 0)
    {
        // ALL 5 bits of word SET => (11111) => 31
        int word = n & 31;
        cnt += Table[word];
        n >>= 5;
    }
    return cnt;
}
/*
    Time:
    Space:
*/

// ==================================================================================
/*
    Using FOR loop and word-size k=4
*/
// int Table[16];
// void init()
// {
//     Table[0] = 0;
//     for (int i = 1; i < 16; i++)
//     {
//         Table[i] = (i & 1) + Table[i >> 1];
//     }
// }
// int countSetBits(unsigned int n)
// {
//     init();
//     int cnt = 0;
//     for (int i = 0; i < 32; i+=4)
//     {
//         cnt += Table[(n >> i) & 0xF];
//     }
//     return cnt;
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