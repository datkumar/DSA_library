#include <bits/stdc++.h>
using namespace std;

typedef vector<int> Hash;

void func(int col, vector<string> &board, vector<vector<string>> &ans, Hash &leftRow, Hash &upperDiagonal, Hash &lowerDiagonal, int N)
{
	if (col == N)
	{
		ans.push_back(board);
		return;
	}

	for (int row = 0; row < N; row++)
	{
		if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[N - 1 + col - row] == 0)
		{
			board[row][col] = 'Q';
			leftRow[row] = 1;
			lowerDiagonal[row + col] = 1;
			upperDiagonal[N - 1 + col - row] = 1;

			func(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, N);

			board[row][col] = 'x';
			leftRow[row] = 0;
			lowerDiagonal[row + col] = 0;
			upperDiagonal[N - 1 + col - row] = 0;
		}
	}
}
vector<vector<string>> NQueens(int N)
{
	string boardRow(N, 'x');
	vector<string> board(N, boardRow);

	Hash leftRow(N, 0), upperDiagonal(2 * N - 1, 0), lowerDiagonal(2 * N - 1, 0);

	vector<vector<string>> ans;
	func(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, N);

	return ans;
}

int main()
{
	int N = 4;
	auto ans = NQueens(N);
	for (auto &x : ans)
	{
		for (int i = 0; i < N; i++)
		{
			cout << x[i] << endl;
		}
		cout << endl;
	}
}