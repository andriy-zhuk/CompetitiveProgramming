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
//int solve(int c, int m)
//{
//	if (c == 0 || m == 0)
//		return 0;
//	if (c > m)
//		swap(c, m);
//	if (c * 2 <= m)
//	{
//		return c;
//	}
//	if (c == m)
//		return (c*2 / 3);
//	return (solve(c - (m - c), c - (m - c)) + (m - c));
//}
//int solve(int c, int m, int x)
//{
//	int mn = min(c, min(m, x));
//	if (c == mn)
//	{
//		return c;
//	}
//	if (m == mn)
//		return m;
//	return solve(c - x, m - x) + x;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int c, m, x;
//		cin >> c >> m >> x;
//		cout << solve(c, m, x) << endl;
//	}
//	return 0;
//}