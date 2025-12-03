#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	double A;
	cin >> A;
	double result = 4 * sqrt(A);

	cout.precision(10);
	cout << fixed << result << '\n';
	return 0;
}