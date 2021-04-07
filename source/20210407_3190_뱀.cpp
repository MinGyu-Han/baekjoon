#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool checkEnd(vector<vector<int>>& board, vector<int>& loc)
{
	// ���� �ʰ�(���� �浹)�� false ����
	if (loc[0] < 0 || loc[1] < 0 || loc[0] > board.size() - 1 || loc[1] > board.size() - 1) return false;
	// �ڱ� ���� �¾��� �� false ����
	if (board[loc[0]][loc[1]] == 2) return false;
	return true; // ������ true ����
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
		board[a - 1][b - 1] = 1; // �����ġ board�� ǥ��
	}
	int L;
	cin >> L;

	vector<int> X(L, 0);
	vector<char> C(L, '0');

	for (int i = 0; i < L; i++)
	{
		cin >> X[i] >> C[i];
	}
	deque<vector<int>> mQ; //�������� �� ��ġ�� ���� deque
	mQ.push_back(vector<int>({ 0, 0 })); // ������ġ ����
	board[0][0] = 2; // board�� ������ �� ǥ��
	int direct = 0; // 0-������, 1-�Ʒ�, 2-����, 3-����
	int time = 0;
	bool check = true;
	for (int i = 0; i < L; i++)
	{
		for (; time < X[i]; time++)
		{
			vector<int> newLoc;
			// ���⿡ ���� 1ĭ ������ ��ǥ ���
			if (direct == 0) newLoc = vector<int>({ mQ.back()[0], mQ.back()[1] + 1 });
			else if (direct == 1) newLoc = vector<int>({ mQ.back()[0] + 1, mQ.back()[1] });
			else if (direct == 2) newLoc = vector<int>({ mQ.back()[0], mQ.back()[1] - 1 });
			else if (direct == 3) newLoc = vector<int>({ mQ.back()[0] - 1, mQ.back()[1] });

			// ���� �������� Ȯ��
			check = checkEnd(board, newLoc);
			if (check == false)	//���� �Ұ��� ����
			{
				time++;
				break;
			}
			// ������ ��ġ�� ����� ���� ���, ���� ���� ����
			if (board[newLoc[0]][newLoc[1]] != 1)
			{
				board[mQ.front()[0]][mQ.front()[1]] = 0;
				mQ.pop_front();
			}
			board[newLoc[0]][newLoc[1]] = 2; // ������ ��ġ�� �� ǥ��
			mQ.push_back(newLoc);	// ť�� ������ �� ��ġ ����
		}
		if (check == false) break; // ���� �Ұ��� ����

		// ���� ��ȯ
		if (C[i] == 'D') direct = (direct + 1) % 4;
		else
		{
			direct--;
			if (direct == -1) direct = 3;
		}
	}
	if (check)	// ���� ���� �ʾ��� ��� ��� ���� �������� ����
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