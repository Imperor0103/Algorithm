#include <iostream>

using namespace std;

struct Node
{
	int x, y;
};

void BFS(int* maze, bool* visited, int rowSize, int colSize)
{
	Node* queue = new Node[10000];
	int front = 0;
	int rear = 0;

	int dirRow[4] = { -1, 1, 0, 0 };	// 세로
	int dirCol[4] = { 0, 0, -1, 1 };	// 가로
	int dirSize = 4;

	queue[rear++] = { 0, 0 };
	visited[0 * colSize + 0] = true;

	while (front < rear)
	{
		Node cur = queue[front++];
		int curRow = cur.y;	// 행(세로)
		int curCol = cur.x;	// 열(가로)

		for (int i = 0; i < dirSize; i++)
		{
			int nextRow = curRow + dirRow[i];
			int nextCol = curCol + dirCol[i];

			if (nextRow < 0 || nextCol < 0 || nextRow >= rowSize || nextCol >= colSize)
				continue;
			if (*(maze + nextRow * colSize + nextCol) == 0 ||
				*(visited + nextRow * colSize + nextCol))
				continue;

			// maze[row][col]: row(y좌표)는 세로, col(x좌표)는 가로			
			// row * (col의 개수) + col가 올바른 1차원 인덱스
			*(visited + nextRow * colSize + nextCol) = true;
			*(maze + nextRow * colSize + nextCol) = *(maze + curRow * colSize + curCol) + 1;
			queue[rear++] = { nextCol, nextRow };
		}
	}
	delete[] queue;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	// N: row(세로 길이)
	// M: col(가로 길이)
	int* maze = new int[N * M];
	bool* visited = new bool[N * M] {false};

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char c;
			cin >> c;
			*(maze + i * M + j) = c - '0';
		}
	}

	BFS(maze, visited, N, M);

	cout << *(maze + (N - 1) * M + M - 1) << '\n';

	delete[] maze;
	delete[] visited;
	return 0;
}