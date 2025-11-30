#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s;
	cin >> s;

	int count0 = 0;
	int count1 = 0;

	if (s[0] == '0') 
		count0++;
	else 
		count1++;


	for (int i = 1; i < s.size(); i++) 
	{
		if (s[i] != s[i - 1]) 
		{   
			if (s[i] == '0') 
				count0++;
			else 
				count1++;
		}
	}
	cout << (count0 < count1 ? count0 : count1);

	return 0;
}