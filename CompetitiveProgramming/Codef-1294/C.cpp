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
//void solve()
//{
//	int x;
//	cin >> x;
//	int oldX = x;
//
//	vector<PII> foo;
//
//	for (LL i = 2; i * i <= x; ++i)
//	{
//		if (x % i == 0)
//		{
//			int cur = 0;
//			while (x % i == 0)
//				x /= i, cur++;
//			foo.PB(MP(i, cur));
//		}
//	}
//	if (x != 1)
//	{
//		foo.PB(MP(x, 1));
//	}
//	if (foo.size() == 1)
//	{
//		if (foo[0].second >= 6)
//		{
//			cout << "YES" << endl;
//			cout << foo[0].f << ' ' << foo[0].f * foo[0].f << ' ' << oldX / foo[0].first / foo[0].f / foo[0].f << endl;
//			return;
//		}
//		cout << "NO" << endl;
//		return;
//	}
//	if (foo.size() >= 3)
//	{
//		cout << "YES" << endl;
//		int x = 1;
//		int y = 1;
//		FOR(i, 0, foo[0].second)
//			x *= foo[0].first;
//		FOR(i, 0, foo[1].second)
//			y *= foo[1].first;
//		cout << x << ' ' << y << ' ' << oldX / x / y << endl;
//		return;
//	}
//	if (foo[0].second + foo[1].second >= 4)
//	{
//		int x = foo[0].first;
//		int y = foo[1].first;
//		int z = oldX / x / y;
//		cout << "YES" << endl;
//		cout << x << ' ' << y << ' ' << z << endl;
//		return;
//	}
//	cout << "NO" << endl;
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
//		solve();
//	}
//	return 0;
//}
//
