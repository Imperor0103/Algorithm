#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	double d1, d2;
	cin >> d1 >> d2;

	double result = (2 * d1) + (2 * M_PI * d2);
	cout << fixed;
	cout.precision(6);
	cout << result << '\n';

	return 0;
}