#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
	int N, W, H;
	cin >> N >> W >> H;

	double diagonal = sqrt(W * W + H * H);

	for (int i = 0; i < N; i++)
	{
		int length;
		cin >> length;

		if (length <= diagonal)
			cout << "DA\n";
		else
			cout << "NE\n";
	}

	return 0;
}
