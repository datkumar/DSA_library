#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<long long int>> Mat;

// returns pair { f(n), f(n+1) }
pair<int, int> fib(int n)
{
	if (n == 0)
		return {0, 1};

	// call fib(n/2)
	auto PAIR = fib(n >> 1);

	int Fn = PAIR.first * (2 * PAIR.second - PAIR.first);

	int Fn_plus_1 = PAIR.first * PAIR.first + PAIR.second * PAIR.second;

	if (n & 1) // 'n' is ODD
		return {Fn_plus_1, Fn + Fn_plus_1};
	else
		return {Fn, Fn_plus_1};
}

Mat multiply(Mat &v1, Mat &v2)
{
	int M = pow(10, 9) + 7;
	Mat temp(2, vector<long long int>(2));

	temp[0][0] = ((v1[0][0] * v2[0][0]) % M + (v1[0][1] * v2[1][0]) % M) % M;
	temp[0][1] = ((v1[0][0] * v2[0][1]) % M + (v1[0][1] * v2[1][1]) % M) % M;
	temp[1][0] = ((v1[1][0] * v2[0][0]) % M + (v1[1][1] * v2[1][0]) % M) % M;
	temp[1][1] = ((v1[1][0] * v2[0][1]) % M + (v1[1][1] * v2[1][1]) % M) % M;

	return temp;
}
Mat helper(Mat &v, int n)
{
	if (n == 1)
		return v;
	Mat temp = helper(v, n / 2);
	Mat ans = multiply(temp, temp);

	if (n & 1) // when Odd
		return multiply(ans, v);
	return ans; // when Even
}

int solve(int A)
{
	// int n = A;
	Mat v = {{1, 1}, {1, 0}};
	Mat ans = helper(v, A);
	return ans[0][1];
}

int main()
{
	cout << solve(13) << endl;
	cout << fib(13).first << endl;
	return 0;
}
