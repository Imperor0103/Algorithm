#include <iostream>

using namespace std;

const int MAX = 100000;

void CustomEnqueue(int q[], int& rear, int x) 
{
	q[rear++] = x;
}

int CustomDequeue(int q[], int& front) 
{
	return q[front++];
}

bool IsEmpty(int front, int rear) 
{
	return front == rear;
}

int BFS(int visited[], int q[], int N, int K)
{
	int front = 0, rear = 0;

	CustomEnqueue(q, rear, N);
	visited[N] = 1;

	while (!IsEmpty(front, rear))
	{
		int x = CustomDequeue(q, front);

		if (x == K)
			return visited[x] - 1;

		int nextX[3] = { x - 1, x + 1, x * 2 };

		for (int i = 0; i < 3; i++) 
		{
			int nx = nextX[i];

			if (nx >= 0 && nx <= MAX && visited[nx] == 0) 
			{
				visited[nx] = visited[x] + 1;
				CustomEnqueue(q, rear, nx);
			}
		}
	}

	return -1; 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	cin >> N >> K;
	int visited[MAX + 1] = { 0 };
	int q[200001];

	cout << BFS(visited, q, N, K) << "\n";

	return 0;
}