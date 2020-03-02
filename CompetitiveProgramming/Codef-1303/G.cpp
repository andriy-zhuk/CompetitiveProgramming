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
//typedef vector<int> VI;
//
//const int INF = 1000 * 1000 * 1000;
//const LL LINF = 1LL * INF * INF;
//const int MAX = 150005;
//const long double PI = acos(-1.);
//const double EPS = 1e-6;
//const LL MOD = INF + 7;
//vector<int> g[MAX];
//bool Q;
//struct Line {
//	mutable LL k, m, p;
//	bool operator<(const Line& o) const 
//	{
//		return Q ? p < o.p : k < o.k;
//	}
//};
//
//struct CHO : multiset<Line> {
//	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
//	const LL inf = LINF;
//	LL div(LL a, LL b) 
//	{
//		return a / b - ((a ^ b) < 0 && a % b);
//	}
//	bool isect(iterator x, iterator y) 
//	{
//		if (y == end()) { 
//			x->p = inf; return false; 
//		}
//		if (x->k == y->k)
//			x->p = x->m > y->m ? inf : -inf;
//		else 
//			x->p = div(y->m - x->m, x->k - y->k);
//		return x->p >= y->p;
//	}
//	void add(LL k, LL m) {
//		auto z = insert({ k, m, 0 }), y = z++, x = y;
//		while (isect(y, z)) z = erase(z);
//		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
//		while ((y = x) != begin() && (--x)->p >= y->p)
//			isect(x, erase(y));
//	}
//	LL query(LL x) 
//	{
//		if (empty())
//			return 0;
//		Q = 1;
//		auto l = *lower_bound({ 0,0,x }); 
//		Q = 0;
//		return l.k * x + l.m;
//	}
//};
//LL a[MAX];
//LL ans = 0;
//int n;
//namespace CENTROID
//{
//	int SZ[MAX];
//	int used[MAX];
//	int U[MAX];
//	vector<pair<LL, LL> > desc;
//	vector<pair<LL, LL> > inc;
//	CHO forinc, fordec;
//	void dfs(int u, int p, LL d, LL suf, LL pref1, LL pref2)
//	{
//		desc.PB(MP(pref1 + pref2 + a[u], d));
//		inc.PB(MP(a[u] * (d + 1) + suf, pref1 + a[u]));
//		FOR(i, 0, SZ(g[u]))
//		{
//			int v = g[u][i];
//			if (v == p || U[v])
//				continue;
//			dfs(v, u, d + 1, suf + a[u] * (d + 1), pref1+a[u], pref2+pref1+a[u]);
//		}
//	}
//
//	void dfsSZ(int u, int p = -1)
//	{
//		SZ[u] = 1;
//		FOR(i, 0, SZ(g[u]))
//		{
//			int  v = g[u][i];
//			if (v == p || U[v])
//				continue;
//			dfsSZ(v, u);
//			SZ[u] += SZ[v];
//		}
//	}
//
//	void build(int x) {
//		dfsSZ(x);
//		int szAll = SZ[x];
//		int p = x;
//		while (true) {
//			int w = -1;
//			FOR(i, 0, SZ(g[x]))
//			{
//				int to = g[x][i];
//				if (to == p || U[to])
//					continue;
//				if (SZ[to] * 2 > szAll)
//				{
//					w = to;
//					break;
//				}
//			}
//			if (w == -1)
//				break;
//			p = x;
//			x = w;
//		}
//		U[x] = true;  
//		int del = 1;
//
//		FOR(ii, 0, 2)
//		{
//			forinc.clear();
//			fordec.clear();
//			del *= -1;
//			FOR(i,0,SZ(g[x]))
//			{
//				int u = g[x][i];
//				if (del == -1)
//				{
//					u = g[x][SZ(g[x]) - 1 - i];
//				}
//				if (U[u])
//					continue;
//				desc.clear(), inc.clear();
//				dfs(u, x, 1, a[x], 0, 0);
//				FOR(i, 0, SZ(desc))
//				{
//					ans = max(ans, desc[i].first + fordec.query(desc[i].second));
//				}
//				FOR(i, 0, SZ(inc))
//				{
//					ans = max(ans, inc[i].first + forinc.query(inc[i].second + a[x]));
//				}
//				FOR(i, 0, SZ(desc))
//				{
//					forinc.add(desc[i].second, desc[i].first);
//				}
//				FOR(i, 0, SZ(inc))
//				{
//					fordec.add(inc[i].second, inc[i].first);
//				}
//			}
//			ans = max(ans, a[x] + forinc.query(a[x]));
//		}
//		
//
//		FOR(i, 0, SZ(g[x]))
//		{
//			int to = g[x][i];
//			if (!U[to]) build(to);
//		}
//	}
//}
//
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n;
//	FOR(i, 0, n-1)
//	{
//		int x, y;
//		cin >> x >> y;
//		x--, y--;
//		g[x].PB(y);
//		g[y].PB(x);
//	}
//	FOR(i, 0, n)
//	{
//		cin >> a[i];
//	}
//	CENTROID::build(0);
//	cout << ans << endl;
//	return 0;
//}
