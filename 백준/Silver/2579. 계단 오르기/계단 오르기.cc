#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int stairs[301];
	int dp[301];

	for (int i = 1; i <= n; i++)
	{
		cin >> stairs[i];
	}

	dp[1] = stairs[1];
	dp[2] = stairs[1] + stairs[2];
	dp[3] = (stairs[1] + stairs[3]) > (stairs[2] + stairs[3]) ?
		(stairs[1] + stairs[3]) : (stairs[2] + stairs[3]);

	for (int i = 4; i <= n; i++)
	{
		dp[i] = (dp[i - 2] + stairs[i]) > (dp[i - 3] + stairs[i - 1] + stairs[i]) ?
			(dp[i - 2] + stairs[i]) : (dp[i - 3] + stairs[i - 1] + stairs[i]);
	}

	cout << dp[n] << '\n';
	return 0;
}