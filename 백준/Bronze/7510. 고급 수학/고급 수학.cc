#include <iostream>
#include <algorithm>

using namespace std;

bool IsRightTriangle(int a, int b, int c) 
{
	int arr[3] = { a, b, c };
	sort(arr, arr + 3);
	return arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) 
	{
		int a, b, c;
		cin >> a >> b >> c;

		cout << "Scenario #" << i << ":\n";
		if (IsRightTriangle(a, b, c)) 
		{
			cout << "yes\n\n";
		}
		else 
		{
			cout << "no\n\n";
		}
	}
	return 0;
}