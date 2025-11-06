#include <iostream>

using namespace std;

void CustomSwap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void CustomPush(int* heap, int* size, int x)
{
	int cur = (*size)++;
	heap[cur] = x;

	while (cur > 0)
	{
		int parent = (cur - 1) / 2;
		if (heap[parent] <= heap[cur])
			break;
		CustomSwap(&heap[parent], &heap[cur]);
		cur = parent;
	}
}

int CustomPop(int* heap, int* size)
{
	if (*size == 0)
		return 0;
	int ret = heap[0];
	(*size)--;
	heap[0] = heap[*size];
	int cur = 0;

	while (true)
	{
		int left = cur * 2 + 1;
		int right = cur * 2 + 2;
		int smallest = cur;

		if (left < *size && heap[left] < heap[smallest])
			smallest = left;
		if (right < *size && heap[right] < heap[smallest])
			smallest = right;
		if (smallest == cur)
			break;

		CustomSwap(&heap[cur], &heap[smallest]);
		cur = smallest;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	int heap[100000];
	int size = 0;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		CustomPush(heap, &size, x);
	}

	int total = 0;
	while (size > 1)
	{
		int a = CustomPop(heap, &size);
		int b = CustomPop(heap, &size);
		int sum = a + b;
		total += sum;
		CustomPush(heap, &size, sum);
	}

	cout << total << '\n';
	return 0;
}