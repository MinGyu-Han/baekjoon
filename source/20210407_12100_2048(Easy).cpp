#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<vector<int>> move(vector<vector<int>> board, int kind)
{
	vector<vector<int>> newBoard(board.size(), vector<int>(board.size(), 0));
	if (kind == 0)	// 위
	{
		for (int i = 0; i < board.size(); i++)
		{
			int k = 0;
			int before = 0;
			for (int j = 0; j < board.size(); j++)
			{
				if (board[j][i] == 0) continue;

				if (before == 0) before = board[j][i];
				else
				{
					if (before == board[j][i])
					{
						newBoard[k++][i] = before * 2;
						before = 0;
					}
					else
					{
						newBoard[k++][i] = before;
						before = board[j][i];
					}
				}
			}
			if (before != 0) newBoard[k][i] = before;
		}
	}
	else if (kind == 1)	// 아래
	{
		for (int i = 0; i < board.size(); i++)
		{
			int k = board.size() - 1;
			int before = 0;
			for (int j = board.size() - 1; j >= 0; j--)
			{
				if (board[j][i] == 0) continue;

				if (before == 0) before = board[j][i];
				else
				{
					if (before == board[j][i])
					{
						newBoard[k--][i] = before * 2;
						before = 0;
					}
					else
					{
						newBoard[k--][i] = before;
						before = board[j][i];
					}
				}
			}
			if (before != 0) newBoard[k][i] = before;
		}

	}
	else if (kind == 2) // 왼쪽
	{
		for (int i = 0; i < board.size(); i++)
		{
			int k = 0;
			int before = 0;
			for (int j = 0; j < board.size(); j++)
			{
				if (board[i][j] == 0) continue;

				if (before == 0) before = board[i][j];
				else
				{
					if (before == board[i][j])
					{
						newBoard[i][k++] = before * 2;
						before = 0;
					}
					else
					{
						newBoard[i][k++] = before;
						before = board[i][j];
					}
				}
			}
			if (before != 0) newBoard[i][k] = before;
		}
	}
	else if (kind == 3)	// 오른쪽
	{
		for (int i = 0; i < board.size(); i++)
		{
			int k = board.size() - 1;
			int before = 0;
			for (int j = board.size() - 1; j >= 0; j--)
			{
				if (board[i][j] == 0) continue;

				if (before == 0) before = board[i][j];
				else
				{
					if (before == board[i][j])
					{
						newBoard[i][k--] = before * 2;
						before = 0;
					}
					else
					{
						newBoard[i][k--] = before;
						before = board[i][j];
					}
				}
			}
			if (before != 0) newBoard[i][k] = before;
		}
	}
	return newBoard;
}

int main()
{
	int N;
	cin >> N;
	vector<vector<int>> board(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) cin >> board[i][j];
	}

	queue<vector<vector<int>>> mQ;
	mQ.push(board);
	set<vector<vector<int>>> mS;
	mS.insert(board);

	for (int i = 0; i < 5; i++)
	{
		int qSize = mQ.size();
		for (int j = 0; j < qSize; j++)
		{
			vector<vector<int>> cur = mQ.front();
			mQ.pop();

			vector<vector<int>> tmp = move(cur, 0);
			if (mS.find(tmp) == mS.end())
			{
				mQ.push(tmp);
				mS.insert(tmp);
			}
			tmp = move(cur, 1);
			if (mS.find(tmp) == mS.end())
			{
				mQ.push(tmp);
				mS.insert(tmp);
			}
			tmp = move(cur, 2);
			if (mS.find(tmp) == mS.end())
			{
				mQ.push(tmp);
				mS.insert(tmp);
			}
			tmp = move(cur, 3);
			if (mS.find(tmp) == mS.end())
			{
				mQ.push(tmp);
				mS.insert(tmp);
			}
		}
	}
	int answer = 0;
	for (set<vector<vector<int>>>::iterator iter = mS.begin(); iter != mS.end(); iter++)
	{
		vector<vector<int>> cur = *iter;

		for (int i = 0; i < cur.size(); i++)
		{
			for (int j = 0; j < cur[i].size(); j++)
			{
				answer = max(answer, cur[i][j]);
			}
		}
	}
	cout << answer << endl;

	return 0;
}