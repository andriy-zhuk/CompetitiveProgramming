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
//const int MAX = 3505;
//const long double PI = acos(-1.);
//const double EPS = 1e-6;
//const LL MOD = INF + 7;
//int a[MAX];
//int n, m, k;
//
//struct ST
//{
//	int t[4 * MAX];
//
//	void build(int v, int tl, int tr)
//	{
//		if (tl == tr)
//		{
//			t[v] = a[tl];
//			return;
//		}
//		int tm = (tl + tr) / 2;
//		build(v + v, tl, tm);
//		build(v + v + 1, tm + 1, tr);
//		t[v] = min(t[v + v], t[v + v + 1]);
//	}
//
//	int get(int v, int tl, int tr, int l, int r)
//	{
//		if (l == tl && r == tr)
//		{
//			return t[v];
//		}
//		int tm = (tl + tr) / 2;
//		if (l >= tm + 1)
//		{
//			return get(v + v + 1, tm + 1, tr, l, r);
//		}
//		if (r <= tm)
//		{
//			return get(v + v, tl, tm, l, r);
//		}
//		return min(
//			get(v + v, tl, tm, l, tm),
//			get(v + v + 1, tm + 1, tr, tm + 1, r)
//		);
//	}
//
//} q;
//
//
//void solve()
//{
//	cin >> n >> m >> k;
//	FOR(i, 0, n)
//	{
//		cin >> a[i];
//	}
//	q.build(1, 0, n - 1);
//	m--;
//	int best = -INF;
//	if (k >= m)
//	{
//		FOR(i, 0, n)
//		{
//			if (i <= m || (n-i-1) <= m)
//				best = max(best, a[i]);
//		}
//		cout << best << endl;
//		return;
//	}
//
//	FOR(l1, 0, k+1)
//	{
//		int cur = INF;
//		FOR(i, 0, m - k + 1)
//		{
//			cur = min(cur, max(a[l1 + i], a[n - k + l1 - 1 - (m - k - i)]));
//		}
//		if (cur != INF)
//			best = max(best, cur);
//	}
//	cout << best << endl;
//
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		solve();
//	}
//	return 0;
//}
//
