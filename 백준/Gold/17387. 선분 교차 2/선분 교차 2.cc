#include <iostream>
#include <algorithm>

using namespace std;

struct Point
{
	long long x, y;
};

// a,b로 만든 edge를 기준으로 c의 방향을 판정하는 CCW
int CCW(Point a, Point b, Point c)
{
	// CCW: AB벡터와 AC벡터의 외적 값
	long long t = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	if (t > 0)
		return 1;
	if (t < 0)
		return -1;
	return 0;
}

bool IsOverlap(Point a, Point b, Point c, Point d) 
{
	// x축 범위 겹침
	if (max(a.x, b.x) < min(c.x, d.x)) 
		return false;
	if (max(c.x, d.x) < min(a.x, b.x)) 
		return false;

	// y축 범위 겹침
	if (max(a.y, b.y) < min(c.y, d.y)) 
		return false;
	if (max(c.y, d.y) < min(a.y, b.y)) 
		return false;
		
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Point A, B, C, D;
	cin >> A.x >> A.y >> B.x >> B.y;
	cin >> C.x >> C.y >> D.x >> D.y;

	// ab_c에서 ab: 기준이 되는 edge, c: 방향을 판정할 vertex
	int ab_c = CCW(A, B, C);
	int ab_d = CCW(A, B, D);
	int cd_a = CCW(C, D, A);
	int cd_b = CCW(C, D, B);

	// 일반적인 교차
	// < 0: 다른 방향, > 0: 같은 방향, = 0: 일직선(colinear)
	if (ab_c * ab_d <= 0 && cd_a * cd_b <= 0)
	{
		// colinear인 경우 별도 범위 체크
		if (ab_c == 0 && ab_d == 0 && cd_a == 0 && cd_b == 0)
		{
			if (IsOverlap(A, B, C, D))
				cout << 1;	// 교차
			else
				cout << 0;
		}
		else
			cout << 1;	// 교차
	}
	else
		cout << 0;

	return 0;
}