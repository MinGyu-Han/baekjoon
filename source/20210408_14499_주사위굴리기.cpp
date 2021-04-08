#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> moveDice(vector<vector<int>> dice, int kind)
{
	vector<vector<int>> newDice;
	if (kind == 1) // 悼率
	{
		newDice = vector<vector<int>>({ {0, dice[0][1], 0}, {dice[3][1], dice[1][0], dice[1][1]}
			, {0, dice[2][1], 0}, {0, dice[1][2], 0} });
	}
	else if (kind == 2) // 辑率
	{
		newDice = vector<vector<int>>({ {0, dice[0][1], 0}, {dice[1][1], dice[1][2], dice[3][1]}
			, {0, dice[2][1], 0}, {0, dice[1][0], 0} });
	}
	else if (kind == 3) // 合率
	{
		newDice = vector<vector<int>>({ {0, dice[1][1], 0}, {dice[1][0], dice[2][1], dice[1][2]}
			, {0, dice[3][1], 0}, {0, dice[0][1], 0} });
	}
	else if (kind == 4) // 巢率
	{
		newDice = vector<vector<int>>({ {0, dice[3][1], 0}, {dice[1][0], dice[0][1], dice[1][2]}
			, {0, dice[1][1], 0}, {0, dice[2][1], 0} });
	}
	return newDice;
}

int main()
{
	int N, M, x, y, K;
	cin >> N >> M >> x >> y >> K;

	vector<vector<int>> board(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) cin >> board[i][j];
	}
	vector<int> move(K, 0);
	for (int i = 0; i < K; i++) cin >> move[i];

	//林荤困
	vector<vector<int>> dice({ {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0} });

	for (int i = 0; i < move.size(); i++)
	{
		int tX = x;
		int tY = y;
		if (move[i] == 1) y++;
		else if (move[i] == 2) y--;
		else if (move[i] == 3) x--;
		else if (move[i] == 4) x++;

		if (x < 0 || y < 0 || x > N - 1 || y > M - 1)
		{
			x = tX;
			y = tY;
			continue;
		}

		dice = moveDice(dice, move[i]);
		if (board[x][y] == 0) board[x][y] = dice[3][1];
		else
		{
			dice[3][1] = board[x][y];
			board[x][y] = 0;
		}
		cout << dice[1][1] << endl;
	}
	return 0;
}