#include <iostream>

using namespace std;

void Padovan(long long dp[], int size)
{
	dp[1] = dp[2] = dp[3] = 1;

	for (int i = 4; i <= size; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 3];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	long long dp[101];       
	Padovan(dp, 100);    

	while (T--)
	{
		int N;
		cin >> N;
		cout << dp[N] << "\n";
	}

	return 0;
}