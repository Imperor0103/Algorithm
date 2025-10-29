#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--) 
	{
		int V, E;
		cin >> V >> E;
		cout << 2 - V + E << '\n';
	}
	return 0;
}
