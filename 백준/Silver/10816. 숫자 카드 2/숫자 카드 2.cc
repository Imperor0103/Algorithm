#include <iostream>

using namespace std;

void CustomSwap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void CustomQuickSort(int* arr, int left, int right)
{
	if (left >= right)
		return;

	int pivot = arr[(left + right) / 2];
	int i = left;
	int j = right;

	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;

		if (i <= j)
		{
			CustomSwap(&arr[i], &arr[j]);
			i++;
			j--;
		}
	}

	if (left < j)
		CustomQuickSort(arr, left, j);
	if (i < right)
		CustomQuickSort(arr, i, right);
}

// target이 나타나는 처음 위치 찾는다
int FirstAppear(int* arr, int size, int target)
{
	int left = 0;
	int right = size;
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] < target)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}

// target이 나타나는 마지막 위치+1
int LastAppear(int* arr, int size, int target)
{
	int left = 0;
	int right = size;
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] <= target)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	int* cards = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> cards[i];
	}

	CustomQuickSort(cards, 0, N - 1);

	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int target;
		cin >> target;
		int first = FirstAppear(cards, N, target);
		int last = LastAppear(cards, N, target);
		cout << last - first << " ";
	}

	delete[] cards;
	return 0;
}