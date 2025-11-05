#include <iostream>

using namespace std;

void CountMinimumCoins(int coins[], int size, int value)
{
	int count = 0;
	// 각 동전이 이전 동전의 배수라면 최적해가 되어 greedy algorithm이 성립한다
	for (int i = 0; i < size; i++)
	{
		int divisor = coins[i];
		count += value / divisor;
		cout << value / divisor << " ";
		value %= divisor;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	int coins[3] = { 300, 60, 10 };


	if (T % 10 != 0)
	{
		cout << -1;
		return 0;
	}

	CountMinimumCoins(coins, 3, T);
	return 0;
}