#include <iostream>
#include <vector>

using namespace std;

int main()
{
	long long answer = 0;
	int N;
	cin >> N;
	vector<long long> A(N, 0);
	for (int i = 0; i < N; i++) cin >> A[i];
	long long B, C;
	cin >> B >> C;

	for (int i = 0; i < N; i++)
	{
		long long remain = A[i] - B;
		answer++;

		if (remain > 0)
		{
			if (remain % C != 0) answer++;
			answer += remain / C;
		}
	}
	cout << answer << endl;

	return 0;
}