#include <iostream>
using namespace std;

struct Edge
{
	int to;
	int cost;
	int next;
};

void AddEdge(Edge* edges, int* head, int* edgeCount, int a, int b, int c)
{
	edges[*edgeCount].to = b;
	edges[*edgeCount].cost = c;
	edges[*edgeCount].next = head[a];
	head[a] = *edgeCount;
	(*edgeCount)++;
}

void BFS(int* head, Edge* edges, int* dist, bool* visited, int* queueArr,
	int* farNode, int* maxDist, int start, int n)
{
	// 탐색 전 초기화
	for (int i = 1; i <= n; i++) 
	{
		dist[i] = -1;
		visited[i] = false;
	}
	int front = 0;
	int rear = 0;
	queueArr[rear++] = start;
	dist[start] = 0;
	visited[start] = true;
	*farNode = start;
	*maxDist = 0;

	// BFS
	while (front < rear)
	{
		int cur = queueArr[front++];

		for (int i = head[cur]; i != -1; i = edges[i].next)
		{
			int nxt = edges[i].to;
			int w = edges[i].cost;

			if (!visited[nxt])
			{
				visited[nxt] = true;
				dist[nxt] = dist[cur] + w;
				queueArr[rear++] = nxt;

				if (dist[nxt] > *maxDist)
				{
					*maxDist = dist[nxt];
					*farNode = nxt;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	int* head = new int[N + 1];
	Edge* edges = new Edge[2 * (N - 1) + 5];
	int* edgeCount = new int;
	*edgeCount = 0;

	for (int i = 1; i <= N; i++)
	{
		head[i] = -1;
	}

	for (int i = 0; i < N - 1; i++) 
	{
		int a, b, c;
		cin >> a >> b >> c;
		AddEdge(edges, head, edgeCount, a, b, c);
		AddEdge(edges, head, edgeCount, b, a, c);
	}

	int* dist = new int[N + 1];
	bool* visited = new bool[N + 1];
	int* queueArr = new int[N + 1];
	
	// 1번 노드에서 가장 먼 곳을 찾고 A에 저장
	int A, dA;
	BFS(head, edges, dist, visited, queueArr, &A, &dA, 1, N);

	// A에서 가장 먼 곳 찾아서 B에 저장하면 A에서 B까지 길이가 diameter
	int B, diameter;
	BFS(head, edges, dist, visited, queueArr, &B, &diameter, A, N);

	cout << diameter << "\n";

	delete[] head;
	delete[] edges;
	delete[] dist;
	delete[] visited;
	delete[] queueArr;
	delete edgeCount;

	return 0;
}