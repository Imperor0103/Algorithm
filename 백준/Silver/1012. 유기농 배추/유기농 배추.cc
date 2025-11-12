#include <iostream>

using namespace std;

void DFS_Iterative(int field[50][50], bool visited[50][50], int startY, int startX, int M, int N)
{
	// 상하좌우 방향 (지역변수)
	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { -1, 1, 0, 0 };

	// 스택 직접 구현
	static int stackY[2500];
	static int stackX[2500];
	int top = -1;

	stackY[++top] = startY;
	stackX[top] = startX;
	visited[startY][startX] = true;

	while (top >= 0)
	{
		int y = stackY[top];
		int x = stackX[top--];

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N)
			{
				if (field[ny][nx] == 1 && !visited[ny][nx])
				{
					visited[ny][nx] = true;
					stackY[++top] = ny;
					stackX[top] = nx;
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

	int T;
	cin >> T;

	int M, N, K;

	int field[50][50];
	bool visited[50][50];

	while (T--)
	{
		cin >> M >> N >> K;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				field[i][j] = 0;
				visited[i][j] = false;
			}
		}

		// 배추 위치
		for (int i = 0; i < K; i++)
		{
			int x, y;
			cin >> x >> y;
			field[y][x] = 1;
		}

		int count = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (field[i][j] == 1 && !visited[i][j])
				{
					DFS_Iterative(field, visited, i, j, M, N);
					count++;
				}
			}
		}
		cout << count << '\n';
	}
	return 0;
}
