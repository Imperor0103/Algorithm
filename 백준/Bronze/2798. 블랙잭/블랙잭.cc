#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	int cards[100];
	for (int i = 0; i < N; i++)
	{
		cin >> cards[i];
	}

	int answer = 0;

	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				int sum = cards[i] + cards[j] + cards[k];
				if (sum <= M && sum > answer)
					answer = sum;
			}
		}
	}

	cout << answer;
	return 0;
}
