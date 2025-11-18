#include <iostream>

using namespace std;

void DFS_Iterative(int graph[][1001], bool visited[], int size[], int start)
{
	int stack[100000];
	int top = -1;

	stack[++top] = start;
	visited[start] = true;

	while (top >= 0)
	{
		int node = stack[top--]; // pop

		for (int i = 0; i < size[node]; i++)
		{
			int next = graph[node][i];
			if (!visited[next])
			{
				visited[next] = true;
				stack[++top] = next; // push
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	int graph[1001][1001] = { 0 };
	int size[1001] = { 0 };
	bool visited[1001] = { false };

	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;

		graph[u][size[u]++] = v;
		graph[v][size[v]++] = u;
	}

	int count = 0;


	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			DFS_Iterative(graph, visited, size, i);
			count++;
		}
	}
	cout << count;
	return 0;
}