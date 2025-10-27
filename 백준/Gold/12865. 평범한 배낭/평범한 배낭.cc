#include <iostream>

using namespace std;

void Pack(int** dp, int* w, int* v, int n, int k)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			// w[i]: 현재 물건의 무게
			// j: 허용무게
			if (j < w[i])
				dp[i][j] = dp[i - 1][j];	// 허용무게보다 크면 물건을 넣을 수 없다
			else
				dp[i][j] = dp[i - 1][j] > dp[i - 1][j - w[i]] + v[i] ?
							dp[i - 1][j] : dp[i - 1][j - w[i]] + v[i];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	cin >> N >> K;

	int W[101], V[101];
	for (int i = 1; i <= N; i++)
	{
		cin >> W[i] >> V[i];
	}

	// dp는 가치를 저장하는 2차원 배열
	// dp[i][j]: 0~i의 물건을 고려했을 때, 무게 한도가 j일 때 얻을 수 있는 최대 가치
	int** dp = new int* [N + 1];
	for (int i = 0; i <= N; i++)
	{
		dp[i] = new int[K + 1]();
	}

	Pack(dp, W, V, N, K);
	cout << dp[N][K];

	for (int i = 0; i <= N; i++)
	{
		delete[] dp[i];
	}
	delete[] dp;
	return 0;
}