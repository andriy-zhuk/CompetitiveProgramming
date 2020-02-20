//#pragma GCC optimize("Ofast")
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <vector>
//#include <set>
//#include <map>
//#include <algorithm>
//#include <iomanip>
//#include <string>
//#include <deque>
//#include <stack>
//#include <cmath>
//#include <iterator>
//#include <string.h>
//
//using namespace std;
//#ifndef DEBUGING
//ostream cnull(NULL);
//#define cerr cnull
//#endif // !DEBUGING
//
//#define PB push_back
//#define MP make_pair
//#define f first
//#define s second
//#define FOR(i,a,b) for (int i = a; i < b; ++i)
//#define RFOR(i, b, a) for (int i = b-1; i>=a; --i)
//#define FILL(a, b) memset(a, b, sizeof a)
//#define ALL(a) a.begin(), a.end()
//#define SZ(a) (int)a.size()
//
//typedef long long LL;
//typedef pair<int, int> PII;
//typedef vector<LL> VI;
//typedef pair<LL, LL> PLL;
//
//const int INF = 1000 * 1000 * 1000;
//const LL LINF = 1LL * INF * INF;
//const int MAX = 100010;
//const long double PI = acos(-1.);
//const double EPS = 1e-6;
//const LL mod = INF + 7;
//
//int n;
//int p[101];
//int a[101];
//int dpT[101][101][101][3];
//
//int dp(int p, int x, int y, int prev) // %0, %1, 0/1
//{
//	if (p == n)
//	{
//		return 0;
//	}
//	if (dpT[p][x][y][prev] != -1)
//	{
//		return dpT[p][x][y][prev];
//	}
//	int best = INF;
//	if (a[p] != -1)
//	{
//		return dpT[p][x][y][prev] = dp(p+1, x, y, a[p]) + (a[p] != prev);
//	}
//	if (x)
//	{
//		best = min(best, dp(p + 1, x-1, y, 0) + (0 != prev));
//	}
//	if (y)
//	{
//		best = min(best, dp(p + 1, x, y-1, 1) + (1 != prev));
//	}
//	return dpT[p][x][y][prev] = best;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	cin >> n;
//	FILL(a, -1);
//	FILL(dpT, -1);
//	FOR(i, 0, n)
//	{
//		int x;
//		cin >> x;
//		if (x != 0)
//		{
//			p[x] = 1;
//			a[i] = x % 2;
//		}
//	}
//	int x = 0, y = 0;
//	FOR(i, 1, n + 1)
//	{
//		if (p[i] == 0)
//		{
//			if (i % 2)
//				y++;
//			else
//				x++;
//		}
//	}
//
//	cout << dp(0, x, y, 2) - 1 << endl;
//
//
//
//
//	return 0;
//}
//
