#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	if (N == 0) 
	{
		cout << 0;
		return 0;
	}
	if (N == 1) 
	{
		cout << 1;
		return 0;
	}

	int prev2 = 0;
	int prev1 = 1;
	int cur = 0;

	for (int i = 2; i <= N; i++) 
	{
		cur = prev1 + prev2;
		prev2 = prev1;
		prev1 = cur;
	}

	cout << cur;
	return 0;
}