#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int answer = 0;
	int N, M;
	cin >> N >> M;
	vector<vector<int>> board(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) cin >> board[i][j];
	}
	// 1x4 형태 블록
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M - 3; j++)
		{
			answer = max(answer, board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i][j + 3]);
		}
	}
	// 4x1 형태의 블록
	for (int i = 0; i < N - 3; i++)
	{
		for (int j = 0; j < M; j++)
		{
			answer = max(answer, board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 3][j]);
		}
	}
	// 2x2 형태의 블록
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M - 1; j++)
		{
			answer = max(answer, board[i][j] + board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1]);
		}
	}
	// 2x3 형태의 블록들
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < M - 2; j++)
		{
			answer = max(answer, board[i][j + 2] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2]);
			answer = max(answer, board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2]);
			answer = max(answer, board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j]);
			answer = max(answer, board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 2]);

			answer = max(answer, board[i][j + 1] + board[i][j + 2] + board[i + 1][j] + board[i + 1][j + 1]);
			answer = max(answer, board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 1][j + 2]);

			answer = max(answer, board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2]);
			answer = max(answer, board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 1]);
		}
	}
	// 3x2 형태의 블록들
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M - 1; j++)
		{
			answer = max(answer, board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 2][j + 1]);
			answer = max(answer, board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1] + board[i + 2][j]);
			answer = max(answer, board[i][j] + board[i][j + 1] + board[i + 1][j] + board[i + 2][j]);
			answer = max(answer, board[i][j] + board[i][j + 1] + board[i + 1][j + 1] + board[i + 2][j + 1]);

			answer = max(answer, board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 2][j + 1]);
			answer = max(answer, board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 2][j]);

			answer = max(answer, board[i][j] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 2][j]);
			answer = max(answer, board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 2][j + 1]);
		}
	}
	cout << answer << endl;

	return 0;
}