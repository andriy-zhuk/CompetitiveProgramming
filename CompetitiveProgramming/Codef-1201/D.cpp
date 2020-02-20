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
//int n, m, q, k;
//PII a[200005];
//int b[200005];
//
//vector<PII> g[400005];
//vector<int> matr[200005];
//
//int get(int x, int y) // x on bottom level; y on top
//{
//	int k = upper_bound(b, b + q, x) - b;
//	k = max(k, 0);
//	k = min(k, q - 1);
//	int l = k - 1;
//	l = max(l, 0);
//	l = min(l, q - 1);
//
//	int r1 = abs(b[k] - x) + abs(b[k] - y);
//	int r2 = abs(b[l] - x) + abs(b[l] - y);
//
//	return min(r1, r2);
//}
//
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	cin >> n >> m >> k >> q;
//	matr[0].PB(0);
//	FOR(i, 0, k)
//	{
//		cin >> a[i].first >> a[i].second;
//		a[i].first--;
//		a[i].second--;
//		matr[a[i].first].PB(a[i].second);
//	}
//	FOR(i, 0, q)
//	{
//		cin >> b[i];
//		b[i]--;
//	}
//	sort(b, b + q);
//	LL res = 0;
//
//	int j = 0;
//	FOR(i, 0, n)
//	{
//		sort(ALL(matr[i]));
//		if (matr[i].size())
//		{
//			res += matr[i].back() - matr[i][0];
//			j = i;
//		}
//	}
//
//	res += j;
//	j = 0;
//	vector<vector<int> > foo;
//	FOR(i, 0, n)
//	{
//		if (matr[i].size())
//		{
//			foo.PB(vector<int>(2, 0));
//			foo[foo.size()-1][0] = matr[i][0];
//			foo[foo.size() - 1][1] = matr[i].back();
//		}
//	}
//	FOR(i, 0, foo.size() - 1)
//	{
//		j += 2;
//		g[j - 2].PB(MP(j, get(foo[i][0], foo[i + 1][1])));
//		g[j - 2].PB(MP(j + 1, get(foo[i][0], foo[i + 1][0])));
//
//		g[j - 1].PB(MP(j, get(foo[i][1], foo[i + 1][1])));
//		g[j - 1].PB(MP(j + 1, get(foo[i][1], foo[i + 1][0])));
//	}
//	if (j != 0)
//	{
//		int s = 1;
//		n = j + 2;
//		vector<LL> d(n, LINF);
//		d[s] = 0;
//		priority_queue < pair<LL, LL> > q;
//		q.push(make_pair(0, s));
//		while (!q.empty()) {
//			LL v = q.top().second, cur_d = -q.top().first;
//			q.pop();
//			if (cur_d > d[v])  continue;
//
//			for (size_t j = 0; j < g[v].size(); ++j) {
//				LL to = g[v][j].first,
//					len = g[v][j].second;
//				if (d[v] + len < d[to]) {
//					d[to] = d[v] + len;
//					q.push(make_pair(-d[to], to));
//				}
//			}
//		}
//		res += min(d[j + 1], d[j]);
//	}
//	cout << res << endl;
//
//
//
//
//	return 0;
//}
//
