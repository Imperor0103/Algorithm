#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	double D, H, W;
	cin >> D >> H >> W;

	double ratio = sqrt(H * H + W * W);
	int height = H * D / ratio;
	int width = W * D / ratio;

	cout << height << " " << width << endl;
	return 0;
}