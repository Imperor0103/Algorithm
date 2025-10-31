#include <iostream>

using namespace std;

// DFS(재귀)
void DFS_Recursive(int* adj, bool* visited, int n, int node, int* count)
{
	visited[node] = true;

	for (int next = 1; next <= n; next++)
	{
		int row = node;
		int col = next;

		if (*(adj + row * (n + 1) + col) && !visited[next])
		{
			(*count)++;
			DFS_Recursive(adj, visited, n, next, count);
		}
	}
}

// DFS(반복, 비재귀)
void DFS_Iterative(int* adj, bool* visited, int n, int start, int* count)
{
	int* stack = new int[n + 1];
	int top = -1;

	stack[++top] = start;	// push

	while (top >= 0)
	{
		int node = stack[top--];	// pop
		if (visited[node])
			continue;
		visited[node] = true;
		if (node != start)
			(*count)++;

		// Recursive와 탐색 순서를 일치하기 위해 역순으로 push
		// push할 때 count하는 것이 문제라는데
		for (int next = n; next >= 1; next--)
		{
			int row = node;
			int col = next;

			if (*(adj + row * (n + 1) + col) && !visited[next])
			{
				stack[++top] = next;	// push
				//(*count)++;
			}
		}
	}
	delete[] stack;
}

void BFS(int* adj, bool* visited, int n, int start, int* count)
{
	int* queue = new int[n + 1];
	int front = 0, rear = 0;

	queue[rear++] = start;	// enqueue
	visited[start] = true;

	while (front < rear)
	{
		int node = queue[front++]; // dequeue

		for (int next = 1; next <= n; next++)
		{
			int row = node;
			int col = next;

			if (*(adj + row * (n + 1) + col) && !visited[next])
			{
				visited[next] = true;
				queue[rear++] = next;	// enqueue
				(*count)++;
			}
		}
	}
	delete[] queue;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// N: 컴퓨터(node)의 수
	// M: 컴퓨터 간의 간선(edge)의 수
	int N, M;
	cin >> N >> M;

	int* adj = new int[(N + 1) * (N + 1)] {0};	// 인접행렬은 정사각행렬
	bool* visited = new bool[(N + 1)] {false};
	int count = 0;

	for (int i = 0; i < M; i++)
	{
		// 예: [5][7] 2차원 행렬(row: 5, col: 7)에서 [3][4]은 21 + 5 = 26번째이며, 
		// 이를 1차원 행렬로 나타내면 3 * 7 + 4 번째
		int a, b;
		cin >> a >> b;
		*(adj + a * (N + 1) + b) = 1;	// 행렬의 [a][b] 성분		
		*(adj + b * (N + 1) + a) = 1;	// 행렬의 [b][a] 성분
	}

	// 문제 조건: 1번 컴퓨터에서 시작
	// DFS(재귀)
	//DFS_Recursive(adj, visited, N, 1, &count);

	// DFS(비재귀)
	//DFS_Iterative(adj, visited, N, 1, &count);

	// BFS
	BFS(adj, visited, N, 1, &count);

	cout << count << '\n';
	return 0;
}