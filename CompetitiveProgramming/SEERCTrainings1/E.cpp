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
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//
//using namespace __gnu_pbds;
//using namespace std;
//
//typedef tree< pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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
//ordered_set foo[100005]; // contains pair<cnt, color>
//set<PII> goo[100005]; // contains pair<color, cnt>
//vector<int> g[100005];
//
//void add(set<PII>& x1, ordered_set& x2, PII toAdd)
//{
//	if (x1.lower_bound(MP(toAdd.first, 0)) != x1.end())
//	{
//		PII curva = *x1.lower_bound(MP(toAdd.first, 0));
//		if (curva.first == toAdd.first)
//		{
//			toAdd.second += curva.second;
//			x1.erase(curva);
//			x2.erase(MP(curva.second, curva.first));
//		}
//	}
//	x1.insert(toAdd);
//	x2.insert(MP(toAdd.second, toAdd.first));
//}
//
//// x1 = MP(color, cnt)
//void merge(set<PII>& x1, ordered_set& x2, set<PII>& y1, ordered_set& y2) // ys-th set push to xs-th set
//{
//	for (auto& iter : y1)
//	{
//		add(x1, x2, iter);
//	}
//	y1.clear();
//	y2.clear();
//}
//
//int marked[100005];
//int elon = 1;
//int c[100005];
//
//vector<PII> zap[100005];
//int ans[100005];
//
//void dfs(int u, int p = -1)
//{
//	if (SZ(g[u]) == 1 && p != -1)
//	{
//		foo[elon].insert(MP(1, c[u]));
//		goo[elon].insert(MP(c[u], 1));
//		marked[u] = elon++;
//	}
//	else
//	{
//		PII best = MP(-1, -1);
//		FOR(i, 0, SZ(g[u]))
//		{
//			int v = g[u][i];
//			if (p == v)
//				continue;
//			dfs(v, u);
//			best = max(best, MP(SZ(goo[marked[v]]), marked[v]));
//		}
//		marked[u] = best.second;
//		FOR(i, 0, SZ(g[u]))
//		{
//			int v = g[u][i];
//			if (p == v)
//				continue;
//			if (marked[v] == marked[u])
//				continue;
//			merge(goo[marked[u]], foo[marked[u]], goo[marked[v]], foo[marked[v]]);
//		}
//		add(goo[marked[u]], foo[marked[u]], MP(c[u], 1));
//	}
//
//	FOR(i, 0, SZ(zap[u]))
//	{
//		int k = zap[u][i].first;
//		int cur = foo[marked[u]].order_of_key(MP(k, 0));
//		cur = SZ(goo[marked[u]]) - cur;
//		ans[zap[u][i].second] = cur;
//	}
//
//}
//
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	int n, m;
//	cin >> n >> m;
//	FOR(i, 0, n)
//	{
//		cin >> c[i];
//	}
//	FOR(i, 0, n - 1)
//	{
//		int x, y;
//		cin >> x >> y;
//		x--, y--;
//		g[x].PB(y);
//		g[y].PB(x);
//	}
//	FOR(i, 0, m)
//	{
//		int v, k;
//		cin >> v >> k;
//		v--;
//		zap[v].PB(MP(k, i));
//	}
//	dfs(0);
//	FOR(i, 0, m)
//	{
//		cout << ans[i] << endl;
//	}
//	return 0;
//}
//
