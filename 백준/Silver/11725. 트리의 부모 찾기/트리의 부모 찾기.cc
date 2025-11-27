#include <iostream>
using namespace std;

void AddEdge(int head[], int to[], int next[], int* idx, int a, int b)
{
	to[*idx] = b;
	next[*idx] = head[a];
	head[a] = *idx;
	(*idx)++;
}

void BFS(int head[], int to[], int next[], int parent[], int N)
{
	bool* visited = new bool[N + 1]();
	int* queueArr = new int[N + 1];
	int front = 0, rear = 0;

	queueArr[rear++] = 1;
	visited[1] = true;

	while (front < rear)
	{
		int cur = queueArr[front++];

		for (int i = head[cur]; i != -1; i = next[i])
		{
			int nxt = to[i];
			if (!visited[nxt])
			{
				visited[nxt] = true;
				parent[nxt] = cur;
				queueArr[rear++] = nxt;
			}
		}
	}

	delete[] visited;
	delete[] queueArr;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	int* head = new int[N + 1];
	int* to = new int[(N - 1) * 2];
	int* next = new int[(N - 1) * 2];
	int* parent = new int[N + 1];

	int idx = 0;

	// head 초기화
	for (int i = 1; i <= N; i++)
	{
		head[i] = -1;
	}
	// 간선 입력
	for (int i = 0; i < N - 1; i++) 
	{
		int a, b;
		cin >> a >> b;
		AddEdge(head, to, next, &idx, a, b);
		AddEdge(head, to, next, &idx, b, a);
	}

	BFS(head, to, next, parent, N);

	for (int i = 2; i <= N; i++)
	{
		cout << parent[i] << "\n";
	}

	delete[] head;
	delete[] to;
	delete[] next;
	delete[] parent;
	return 0;
}