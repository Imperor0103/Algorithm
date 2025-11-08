#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	int triangle[501][501];
	int dp[501][501];

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j <= i; j++) 
		{
			cin >> triangle[i][j];
		}
	}

	dp[0][0] = triangle[0][0];

	for (int i = 1; i < n; i++) 
	{
		for (int j = 0; j <= i; j++) 
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j] + triangle[i][j];
			else if (j == i)
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			else
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
		}
	}

	int result = 0;
	for (int j = 0; j < n; j++) 
	{
		result = max(result, dp[n - 1][j]);
	}

	cout << result << '\n';
	return 0;
}