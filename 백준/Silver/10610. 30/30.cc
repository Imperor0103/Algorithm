#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s;
	cin >> s;

	// 0~9 숫자의 개수를 저장한 배열 
	int digit[10] = { 0 };

	long long sum = 0;

	for (char c : s) 
	{
		int d = c - '0';
		digit[d]++;
		sum += d;
	}

	if (digit[0] == 0 || sum % 3 != 0) 
	{
		cout << -1;
		return 0;
	}

	// 가장 큰 수 출력
	for (int i = 9; i >= 0; i--) 
	{
		while (digit[i]--)
		{
			cout << i;
		}
	}
	return 0;
}