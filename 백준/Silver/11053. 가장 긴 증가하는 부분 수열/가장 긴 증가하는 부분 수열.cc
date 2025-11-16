#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	int* A = new int[N];
	int* dp = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	int answer = 0;

	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;  // 자기 자신만 포함하면 길이 1

		for (int j = 0; j < i; j++)
		{
			if (A[j] < A[i])
			{
				if (dp[j] + 1 > dp[i])
					dp[i] = dp[j] + 1;
			}
		}
		if (dp[i] > answer)
			answer = dp[i];
	}

	cout << answer << '\n';

	delete[] A;
	delete[] dp;

	return 0;
}