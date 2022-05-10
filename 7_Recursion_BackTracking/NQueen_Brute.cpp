#include <bits/stdc++.h>
using namespace std;

bool safeToPlace(int row, int col, vector<string> &board, int N)
{
	int i, j;

	// Upper-Left Diagonal
	i = row, j = col;
	while (i >= 0 && j >= 0)
	{
		if (board[i][j] == 'Q')
			return false;
		i--, j--;
	}

	// Left-Row
	i = row, j = col;
	while (j >= 0)
	{
		if (board[i][j] == 'Q')
			return false;
		j--;
	}

	// Lower-Left Diagonal
	i = row, j = col;
	while (i < N && j >= 0)
	{
		if (board[i][j] == 'Q')
			return false;
		i++, j--;
	}

	return true;
}

void func(int col, vector<string> &board, vector<vector<string>> &ans, int N)
{
	if (col == N)
	{
		ans.push_back(board);
		return;
	}

	for (int row = 0; row < N; row++)
	{
		if (safeToPlace(row, col, board, N))
		{
			board[row][col] = 'Q';
			func(col + 1, board, ans, N);
			board[row][col] = 'x';
		}
	}
}

vector<vector<string>> NQueens(int N)
{
	string boardRow(N, 'x');
	vector<string> board(N, boardRow);
	vector<vector<string>> ans;
	func(0, board, ans, N);
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