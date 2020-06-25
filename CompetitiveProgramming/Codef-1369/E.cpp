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
//using namespace std;
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
//const int MAX = 100010;
//const long double PI = acos(-1.);
//const double EPS = 1e-6;
//const LL MOD = INF + 7;
//int n, m;
//int w[200005];
//
//set<pair<int, int> > g[200005];
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n >> m;
//	FOR(i, 0, n)
//	{
//		cin >> w[i];
//	}
//	FOR(i, 0, m)
//	{
//		int x, y;
//		cin >> x >> y;
//		x--, y--;
//		g[x].insert(MP(y, i + 1));
//		g[y].insert(MP(x, i + 1));
//	}
//	LL sumw = 0;
//	LL sumd = 0;
//	FOR(i, 0, n)
//	{
//		sumw += w[i];
//		sumd += g[i].size();
//	}
//
//	set<pair<int, int> > foo;
//	FOR(i, 0, n)
//	{
//		foo.insert(MP((int)g[i].size() - w[i], i));
//	}
//	vector<pair<PII, int> > ans;
//	while (foo.size())
//	{
//		PII cur = *foo.begin();
//		if (cur.first > 0)
//		{
//			cout << "DEAD" << endl;
//			return 0;
//		}
//		int u = cur.second;
//		foo.erase(foo.begin());
//		for (auto& iter: g[u])
//		{
//			int v = iter.first;
//			int id = iter.second;
//			ans.PB(MP(MP(u,v), id));
//			foo.erase(MP(SZ(g[v]) - w[v], v));
//			g[v].erase(MP(u, id));
//			
//			foo.insert(MP(SZ(g[v]) - w[v], v));
//		}
//		g[u].clear();
//	}
//	reverse(ALL(ans));
//	FOR(i, 0, ans.size())
//	{
//		int u = ans[i].first.first;
//		int v = ans[i].first.second;
//		if (w[u] <= 0 && w[v] <= 0)
//		{
//			cout << "DEAD" << endl;
//			return 0;
//		}
//		w[u]--;
//		w[v]--;
//	}
//	cout << "ALIVE" << endl;
//	FOR(i, 0, ans.size())
//	{
//		cout << ans[i].second << ' ';
//	}
//	cout << endl;
//
//	return 0;
//}
//
