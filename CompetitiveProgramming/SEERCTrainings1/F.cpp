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
//const int MAX = 200010;
//const long double PI = acos(-1.);
//const double EPS = 1e-6;
//const LL mod = INF + 7;
//
//struct val
//{
//	LL best, bestL, bestR;
//	val(LL x, LL y)
//	{
//		bestL = -y + 2 * x;
//		bestR = y + 2 * x;
//		best = 0;
//	}
//	val()
//	{
//		best = bestL = bestR = 0;
//	}
//};
//
//val combine(val a, val b)
//{
//	val ret;
//	ret.bestL = max(a.bestL, b.bestL);
//	ret.bestR = max(a.bestR, b.bestR);
//	ret.best = max(max(a.best, b.best), max(a.bestL + b.bestR, 0LL));
//	return ret;
//}
//
//struct ST
//{
//	val t[MAX * 4];
//	void build(pair<LL, LL>* a, int v, int tl, int tr)
//	{
//		if (tl == tr)
//		{
//			t[v] = val(a[tl].first, a[tl].second);
//			return;
//		}
//		int tm = (tl + tr) / 2;
//		build(a, v + v, tl, tm);
//		build(a, v + v + 1, tm + 1, tr);
//
//		t[v] = combine(t[v + v], t[v + v + 1]);
//	}
//
//	val get(int v, int tl, int tr, int l, int r)
//	{
//		if (tl == l && tr == r)
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
//		return combine(
//			get(v + v, tl, tm, l, tm),
//			get(v + v + 1, tm + 1, tr, tm + 1, r)
//		);
//	}
//} q;
//
//int n, m;
//LL d[200005];
//LL h[200005];
//
//
//pair<LL, LL> a[200005];
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n >> m;
//	FOR(i, 0, n)
//	{
//		cin >> d[i+1];
//		d[i + n+1] = d[i+1];
//	}
//	FOR(i, 0, n)
//	{
//		cin >> h[i];
//		h[i + n] = h[i];
//	}
//	int nn = 2 * n;
//	FOR(i, 0, nn)
//	{
//		if (i)
//		{
//			a[i].second = a[i - 1].second;
//		}
//		a[i].first = h[i];
//		a[i].second += d[i];
//	}
//
//	q.build(a, 1, 0, nn-1);
//
//	FOR(i, 0, m)
//	{
//		int l, r;
//		cin >> l >> r;
//		l--, r--;
//		if (l <= r)
//		{
//			cout << q.get(1, 0, nn - 1, r + 1, l + n - 1).best << endl;
//		}
//		else
//		{
//			cout << q.get(1, 0, nn - 1, r + 1, l - 1).best << endl;
//		}
//	}
//	return 0;
//}
//
