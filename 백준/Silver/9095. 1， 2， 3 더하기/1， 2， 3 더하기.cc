#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	int dp[11] = { 0,1,2,4 };

	for (int i = 4; i <= 10; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	while (T--)
	{
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}

	return 0;
}