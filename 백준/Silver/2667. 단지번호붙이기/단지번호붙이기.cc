#include <iostream>

using namespace std;

struct Node
{
	int x, y;
};


int DFS(int map[25][25], bool visited[25][25], int startX, int startY, int N)
{
	Node stack[625];
	int top = -1;

	stack[++top] = { startX, startY };
	visited[startX][startY] = true;

	int count = 0;
	int dirSize = 4;
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };

	while (top >= 0)
	{
		Node now = stack[top--];
		count++;

		for (int i = 0; i < 4; i++)
		{
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N)
			{
				if (map[nx][ny] == 1 && !visited[nx][ny])
				{
					visited[nx][ny] = true;
					stack[++top] = { nx, ny };
				}
			}
		}
	}
	return count;
}

// 재귀를 사용하지 않는 QuickSort
void CustomQuickSort(int arr[], int left, int right)
{
	int lstack[625];	// 분할의 왼쪽 인덱스 저장
	int rstack[625];	// 분할의 오른쪽 인덱스 저장
	int top = -1;

	lstack[++top] = left;
	rstack[top] = right;

	while (top >= 0)
	{
		int l = lstack[top];
		int r = rstack[top--];

		while (l < r)
		{
			int pivot = arr[(l + r) / 2];
			int i = l;
			int j = r;

			while (i <= j)
			{
				while (arr[i] < pivot)
				{
					i++;
				}
				while (arr[j] > pivot)
				{
					j--;
				}

				if (i <= j)
				{
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
					i++;
					j--;
				}
			}

			// 오른쪽 구간을 스택에 저장
			if (i < r)
			{
				lstack[++top] = i;
				rstack[top] = r;
			}
			// 왼쪽 구간으로 반복
			r = j;
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

	int map[25][25];
	bool visited[25][25] = { false };

	for (int i = 0; i < N; i++)
	{
		string line;
		cin >> line;
		for (int j = 0; j < N; j++)
		{
			map[i][j] = line[j] - '0';
		}
	}

	int houseList[625];
	int complexCount = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1 && !visited[i][j]) 
			{
				int houses = DFS(map, visited, i, j, N);
				houseList[complexCount++] = houses;
			}
		}
	}

	CustomQuickSort(houseList, 0, complexCount - 1);

	cout << complexCount << '\n';
	for (int i = 0; i < complexCount; i++)
	{
		cout << houseList[i] << '\n';
	}

	return 0;
}