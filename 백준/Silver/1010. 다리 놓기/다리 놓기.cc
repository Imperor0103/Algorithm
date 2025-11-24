#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		int N, M;
		cin >> N >> M;

		long long combination = 1;	// nCm

		for (int i = 1; i <= N; i++)
		{
			combination = combination * (M - i + 1) / i;
		}

		cout << combination << "\n";
	}

	return 0;
}