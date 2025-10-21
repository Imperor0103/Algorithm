#include <iostream>

using namespace std;

void DFS(int start, int N, int** adj, bool* visited)
{
	int* stack = new int[N * N];
	int top = -1;

	stack[++top] = start;

	while (top >= 0)
	{
		int v = stack[top--];
		if (visited[v])
			continue;

		visited[v] = true;
		cout << v << " ";

		for (int i = N; i >= 1; i--)
		{
			if (adj[v][i] == 1 && !visited[i])
				stack[++top] = i;
		}
	}

	delete[] stack;
}

void BFS(int start, int N, int** adj, bool* visited)
{
	int* queue = new int[N + 1];
	int front = 0;
	int rear = 0;

	queue[rear++] = start;
	visited[start] = true;

	while (front < rear)
	{
		int v = queue[front++];
		cout << v << " ";

		for (int i = 1; i <= N; i++)
		{
			if (adj[v][i] == 1 && !visited[i])
			{
				visited[i] = true;
				if (rear < N + 1)
					queue[rear++] = i;
			}
		}
	}

	delete[] queue;
}

int main()
{
	int N, M, V;
	cin >> N >> M >> V;

	int** adj = new int* [N + 1];
	for (int i = 0; i <= N; i++)
	{
		adj[i] = new int[N + 1]();	
	}

	bool* visited = new bool[N + 1]();	

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a][b] = adj[b][a] = 1;
	}

	DFS(V, N, adj, visited);
	cout << "\n";

	fill(visited, visited + N + 1, false);	// visited 초기화
	BFS(V, N, adj, visited);
	cout << "\n";

	for (int i = 0; i <= N; i++)
	{
		delete[] adj[i];
	}
	delete[] adj;
	delete[] visited;

	return 0;
}