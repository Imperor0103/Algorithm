#include <iostream>

using namespace std;

void CustomBubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int arr[9];
	int sum = 0;

	for (int i = 0; i < 9; i++) 
	{
		cin >> arr[i];
		sum += arr[i];
	}

	int a = -1, b = -1;
	// 2명을 찾는 브루트포스
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - (arr[i] + arr[j]) == 100)
			{
				a = i;
				b = j;
				break;
			}
		}
		if (a != -1) 
			break;
	}

	// 7명을 새로운 배열로 복사
	int result[7];
	int idx = 0;
	for (int i = 0; i < 9; i++)
	{
		if (i == a || i == b) 
			continue;
		result[idx++] = arr[i];
	}

	CustomBubbleSort(result, 7);

	for (int i = 0; i < 7; i++)
	{
		cout << result[i] << "\n";
	}

	return 0;
}