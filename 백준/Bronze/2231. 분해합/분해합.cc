#include <iostream>

using namespace std;

int DigitSum(int x) 
{
	int sum = 0;
	while (x > 0) 
	{
		sum += x % 10;
		x /= 10;
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	int answer = 0;

	int start = N - 9 * 7; // N의 최대 자릿수는 7자리(1,000,000 이하)
	if (start < 1) 
		start = 1;

	for (int i = start; i < N; i++) 
	{
		if (i + DigitSum(i) == N) 
		{
			answer = i;
			break;  
		}
	}

	cout << answer;
	return 0;
}