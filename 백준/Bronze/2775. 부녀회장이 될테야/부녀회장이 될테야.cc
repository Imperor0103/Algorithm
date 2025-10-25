#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 0층: 1 2 3 4 5 6 ...
	// 1층: 1 3 6 10 15 21 ...
	// 2층: 1 4 10 20 35 56 ...
	// apt[a][b]: a층 b호
	// apt[a][b] = apt[a-1][b] + apt[a][b-1]

	int T;
	cin >> T;

	while (T--)
	{
		int k, n;
		cin >> k >> n;

		int apt[15][15] = { 0 };

		// 0층
		for (int i = 1; i <= n; i++)
		{
			apt[0][i] = i;
		}

		// k층, n호
		for (int i = 1; i <= k; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (j == 1)
					apt[i][j] = 1;
				else
					apt[i][j] = apt[i - 1][j] + apt[i][j - 1];
			}
		}
		cout << apt[k][n] << '\n';
	}

	return 0;
}