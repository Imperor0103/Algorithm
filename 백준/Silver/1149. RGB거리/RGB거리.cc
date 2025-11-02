#include <iostream>

using namespace std;

int CustomMin(int a, int b)
{
	return (a < b) ? a : b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	int cost[1001][3];
	int dp[1001][3];

	for (int i = 1; i <= N; i++)
	{
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}
	dp[1][0] = cost[1][0];
	dp[1][1] = cost[1][1];
	dp[1][2] = cost[1][2];

	for (int i = 2; i <= N; i++)
	{
		dp[i][0] = CustomMin(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
		dp[i][1] = CustomMin(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		dp[i][2] = CustomMin(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
	}

	int result = dp[N][0];
	if (dp[N][1] < result) 
		result = dp[N][1];
	if (dp[N][2] < result) 
		result = dp[N][2];

	cout << result << '\n';
	return 0;
}