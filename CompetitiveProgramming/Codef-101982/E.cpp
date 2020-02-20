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
//
//namespace DINIC
//{
//	const int MAXN = 2000;
//	struct edge {
//		int a, b, cap, flow;
//	};
//
//	int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
//	vector<edge> e;
//	vector<int> g[MAXN];
//
//	void add_edge(int a, int b, int cap) {
//		edge e1 = { a, b, cap, 0 };
//		edge e2 = { b, a, 0, 0 };
//		g[a].push_back((int)e.size());
//		e.push_back(e1);
//		g[b].push_back((int)e.size());
//		e.push_back(e2);
//	}
//
//	bool bfs() {
//		int qh = 0, qt = 0;
//		q[qt++] = s;
//		memset(d, -1, n * sizeof d[0]);
//		d[s] = 0;
//		while (qh < qt && d[t] == -1) {
//			int v = q[qh++];
//			for (size_t i = 0; i < g[v].size(); ++i) {
//				int id = g[v][i],
//					to = e[id].b;
//				if (d[to] == -1 && e[id].flow < e[id].cap) {
//					q[qt++] = to;
//					d[to] = d[v] + 1;
//				}
//			}
//		}
//		return d[t] != -1;
//	}
//
//	int dfs(int v, int flow) {
//		if (!flow)  return 0;
//		if (v == t)  return flow;
//		for (; ptr[v] < (int)g[v].size(); ++ptr[v]) {
//			int id = g[v][ptr[v]],
//				to = e[id].b;
//			if (d[to] != d[v] + 1)  continue;
//			int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
//			if (pushed) {
//				e[id].flow += pushed;
//				e[id ^ 1].flow -= pushed;
//				return pushed;
//			}
//		}
//		return 0;
//	}
//
//	int dinic() {
//		int flow = 0;
//		for (;;) {
//			if (!bfs())  break;
//			memset(ptr, 0, n * sizeof ptr[0]);
//			while (int pushed = dfs(s, INF))
//				flow += pushed;
//		}
//		return flow;
//	}
//
//
//}
//
//int n, m, c;
//int dx[] = { 0, 1, 0, -1 };
//int dy[] = { 1, 0, -1, 0 };
//string a[31];
//int cost[30];
//bool ok(int x, int y)
//{
//	return min(x, y) >= 0 && x < n && y < m;
//}
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	cin >> n >> m >> c;
//	swap(n, m);
//	FOR(i, 0, n)
//	{
//		cin >> a[i];
//	}
//	FOR(i, 0, c)
//	{
//		cin >> cost[i];
//	}
//	DINIC::n = 2 + n * m * 2;
//	DINIC::s = 0;
//	DINIC::t = 1;
//	FOR(x, 0, n)
//	{
//		FOR(y, 0, m)
//		{
//			if (a[x][y] == 'B')
//			{
//				DINIC::add_edge(DINIC::s, 2+(x * m + y) * 2, INF);
//			}
//			if (x == 0 || y == 0 || x == n - 1 || y == m - 1)
//			{
//				DINIC::add_edge(2+(x * m + y) * 2+1, DINIC::t, INF);
//			}
//		}
//	}
//	FOR(x, 0, n)
//	{
//		FOR(y, 0, m)
//		{
//			int val = INF;
//			if (a[x][y] >= 'a' && a[x][y] <= 'z')
//			{
//				val = cost[a[x][y] - 'a'];
//			}
//			DINIC::add_edge(2 + (x * m + y) * 2, 2 + (x * m + y) * 2 + 1, val);
//			FOR(k, 0, 4)
//			{
//				int nx = x + dx[k];
//				int ny = y + dy[k];
//				if (ok(nx, ny))
//				{
//					DINIC::add_edge(2 + (x * m + y) * 2 + 1, 2 + (nx * m + ny) * 2, INF);
//				}
//			}
//		}
//	}
//	int x = DINIC::dinic();
//	if (x == INF)
//		x = -1;
//	cout << x << endl;
//
//
//
//
//	return 0;
//}
//
