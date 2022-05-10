#include <bits/stdc++.h>
using namespace std;

void func(int idx, string &seq, vector<string> &ans, string &digits, vector<string> &Map)
{
    if ((size_t)idx == digits.size())
    {
        ans.push_back(seq);
        return;
    }

    int curr_digit = digits[idx] - '0';
    string available_letters = Map[curr_digit];
    for (int i = 0; (size_t)i < available_letters.size(); i++)
    {
        seq.push_back(available_letters[i]);
        func(idx + 1, seq, ans, digits, Map);
        seq.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    if (digits.empty())
        return {};

    vector<string> M(10, "");
    M[2] = "abc";
    M[3] = "def";
    M[4] = "ghi";
    M[5] = "jkl";
    M[6] = "mno";
    M[7] = "pqrs";
    M[8] = "tuv";
    M[9] = "wxyz";

    vector<string> ans;
    string seq = "";

    func(0, seq, ans, digits, M);

    return ans;
}

int main()
{

    string digits = "23";
    auto ans = letterCombinations(digits);
    for (auto &x : ans)
        cout << x << endl;

    return 0;
}