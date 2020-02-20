	//#pragma GCC optimize("Ofast")
	//#define _CRT_SECURE_NO_WARNINGS

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

	//using namespace std;
	//#ifndef DEBUGING
	//ostream cnull(NULL);
	//#define cerr cnull
	//#endif // !DEBUGING

	//#define PB push_back
	//#define MP make_pair
	//#define f first
	//#define s second
	//#define FOR(i,a,b) for (int i = a; i < b; ++i)
	//#define RFOR(i, b, a) for (int i = b-1; i>=a; --i)
	//#define FILL(a, b) memset(a, b, sizeof a)
	//#define ALL(a) a.begin(), a.end()
	//#define SZ(a) (int)a.size()

	//typedef long long LL;
	//typedef pair<int, int> PII;
	//typedef vector<LL> VI;
	//typedef pair<LL, LL> PLL;

	//const int INF = 1000 * 1000 * 1000;
	//const LL LINF = 1LL * INF * INF;
	//const int MAX = 100010;
	//const long double PI = acos(-1.);
	//const double EPS = 1e-6;
	//const LL mod = INF + 7;
	//int n;


	//LL x[100005];
	//map<LL, LL> val[100005];
	//vector<int> g[100005];
	//map<LL, LL> tmp;
	//LL answer = 0;

	//LL gcd(LL a, LL b)
	//{
	//	if (!a)
	//		return b;
	//	return gcd(b % a, a);
	//}
	//void dfs(int u, int p = -1)
	//{
	//	tmp.clear();
	//	for (auto& iter : val[u])
	//	{
	//		LL cur = gcd(iter.first, x[u]);
	//		answer = (answer + (cur * iter.second)%mod)%mod;
	//		tmp[cur] += iter.second;
	//	}
	//	tmp[x[u]] += 1;
	//	answer = (answer + x[u]) % mod;
	//	FOR(i, 0, SZ(g[u]))
	//	{
	//		int v = g[u][i];
	//		if (v == p)
	//			continue;
	//		val[v] = tmp;
	//	}
	//	FOR(i, 0, SZ(g[u]))
	//	{
	//		int v = g[u][i];
	//		if (v == p)
	//			continue;
	//		dfs(v, u);
	//	}
	//}


	//int main()
	//{
	//	ios_base::sync_with_stdio(0);
	//	//freopen("input.txt", "r", stdin);
	//	//freopen("output.txt", "w", stdout);
	//	cin >> n;
	//	FOR(i, 0, n)
	//	{
	//		cin >> x[i];
	//	}
	//	FOR(i, 0, n - 1)
	//	{
	//		int x, y;
	//		cin >> x >> y;
	//		x--, y--;
	//		g[x].PB(y);
	//		g[y].PB(x);
	//	}
	//	dfs(0);
	//	cout << answer << endl;



	//	return 0;
	//}