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
//int n, m;
//vector<int> g[100005];
//int sum[100005];
//set<pair<int, int> > foo;
//vector<pair<int, PII> > ans;
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n >> m;
//	FOR(i, 0, m)
//	{
//		int x, y, z;
//		cin >> x >> y >> z;
//		x--, y--;
//
//		sum[x] += z;
//		sum[y] -= z;
//
//	}
//
//	FOR(i, 0, n)
//	{
//		if (sum[i])
//			foo.insert(MP(sum[i], i));
//	}
//
//	while (foo.size())
//	{
//		PII a = *foo.begin();
//		PII b = *(--foo.end());
//		foo.erase(foo.begin());
//		foo.erase((--foo.end()));
//
//		int c = min(-a.first, b.first);
//
//		a.first = -(-a.first - c);
//		b.first = b.first - c;
//
//		ans.PB(MP(a.second, MP(b.second, c)));
//		if (a.first)
//		{
//			foo.insert(a);
//		}
//		if (b.first)
//		{
//			foo.insert(b);
//		}
//	}
//	cout << ans.size() << endl;
//	FOR(i, 0, ans.size())
//	{
//		cout << ans[i].first + 1 << ' ' << ans[i].second.first + 1 << ' ' << ans[i].second.second << endl;
//	}
//
//
//
//
//	return 0;
//}
