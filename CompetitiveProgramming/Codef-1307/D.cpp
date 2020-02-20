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
//typedef unsigned long long ULL;
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
//const LL MOD = INF + 7;
//int n, m, k;
//int a[200005];
//
//vector<int> g[200005];
//int d[2][200005];
//int q[400005];
//
//
//void bfs(int s)
//{
//	int qh = 0;
//	int qt = 0;
//
//	if (s == 1)
//	{
//		d[s][n - 1] = 0;
//		q[qt++] = n - 1;
//	}
//	else
//	{
//		d[s][s] = 0;
//		q[qt++] = 0;
//	}
//	while (qt != qh)
//	{
//		int u = q[qh++];
//
//		FOR(i, 0, g[u].size())
//		{
//			int v = g[u][i];
//			if (d[s][v] != -1)
//				continue;
//			d[s][v] = d[s][u] + 1;
//			q[qt++] = v;
//		}
//	}
//}
//
//
//
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n >> m >> k;
//	FOR(i, 0, k)
//	{
//		cin >> a[i];
//		a[i]--;
//	}
//	FOR(i, 0, m)
//	{
//		int x, y;
//		cin >> x >> y;
//		x--, y--;
//		g[x].PB(y);
//		g[y].PB(x);
//	}
//	FILL(d, -1);
//
//	bfs(0);
//	bfs(1);
//
//
//	vector<PII> foo1;
//	set<PII> foo2;
//	int best = d[0][n - 1];
//	FOR(i, 0, k)
//	{
//		int d1 = d[0][a[i]];
//		int d2 = d[1][a[i]];
//		foo1.PB(MP(d1, a[i]));
//		foo2.insert(MP(d2, a[i]));
//	}
//
//
//	sort(ALL(foo1));
//	int best2 = 0;
//	FOR(i, 0, foo1.size()-1)
//	{
//		foo2.erase(MP(d[1][foo1[i].second], foo1[i].second));
//		int val = foo1[i].first + (--foo2.end())->first + 1;
//		best2 = max(best2, min(val, best));
//	}
//	
//	
//	if (best2 == 0)
//		best2 = best;
//	cout << best2 << endl;
//
//
//
//
//
//
//
//
//
//
//
//	return 0;
//}
//
