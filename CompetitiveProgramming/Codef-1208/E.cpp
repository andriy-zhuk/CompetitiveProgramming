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
//const int MAX = 1000010;
//const long double PI = acos(-1.);
//const double EPS = 1e-6;
//const LL mod = INF + 7;
//
//struct ST5
//{
//	LL t[MAX]; // stores minimax values on a segment
//	LL g[MAX]; // stores addtion on a segment
//	int n;
//	void build(int v, int tl, int tr)
//	{
//		t[v] = -LINF;
//		if (tl == tr)
//			return;
//		int tm = (tl + tr) / 2;
//		build(v + v, tl, tm);
//		build(v + v + 1, tm + 1, tr);
//	}
//
//	void add(int v, int tl, int tr, int l, int r, LL val)
//	{
//		if (l > r)
//			return;
//		if (tl == l && tr == r)
//		{
//			g[v] += val;
//			t[v] += val;
//		}
//		else
//		{
//			int tm = (tl + tr) >> 1;
//			add((v << 1), tl, tm, l, min(tm, r), val);
//			add((v << 1) + 1, tm + 1, tr, max(tm + 1, l), r, val);
//			t[v] = g[v] + min(t[(v << 1)], t[(v << 1) + 1]);
//		}
//	}
//
//	LL get(int v, int tl, int tr, int pos)
//	{
//		if (tl == tr)
//			return g[v];
//		int tm = (tl + tr) >> 1;
//		if (pos > tm)
//		{
//			return g[v] + get((v << 1) + 1, tm + 1, tr, pos);
//		}
//		else
//		{
//			return g[v] + get((v << 1), tl, tm, pos);
//		}
//	}
//} arr;
//
//int q, n;
//int pref[200005];
//int a[200005];
//int suf[200005];
//void perf()
//{
//	int w;
//	cin >> w;
//	FOR(i, 0, w)
//	{
//		cin >> a[i];
//		pref[i] = a[i];
//		if (i)
//			pref[i] = max(pref[i], pref[i - 1]);
//	}
//	RFOR(i, w, 0)
//	{
//		suf[i] = a[i];
//		if (i != w - 1)
//		{
//			suf[i] = max(suf[i], suf[i + 1]);
//		}
//	}
//
//	arr.add(1, 0, n - 1, w - 1, n - w, pref[w-1]);
//
//	cout << w - 1 << ' ' << n - w << ' ' <<  pref[w - 1] << endl;
//
//	FOR(i, n - w + 1, n)
//	{
//		int x = i;
//		LL val = suf[i-n+w];
//		arr.add(1, 0, n - 1, x, x, val);
//		cout << x << ' ' << val << endl;
//	}
//
//	FOR(i, 0, w - 1)
//	{
//		int x = i;
//		LL val = pref[i];
//		arr.add(1, 0, n - 1, x, x, val);
//		cout << x << ' ' << val << endl;
//	}
//
//	FOR(i, 0, w)
//	{
//		pref[i] = suf[i] = -LINF;
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	
//	int q;
//	FOR(i, 0, MAX)
//	{
//		pref[i] = suf[i] = -LINF;
//	}
//	cin >> q >> n;
//	arr.build(1, 0, n - 1);
//	FOR(i, 0, q)
//	{
//		perf();
//	}
//
//	FOR(i, 0, n)
//	{
//		cout << arr.get(1, 0, n - 1, i) << ' ';
//	}
//
//	return 0;
//}