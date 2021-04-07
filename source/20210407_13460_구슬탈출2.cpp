#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main()
{
	int answer = 0;
	int N, M;
	cin >> N >> M;

	vector<vector<int>> board(N, vector<int>(M, 0));

	vector<vector<int>> ballLoc(2, vector<int>(2, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char a;
			cin >> a;
			switch (a)
			{
			case '#':
				board[i][j] = 9;
				break;
			case 'O':
				board[i][j] = 1;
				break;
			case 'B':
				ballLoc[1][0] = i;
				ballLoc[1][1] = j;
				break;
			case 'R':
				ballLoc[0][0] = i;
				ballLoc[0][1] = j;
				break;
			default:
				break;
			}
		}
	}

	queue<vector<vector<int>>> mQ;
	set<vector<vector<int>>> mS;
	mQ.push(ballLoc);

	bool findedAns = false;
	while (!mQ.empty())
	{
		int qSize = mQ.size();
		answer++;

		bool check = true;
		for (int k = 0; k < qSize; k++)
		{
			vector<vector<int>> cur = mQ.front();
			mQ.pop();
			// 중복 형태 방지
			if (mS.find(cur) != mS.end()) continue;
			mS.insert(cur);

			// 위
			vector<vector<int>> nCur = cur;
			// 블루볼
			check = true;
			for (int i = nCur[1][0] - 1; i >= 0; i--)
			{
				if (board[i][nCur[1][1]] == 9) break;
				else if (board[i][nCur[1][1]] == 1)
				{
					check = false;
					break;
				}
				else nCur[1][0] = i;
			}
			if (check)
			{
				//레드볼
				check = false;
				for (int i = nCur[0][0] - 1; i >= 0; i--)
				{
					if (board[i][nCur[0][1]] == 9) break;
					else if (board[i][nCur[0][1]] == 1)
					{
						check = true;
						break;
					}
					else nCur[0][0] = i;
				}
				if (check)
				{
					findedAns = true;
					break;
				}

				if (nCur[0][0] == nCur[1][0] && nCur[0][1] == nCur[1][1])
				{
					if (cur[0][0] < cur[1][0]) nCur[1][0]++;
					else nCur[0][0]++;
				}
				mQ.push(nCur);
			}
			// 아래
			nCur = cur;
			// 블루볼
			check = true;
			for (int i = nCur[1][0] + 1; i < board.size(); i++)
			{
				if (board[i][nCur[1][1]] == 9) break;
				else if (board[i][nCur[1][1]] == 1)
				{
					check = false;
					break;
				}
				else nCur[1][0] = i;
			}
			if (check)
			{
				//레드볼
				check = false;
				for (int i = nCur[0][0] + 1; i < board.size(); i++)
				{
					if (board[i][nCur[0][1]] == 9) break;
					else if (board[i][nCur[0][1]] == 1)
					{
						check = true;
						break;
					}
					else nCur[0][0] = i;
				}
				if (check)
				{
					findedAns = true;
					break;
				}

				if (nCur[0][0] == nCur[1][0] && nCur[0][1] == nCur[1][1])
				{
					if (cur[0][0] < cur[1][0]) nCur[0][0]--;
					else nCur[1][0]--;
				}
				mQ.push(nCur);
			}
			// 왼
			nCur = cur;
			// 블루볼
			check = true;
			for (int i = nCur[1][1] - 1; i >= 0; i--)
			{
				if (board[nCur[1][0]][i] == 9) break;
				else if (board[nCur[1][0]][i] == 1)
				{
					check = false;
					break;
				}
				else nCur[1][1] = i;
			}
			if (check)
			{
				//레드볼
				check = false;
				for (int i = nCur[0][1] - 1; i >= 0; i--)
				{
					if (board[nCur[0][0]][i] == 9) break;
					else if (board[nCur[0][0]][i] == 1)
					{
						check = true;
						break;
					}
					else nCur[0][1] = i;
				}
				if (check)
				{
					findedAns = true;
					break;
				}

				if (nCur[0][0] == nCur[1][0] && nCur[0][1] == nCur[1][1])
				{
					if (cur[0][1] < cur[1][1]) nCur[1][1]++;
					else nCur[0][1]++;
				}
				mQ.push(nCur);
			}
			// 오
			nCur = cur;
			// 블루볼
			check = true;
			for (int i = nCur[1][1] + 1; i < board[0].size(); i++)
			{
				if (board[nCur[1][0]][i] == 9) break;
				else if (board[nCur[1][0]][i] == 1)
				{
					check = false;
					break;
				}
				else nCur[1][1] = i;
			}
			if (check)
			{
				//레드볼
				check = false;
				for (int i = nCur[0][1] + 1; i < board[0].size(); i++)
				{
					if (board[nCur[0][0]][i] == 9) break;
					else if (board[nCur[0][0]][i] == 1)
					{
						check = true;
						break;
					}
					else nCur[0][1] = i;
				}
				if (check)
				{
					findedAns = true;
					break;
				}

				if (nCur[0][0] == nCur[1][0] && nCur[0][1] == nCur[1][1])
				{
					if (cur[0][1] < cur[1][1]) nCur[0][1]--;
					else nCur[1][1]--;
				}
				mQ.push(nCur);
			}
		}
		if (findedAns) break;
		if (answer >= 10) break; // 특이하게 10번 이하까지만 답을 찾음

	}
	if (findedAns == false) answer = -1;
	cout << answer << endl;
	return 0;
}