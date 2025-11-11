#include <iostream>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	int arr[1000];
	int removeOrder[1000];
	int removeCount = 0;
	int curIdx = 0;
	int remain = N;

	for (int i = 0; i < N; i++)
	{
		arr[i] = i + 1;
	}

	while (remain > 0)
	{
		int move = 0;

		// 살아있는 사람 중 K번째 찾기
		while (move < K)
		{
			if (arr[curIdx] != 0) // 제거되지 않은 사람만 카운트
				move++;

			if (move == K)
				break;

			curIdx = (curIdx + 1) % N;
		}

		removeOrder[removeCount] = arr[curIdx];
		removeCount++;
		arr[curIdx] = 0;
		remain--;

		while (remain > 0 && arr[curIdx] == 0)
		{
			curIdx = (curIdx + 1) % N;
		}
	}

	cout << "<";
	for (int i = 0; i < N; i++)
	{
		cout << removeOrder[i];
		if (i != N - 1)
			cout << ", ";
	}
	cout << ">" << '\n';

	return 0;
}
