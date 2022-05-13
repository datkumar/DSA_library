#include <bits/stdc++.h>
using namespace std;

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
        cout << i << "\t" << binaryForm(i) << endl;
    }

    return 0;
}