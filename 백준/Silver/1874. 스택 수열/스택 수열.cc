#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	int stack[100000];	// 숫자
	int top = -1; 
	int current = 1;	// 다음 push할 숫자
	char result[200000];	// +, - 저장
	int rIdx = 0;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		while (current <= x)
		{
			stack[++top] = current;
			current++;
			result[rIdx++] = '+';
		}

		if (top >= 0 && stack[top] == x)
		{
			top--;
			result[rIdx++] = '-';
		}
		else
		{
			cout << "NO" << '\n';
			return 0;
		}
	}

	for (int i = 0; i < rIdx; i++)
		cout << result[i] << '\n';

	return 0;
}