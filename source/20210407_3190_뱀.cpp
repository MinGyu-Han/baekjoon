#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool checkEnd(vector<vector<int>>& board, vector<int>& loc)
{
	// 범위 초과(벽에 충돌)시 false 리턴
	if (loc[0] < 0 || loc[1] < 0 || loc[0] > board.size() - 1 || loc[1] > board.size() - 1) return false;
	// 자기 몸에 맞았을 시 false 리턴
	if (board[loc[0]][loc[1]] == 2) return false;
	return true; // 나머지 true 리턴
}

int main()
{
	int N;
	cin >> N;
	int K;
	cin >> K;
	vector<vector<int>> board(N, vector<int>(N, 0));
	for (int i = 0; i < K; i++)
	{
		int a, b;
		cin >> a >> b;
		board[a - 1][b - 1] = 1; // 사과위치 board에 표시
	}
	int L;
	cin >> L;

	vector<int> X(L, 0);
	vector<char> C(L, '0');

	for (int i = 0; i < L; i++)
	{
		cin >> X[i] >> C[i];
	}
	deque<vector<int>> mQ; //지렁이의 몸 위치를 담을 deque
	mQ.push_back(vector<int>({ 0, 0 })); // 시작위치 저장
	board[0][0] = 2; // board에 지렁이 몸 표시
	int direct = 0; // 0-오른쪽, 1-아래, 2-왼쪽, 3-위쪽
	int time = 0;
	bool check = true;
	for (int i = 0; i < L; i++)
	{
		for (; time < X[i]; time++)
		{
			vector<int> newLoc;
			// 방향에 따른 1칸 전진한 좌표 계산
			if (direct == 0) newLoc = vector<int>({ mQ.back()[0], mQ.back()[1] + 1 });
			else if (direct == 1) newLoc = vector<int>({ mQ.back()[0] + 1, mQ.back()[1] });
			else if (direct == 2) newLoc = vector<int>({ mQ.back()[0], mQ.back()[1] - 1 });
			else if (direct == 3) newLoc = vector<int>({ mQ.back()[0] - 1, mQ.back()[1] });

			// 진행 가능한지 확인
			check = checkEnd(board, newLoc);
			if (check == false)	//진행 불가시 종료
			{
				time++;
				break;
			}
			// 진행한 위치에 사과가 없을 경우, 꼬리 끝몸 제거
			if (board[newLoc[0]][newLoc[1]] != 1)
			{
				board[mQ.front()[0]][mQ.front()[1]] = 0;
				mQ.pop_front();
			}
			board[newLoc[0]][newLoc[1]] = 2; // 진행한 위치에 몸 표시
			mQ.push_back(newLoc);	// 큐에 지렁이 몸 위치 넣음
		}
		if (check == false) break; // 진행 불가시 종료

		// 방향 전환
		if (C[i] == 'D') direct = (direct + 1) % 4;
		else
		{
			direct--;
			if (direct == -1) direct = 3;
		}
	}
	if (check)	// 아직 죽지 않았을 경우 계속 같은 방향으로 진행
	{
		while (true)
		{
			vector<int> newLoc;

			if (direct == 0) newLoc = vector<int>({ mQ.back()[0], mQ.back()[1] + 1 });
			else if (direct == 1) newLoc = vector<int>({ mQ.back()[0] + 1, mQ.back()[1] });
			else if (direct == 2) newLoc = vector<int>({ mQ.back()[0], mQ.back()[1] - 1 });
			else if (direct == 3) newLoc = vector<int>({ mQ.back()[0] - 1, mQ.back()[1] });

			check = checkEnd(board, newLoc);
			time++;
			if (check == false)
			{
				break;
			}
			if (board[newLoc[0]][newLoc[1]] != 1)
			{
				board[mQ.front()[0]][mQ.front()[1]] = 0;
				mQ.pop_front();
			}
			board[newLoc[0]][newLoc[1]] = 2;
			mQ.push_back(newLoc);
		}
	}
	cout << time << endl;

	return 0;
}