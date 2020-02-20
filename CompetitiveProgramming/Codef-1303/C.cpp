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
//vector<int> g[26];
//string res;
//void dfs(int u, int p = -1)
//{
//	res.PB('a'+u);
//	FOR(i, 0, g[u].size())
//	{
//		int v = g[u][i];
//		if (v == p)
//			continue;
//		dfs(v, u);
//	}
//}
//
//int used[26][26];
//void solve()
//{
//	string s;
//	cin >> s;
//	if (s.size() == 1)
//	{
//		cout << "YES" << endl;
//		FOR(i, 0, 26)
//		{
//			cout << char('a' + i);
//		}
//		cout << endl;
//		return;
//	}
//	FILL(used, 0);
//	FOR(i, 0, 26)
//	{
//		g[i].clear();
//	}
//	FOR(i, 0, SZ(s) - 1)
//	{
//		int u = s[i] - 'a';
//		int v = s[i+1] - 'a';
//		used[u][v] = used[v][u] = 1;
//	}
//	FOR(i, 0, 26)
//	{
//		FOR(j, 0, 26)
//		{
//			if (used[i][j])
//				g[i].PB(j);
//		}
//	}
//	vector<int> foo;
//	FOR(i, 0, 26)
//	{
//		if (g[i].size() == 1)
//			foo.PB(i);;
//		if (g[i].size() > 2)
//		{
//			cout << "NO" << endl;
//			return;
//		}
//	}
//	if (foo.size() > 2 || foo.size() == 0)
//	{
//		cout << "NO" << endl;
//		return;
//	}
//	int st = foo.back();
//	res = "";
//	dfs(st);
//
//	FOR(i, 0, 26)
//	{
//		if (g[i].size() == 0)
//		{
//			res.PB('a' + i);
//		}
//	}
//	cout << "YES" << endl;
//	cout << res << endl;
//}
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		solve();
//	}
//	return 0;
//}
//
