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
//
//struct val
//{
//	int pref, suf, suma, best;
//};
//
//struct ST
//{
//	val t[MAX * 4];
//	val combine(val a, val b)
//	{
//		val cur;
//		cur.suma = a.suma + b.suma;
//		cur.pref = max(a.pref, a.suma + b.pref);
//		cur.suf = max(b.suf, b.suma + a.suf);
//		cur.best = max(a.suf + b.pref, max(a.best, b.best));
//		return cur;
//	}
//	void build(int* a, int v, int tl, int tr)
//	{
//		if (tl == tr)
//		{
//			t[v].suma = a[tl];
//			t[v].pref = a[tl];
//			t[v].suf = a[tl];
//			t[v].best = a[tl];
//			return;
//		}
//		int tm = (tl + tr) / 2;
//		build(a, v + v, tl, tm);
//		build(a, v + v + 1, tm + 1, tr);
//		t[v] = combine(t[v + v], t[v + v + 1]);
//	}
//	void upd(int v, int tl, int tr, int pos, int val)
//	{
//		if (tl == tr)
//		{
//			t[v].suma = val;
//			t[v].pref = val;
//			t[v].suf = val;
//			t[v].best = val;
//			return;
//		}
//		int tm = (tl + tr) / 2;
//		if (pos <= tm)
//		{
//			upd(v + v, tl, tm, pos, val);
//		}
//		else
//		{
//			upd(v + v + 1, tm + 1, tr, pos, val);
//		}
//		t[v] = combine(t[v + v], t[v + v + 1]);
//	}
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
//int a[100005];
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	int n;
//	cin >> n;
//	FOR(i, 0, n)
//	{
//		cin >> a[i];
//	}
//	q.build(a, 1, 0, n - 1);
//	int m;
//	cin >> m;
//	while (m--)
//	{
//		int t, x, y;
//		cin >> t >> x >> y;
//		if (t)
//		{
//			x--, y--;
//			cout << q.get(1, 0, n - 1, x, y).best << endl;	
//		}
//		else
//		{
//			x--;
//			q.upd(1, 0, n - 1, x, y);
//		}
//	}
//	return 0;
//}
//
