#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	cin >> N >> K;

	int q[5001];
	int front = 0, back = 0;

	for (int i = 1; i <= N; i++)
	{
		q[back] = i;
		back = (back + 1) % 5001;
	}

	cout << "<";

	while (front != back)
	{
		// K-1번 앞으로 보내기
		for (int i = 0; i < K - 1; i++)
		{
			// front 값 꺼내서 뒤에 다시 넣음
			q[back] = q[front];
			back = (back + 1) % 5001;
			front = (front + 1) % 5001;
		}

		// K번째 요소 제거(pop)
		cout << q[front];
		front = (front + 1) % 5001;

		if (front != back)
			cout << ", ";
	}
	cout << ">";
	return 0;
}