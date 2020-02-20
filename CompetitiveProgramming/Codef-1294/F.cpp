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
//int n;
//vector<int> g[200005];
//int used[200005];
//int nxt[200005];
//void dfs(int u, int d)
//{
//	used[u] = d;
//	FOR(i, 0, SZ(g[u]))
//	{
//		int v = g[u][i];
//		if (used[v] == 0)
//		{
//			nxt[v] = u;
//			dfs(v, d + 1);
//		}
//	}
//}
//
//
//vector<int> get()
//{
//	FILL(used, 0);
//	dfs(0, 1);
//	PII best = MP(1, 0);
//
//	FOR(i, 0, n)
//	{
//		best = max(best, MP(used[i], i));
//	}
//	int st = best.second;
//	FILL(used, 0);
//	best = MP(1, st);
//	dfs(st, 1);
//	FOR(i, 0, n)
//	{
//		best = max(best, MP(used[i], i));
//	}
//	int fin = best.second;
//
//	vector<int> ans;
//	while (fin != st)
//	{
//		ans.PB(fin);
//		fin = nxt[fin];
//	}
//	ans.PB(st);
//	
//	return ans;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n;
//	FOR(i, 0, n - 1)
//	{
//		int x, y;
//		cin >> x >> y;
//		x--; y--;
//		g[x].PB(y);
//		g[y].PB(x);
//	}
//
//	vector<int> chain = get();
//
//	FILL(used, 0);
//
//	FOR(i, 0, chain.size())
//	{
//		int u = chain[i];
//		used[u] = 1;
//	}
//	FOR(i, 0, chain.size())
//	{
//		int u = chain[i];
//		used[u] = 1;
//		FOR(j, 0, g[u].size())
//		{
//			int v = g[u][j];
//			if (!used[v])
//				dfs(v, 2);
//		}
//	}
//
//	PII mx = MP(0, 0);
//	FOR(i, 0, n)
//	{
//		mx = max(mx, MP(used[i],i));
//	}
//	VI ans;
//	if (mx.first == 1)
//	{
//		ans.PB(chain[0]);
//		ans.PB(chain[1]);
//		ans.PB(chain.back());
//	}
//	else
//	{
//		ans.PB(chain[0]);
//		ans.PB(chain.back());
//		ans.PB(mx.second);
//	}
//
//	cout << mx.first - 1 + (int)chain.size() - 1 << endl;
//	FOR(i, 0, 3)
//	{
//		cout << ans[i] + 1 << ' ';
//	}
//	cout << endl;
//	return 0;
//}
//
