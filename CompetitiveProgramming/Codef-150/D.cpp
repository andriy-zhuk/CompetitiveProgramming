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
//#include <queue>
//
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
//int n, m,l,s;
//vector<pair<PII, int> > rib;
//vector<PII> g[100005];
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	cin >> n >> m >> s;
//	s--;
//	FOR(i, 0, m)
//	{
//		int x, y, z;
//		cin >> x >> y >> z;
//		x--, y--;
//		g[x].PB(MP(y, z));
//		g[y].PB(MP(x, z));
//		rib.PB(MP(MP(x, y), z));
//	}
//	int ans = 0;
//
//	vector<int> d(n, INF);
//	d[s] = 0;
//	priority_queue < pair<int, int> > q;
//	q.push(make_pair(0, s));
//	while (!q.empty()) {
//		int v = q.top().second, cur_d = -q.top().first;
//		q.pop();
//		if (cur_d > d[v])  continue;
//
//		for (size_t j = 0; j < g[v].size(); ++j) {
//			int to = g[v][j].first,
//				len = g[v][j].second;
//			if (d[v] + len < d[to]) {
//				d[to] = d[v] + len;
//				q.push(make_pair(-d[to], to));
//			}
//		}
//	}
//	cin >> l;
//	FOR(i, 0, n)
//	{
//		if (d[i] == l)
//			ans++;
//	}
//
//	FOR(i, 0, m)
//	{
//		int x, y, z;
//		x = rib[i].first.first, y = rib[i].first.second, z = rib[i].second;
//
//		int a = -1;
//		int b = -1;
//		if (d[x] < l && d[x] + z > l)
//		{
//			a = l-d[x];
//		}
//		if (d[y] < l && d[y] + z > l)
//		{
//			b = l-d[y];
//		}
//		
//		if (a != -1 && z - a + d[y] > a + d[x])
//			ans++;
//		if (b != -1 && z - b + d[x] >= b + d[y])
//			ans++;
//	}
//	cout << ans << endl;
//
//	return 0;
//}
