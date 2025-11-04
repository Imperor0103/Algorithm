#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	double h[51];
	for (int i = 0; i < n; i++)
	{
		cin >> h[i];
	}

	int result = 0;

	for (int i = 0; i < n; i++)
	{
		int visible = 0;

		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;

			bool canSee = true;
			int left = i < j ? i : j;
			int right = i > j ? i : j;

			for (int k = left + 1; k < right; k++)
			{
				double heightLimit = (h[right] - h[left]) * (k - left) / (right - left) + h[left];
				if (h[k] >= heightLimit)
				{
					canSee = false;
					break;
				}
			}

			if (canSee)
				visible++;
		}

		result = result > visible ? result : visible;
	}
	cout << result;

	return 0;
}