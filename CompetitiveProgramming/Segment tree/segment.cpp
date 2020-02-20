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
//// sum on a segment with update a[pos] = val
//
//struct ST1
//{
//	int n, t[4 * MAX];
//	int trash[200];
//
//	void build(int a[], int v, int tl, int tr)
//	{
//		if (tl == tr)
//		{
//			t[v] = a[tl];
//		}
//		else
//		{
//			int tm = (tl + tr) >> 1;
//			build(a, v << 1, tl, tm);
//			build(a, (v << 1) + 1, tm + 1, tr);
//			t[v] = t[(v << 1)] + t[(v << 1) + 1];
//		}
//	}
//
//	int sum(int v, int tl, int tr, int l, int r)
//	{
//		if (l > r)
//			return 0;
//		if (l == tl && r == tr)
//			return t[v];
//		int tm = (tl + tr) >> 1;
//		return	sum((v << 1), tl, tm, l, min(tm, r)) +
//			sum((v << 1) + 1, tm + 1, tr, max(tm + 1, tl), tr);
//	}
//
//	void update(int v, int tl, int tr, int pos, int val)
//	{
//		if (tl == tr)
//		{
//			t[v] = val;
//		}
//		else
//		{
//			int tm = (tl + tr) >> 1;
//			if (tm > pos)
//			{
//				update((v << 1) + 1, tm + 1, tr, pos, val);
//			}
//			else
//			{
//				update((v << 1), tl, tm, pos, val);
//			}
//			t[v] = t[(v << 1)] + t[(v << 1) + 1];
//		}
//	}
//
//	void u_update(int pos, int val)
//	{
//		int v = 1, tl = 0, tr = n - 1, p = 0;
//		while (tl != tr)
//		{
//			trash[p++] = v;
//			int tm = (tl + tr) >> 1;
//			if (tm > pos)
//			{
//				v = (v << 1) + 1;
//				tl = tm + 1;
//			}
//			else
//			{
//				v = (v << 1);
//				tr = tm;
//			}
//		}
//		t[tl] = val;
//		while (p)
//		{
//			v = trash[--p];
//			t[v] = t[(v << 2)] + t[(v << 2) + 1];
//		}
//	}
//
//	int prefsum_lb(int v, int tl, int tr, int x)
//	{
//		if (t[v] < x)
//			return -1;
//		if (tl == tr)
//			return tl;
//		int tm = (tl + tr) >> 1;
//		if (t[(v << 1)] < x)
//		{
//			return prefsum_lb((v << 1) + 1, tm + 1, tr, x - t[(v << 1)]);
//		}
//		else
//		{
//			return prefsum_lb((v << 1), tl, tm, x);
//		}
//	}
//};
//
//// minimum(maximum) on a segment with update a[pos] = val
//
//struct ST2
//{
//	int n, t[4 * MAX];
//	int trash[200];
//	int DEFAULT = INF;
//
//	void build(int a[], int v, int tl, int tr)
//	{
//		if (tl == tr)
//		{
//			t[v] = a[tl];
//		}
//		else
//		{
//			int tm = (tl + tr) >> 1;
//			build(a, (v << 1), tl, tm);
//			build(a, (v << 1), tm + 1, tr);
//		}
//	}
//
//	int minimum(int v, int tl, int tr, int l, int r)
//	{
//		if (l > r)
//			return DEFAULT;
//		if (l == tl && r == tr)
//			return t[v];
//		int tm = (tl + tr) >> 1;
//		return min(minimum((v << 1), tl, tm, l, min(r, tm)),
//			minimum((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r));
//	}
//
//	void update(int v, int tl, int tr, int pos, int val)
//	{
//		if (tl == tr)
//		{
//			t[v] = val;
//		}
//		int tm = (tl + tr) >> 1;
//		if (pos > tm)
//			update((v << 1) + 1, tm + 1, tr, pos, val);
//		else
//			update((v << 1), tl, tm, pos, val);
//		t[v] = min(t[(v << 1)], t[(v << 1) + 1]);
//	}
//
//	void u_update(int pos, int val)
//	{
//		int p = 0, v = 1, tl = 0, tr = n - 1;
//		while (tl != tr)
//		{
//			trash[p++] = v;
//			int tm = (tl + tr) >> 1;
//			if (pos > tm)
//			{
//				v = (v << 1) + 1;
//				tl = tm + 1;
//			}
//			else
//			{
//				v = (v << 1);
//				tr = tm;
//			}
//		}
//		t[v] = val;
//		while (p)
//		{
//			v = trash[--p];
//			t[v] = min(t[(v << 1)], t[(v << 1) + 1]);
//		}
//	}
//};
//
//// minimum(maximum) and its count on a segment with update a[pos] = val;
//
//struct ST3
//{
//	int n;
//	pair<int, int> t[4 * MAX];
//	int trash[200];
//	pair<int, int> DEFAULT = MP(INF, 0);
//	pair<int, int> merge(pair<int, int> l, pair<int, int> r)
//	{
//		if (l.first < r.first)
//			return l;
//		if (l.first > r.first)
//			return r;
//		l.second += r.second;
//		return l;
//	}
//
//	void build(int a[], int v, int tl, int tr)
//	{
//		if (tl == tr)
//		{
//			t[v] = MP(a[tl], 1);
//		}
//		else
//		{
//			int tm = (tl + tr) >> 1;
//			build(a, (v << 1), tl, tm);
//			build(a, (v << 1) + 1, tm + 1, tr);
//			t[v] = merge(t[(v << 1)], t[(v << 1) + 1]);
//		}
//	}
//
//	pair<int, int> minimum(int v, int tl, int tr, int l, int r)
//	{
//		if (l > r)
//		{
//			return DEFAULT;
//		}
//		if (tl == l && tr == r)
//		{
//			return t[v];
//		}
//		int tm = (tl + tr) >> 1;
//		return merge(minimum((v << 1), tl, tm, l, min(r, tm)),
//			minimum((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r));
//	}
//
//	void update(int v, int tl, int tr, int pos, int val)
//	{
//		if (tr == tl)
//		{
//			t[v] = MP(val, 1);
//		}
//		else
//		{
//			int tm = (tl + tr) >> 1;
//			if (pos > tm)
//			{
//				update((v << 1) + 1, tm + 1, tr, pos, val);
//			}
//			else
//			{
//				update((v << 1), tl, tm, pos, val);
//			}
//			t[v] = merge(t[(v << 1)], t[(v << 1) + 1]);
//		}
//	}
//
//	void u_update(int pos, int val)
//	{
//		int p = 0, v = 1, tl = 0, tr = n - 1;
//		while (tl != tr)
//		{
//			trash[p++] = v;
//			int tm = (tl + tr) >> 1;
//			if (pos > tm)
//			{
//				v = (v << 1) + 1;
//				tl = tm + 1;
//			}
//			else
//			{
//				v = (v << 1);
//				tr = tm;
//			}
//		}
//		t[v] = MP(val, 1);
//		while (p)
//		{
//			v = trash[--p];
//			t[v] = merge(t[(v << 1)], t[(v << 1) + 1]);
//		}
//	}
//};
//
//// position k-th zero with update a[pos] = (val == 0)
//
//struct ST4
//{
//	int n, t[4 * MAX];
//	int trash[200];
//
//	void build(int a[], int v, int tl, int tr)
//	{
//		if (tl == tr)
//		{
//			t[v] = (a[tl] == 0);
//		}
//		int tm = (tl + tr) >> 1;
//		build(a, (v << 1), tl, tm);
//		build(a, (v << 1) + 1, tm + 1, tr);
//		t[v] = t[(v << 1)] + t[(v << 1) + 1];
//	}
//
//	int find(int v, int tl, int tr, int k)
//	{
//		if (k > t[v])
//			return -1;
//		if (tl == tr)
//			return tl;
//		int tm = (tl + tr) >> 1;
//		if (k > t[(v << 1)])
//		{
//			find((v << 1) + 1, tm + 1, tr, k - t[(v << 1)]);
//		}
//		else
//		{
//			find((v << 1), tl, tm, k);
//		}
//	}
//
//	int u_find(int k)
//	{
//		int v = 1, tl = 0, tr = n - 1;
//		while (tl != tr)
//		{
//			if (k > t[v])
//				return -1;
//			int tm = (tl + tr) >> 1;
//			if (k > t[(v << 1)])
//			{
//				k -= t[(v << 1)];
//				v = (v << 1) + 1;
//				tl = tm + 1;
//			}
//			else
//			{
//				v = (v << 1);
//				tr = tm;
//			}
//		}
//		return tl;
//	}
//
//	void update(int v, int tl, int tr, int pos, int val)
//	{
//		if (tl == tr)
//		{
//			t[v] = (val == 0);
//		}
//		else
//		{
//			int tm = (tl + tr) >> 1;
//			if (pos > tm)
//			{
//				update((v << 1) + 1, tm + 1, tr, pos, val);
//			}
//			else
//			{
//				update((v << 1), tl, tm, pos, val);
//			}
//			t[v] = t[(v << 1)] + t[(v << 1) + 1];
//		}
//	}
//
//	void u_update(int pos, int val)
//	{
//		int p = 0, v = 1, tl = 0, tr = n - 1;
//		while (tl != tr)
//		{
//			trash[p++] = v;
//			int tm = (tl + tr) >> 1;
//			if (pos > tm)
//			{
//				v = (v << 1) + 1;
//				tl = tm + 1;
//			}
//			else
//			{
//				v = (v << 1);
//				tr = tm;
//			}
//		}
//		t[v] = (val == 0);
//		while (p)
//		{
//			v = trash[--p];
//			t[v] = t[(v << 1)] + t[(v << 1) + 1];
//		}
//	}
//};
//
//// addition on a segemnt, minimax query on a segment
//struct ST5
//{
//	int t[MAX]; // stores minimax values on a segment
//	int g[MAX]; // stores addtion on a segment
//	int n;
//
//	void add(int v, int tl, int tr, int l, int r, int val)
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
//	int get(int v, int tl, int tr, int pos)
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
//
//	int minimum(int v, int tl, int tr, int l, int r)
//	{
//		if (l > r)
//			return INF;
//		if (tl == l && tr == r)
//			return t[v] + g[v];
//		int tm = (tl + tr) >> 1;
//		return g[v] + min(
//			minimum((v << 1), tl, tm, l, min(r, tm)),
//			minimum((v << 1) + 1, tm + 1, tr, max(tm + 1, l), r)
//		);
//	}
//};
//
//// assignment on a segment, suma on a segment query
//
//struct ST6
//{
//	int t[4 * MAX], n;
//	int col[4 * MAX];
//	int value(int v, int tl, int tr)
//	{
//		if (col[v] != -1)
//			return (tr - tl + 1) * col[v];
//		return t[v];
//	}
//	void push(int v)
//	{
//		if (col[v] != -1)
//		{
//			col[(v << 1)] = col[(v << 1) + 1] = col[v];
//			col[v] = -1;
//		}
//	}
//
//	void build(int a[], int v, int tl, int tr)
//	{
//		if (tl == tr)
//		{
//			t[v] = a[tl];
//			col[v] = -1;
//		}
//		else
//		{
//			int tm = (tl + tr) >> 1;
//			build(a, (v << 1), tl, tm);
//			build(a, (v << 1) + 1, tm + 1, tr);
//			t[v] = t[(v << 1)] + t[(v << 1) + 1];
//			col[v] = -1;
//		}
//	}
//
//	void assign(int v, int tl, int tr, int l, int r, int val)
//	{
//		if (l > r)
//			return;
//		if (tl == l && tr == r)
//		{
//			col[v] = val;
//		}
//		else
//		{
//			push(v);
//			int tm = (tl + tr) >> 1;
//			assign(v + v, tl, tm, l, min(tm, r), val);
//			assign(v + v + 1, tm + 1, tr, max(tm + 1, l), r, val);
//			t[v] = value(v + v, tl, tm) + value(v + v + 1, tm + 1, tr);
//		}
//	}
//
//	int suma(int v, int tl, int tr, int l, int r)
//	{
//		if (l > r)
//			return 0;
//		if (tl == l && tr == r)
//		{
//			return value(v, tl, tr);
//		}
//		int tm = (tl + tr) >> 1;
//		push(v);
//		t[v] = suma(v + v, tl, tm, l, min(tm, r)) +
//			suma(v + v + 1, tm + 1, tr, max(tm + 1, l), r);
//		return t[v];
//	}
//};
//
//ST6 foo[26];
//string s;
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	int n, q;
//	cin >> n >> q;
//	cin >> s;
//	FOR(i, 0, SZ(s))
//	{
//		foo[s[i] - 'a'].assign(1, 0, n - 1, i, i, 1);
//	}
//
//	while (q--)
//	{
//		int l, r, k;
//		cin >> l >> r >> k;
//		l--, r--;
//		int cur = 0;
//		FOR(i, 0, 26)
//		{
//			int ii = i;
//			if (!k)
//				ii = 25 - i;
//			int cnt = foo[ii].suma(1, 0, n - 1, l, r);
//			foo[ii].assign(1, 0, n - 1, l, r, 0);
//			foo[ii].assign(1, 0, n - 1, l + cur, l + cur + cnt - 1, 1);
//			cur += cnt;
//		}
//	}
//	FOR(i, 0, n)
//	{
//		FOR(j, 0, 26)
//		{
//			if (foo[j].suma(1, 0, n - 1, i, i))
//			{
//				cout << char(j + 'a');
//				break;
//			}
//		}
//	}
//
//}