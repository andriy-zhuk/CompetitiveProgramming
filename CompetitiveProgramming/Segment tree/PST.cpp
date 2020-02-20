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
//int t[MAX * 20 * 8];
//int g[MAX * 20 * 8][2];
//int col[MAX * 20 * 8];
//int vcount = 1;
//
//int hd;
//
//struct PST
//{
//	void copy(int v, int old)
//	{
//		g[v][0] = g[old][0];
//		g[v][1] = g[old][1];
//		t[v] = t[old];
//	}
//	int build(int tl, int tr)
//	{
//		int v = vcount++;
//		if (tl == tr)
//		{
//			t[v] = 0;
//			return v;
//		}
//		int tm = (tl + tr) / 2;
//		g[v][0] = build(tl, tm);
//		g[v][1] = build(tm + 1, tr);
//		t[v] = t[g[v][0]] + t[g[v][1]];
//		return v;
//	}
//	int upd(int old, int tl, int tr, int pos, int val)
//	{
//		int v = vcount++;
//		copy(v, old);
//		if (tl == tr)
//		{
//			t[v] = val;
//			return v;
//		}
//		int tm = (tl + tr) / 2;
//		if (pos <= tm)
//		{
//			g[v][0] = upd(g[v][0], tl, tm, pos, val);
//		}
//		else
//		{
//			g[v][1] = upd(g[v][1], tm + 1, tr, pos, val);
//		}
//		t[v] = t[g[v][0]] + t[g[v][1]];
//		return v;
//	}
//
//	int get(int v, int tl, int tr, int l, int r)
//	{
//		if (tl == l && tr == r)
//			return t[v];
//		int tm = (tl + tr) / 2;
//		if (l >= tm + 1)
//		{
//			return get(g[v][1], tm + 1, tr, l, r);
//		}
//		if (r <= tm)
//		{
//			return get(g[v][0], tl, tm, l, r);
//		}
//		return get(g[v][0], tl, tm, l, tm) + get(g[v][1], tm + 1, tr, tm + 1, r);
//	}
//} q;
//
//struct PST2 {
//	int value(int v, int tl, int tr)
//	{
//		if (col[v] != -1)
//			return (tr - tl + 1) * col[v];
//		return t[v];
//	}
//
//	int build(int tl, int tr)
//	{
//		int v = vcount++;
//		if (tl == tr)
//		{
//			t[v] = 0;
//			col[v] = -1;
//			return v;
//		}
//
//		int tm = (tl + tr)/ 2;
//		g[v][0] = build(tl, tm);
//		g[v][1] = build(tm + 1, tr);
//		t[v] = t[g[v][0]] + t[g[v][1]];
//		col[v] = -1;
//		return v;
//	}
//	void copy(int v, int old)
//	{
//		t[v] = t[old];
//		g[v][0] = g[old][0];
//		g[v][1] = g[old][1];
//		col[v] = col[old];
//	}
//
//	void push(int& v, int tl, int tr)
//	{
//		int old = v;
//		v = vcount++;
//		if (vcount >= MAX * 20 * 8)
//		{
//			cout << "KAKA";
//			exit(0);
//		}
//		copy(v, old);
//		if (tl == tr || col[old] == -1)
//		{
//			return;
//		}
//		g[v][0] = vcount++;
//		g[v][1] = vcount++;
//		copy(g[v][0], g[old][0]);
//		copy(g[v][1], g[old][1]);
//		col[g[v][0]] = col[v];
//		col[g[v][1]] = col[v];
//		col[v] = -1;
//	}
//
//	int upd(int old, int tl, int tr, int l, int r, int val)
//	{
//		int v = old;
//		push(v, tl, tr);
//		if (tl == l && tr == r)
//		{
//			col[v] = val;
//			return v;
//		}
//		int tm = (tl + tr) /2;
//		if (l >= tm + 1)
//		{
//			g[v][1] = upd(g[v][1], tm + 1, tr, l, r, val);
//		} else if (r <= tm)
//		{
//			g[v][0] = upd(g[v][0], tl, tm, l, r, val);
//		}
//		else
//		{
//			g[v][0] = upd(g[v][0], tl, tm, l, tm, val);
//			g[v][1] = upd(g[v][1], tm + 1, tr, tm + 1, r, val);
//		}
//		t[v] = value(g[v][0], tl, tm) + value(g[v][1] , tm + 1, tr);
//		return v;
//	}
//
//	pair<int, int> get(int old, int tl, int tr, int l, int r) // value, vertex
//	{
//		if (tl == l && tr == r)
//		{
//			return MP(value(old, tl, tr), old);
//		}
//		int v = old;
//		push(v, tl, tr);
//		int tm = (tl + tr) / 2;
//		t[v] = value(g[v][0], tl, tm) + value(g[v][1], tm + 1, tr);
//		if (l >= tm + 1)
//		{
//			PII cur = get(g[v][1], tm + 1, tr, l, r);
//			g[v][1] = cur.second;
//			return MP(cur.first, v);
//		}
//		if (r <= tm)
//		{
//			PII cur = get(g[v][0], tl, tm, l, r);
//			g[v][0] = cur.second;
//			return MP(cur.first, v);
//		}
//		PII cur = get(g[v][0], tl, tm, l, tm);
//		g[v][0] = cur.second;
//		PII bur = get(g[v][1], tm + 1, tr, tm + 1, r);
//		g[v][1] = bur.second;
//		return MP(cur.first + bur.first, v);
//	}
//
//	int get2(int v, int tl, int tr, int l, int r)
//	{
//		if (tl == l && tr == r)
//		{
//			return value(v, tl, tr);
//		}
//		if (col[v] != -1)
//		{
//			return (r - l + 1) * col[v];
//		}
//		int tm = (tl + tr) / 2;
//		if (l >= tm + 1)
//		{
//			return get2(g[v][1], tm+1, tr, l, r);
//		}
//		if (r <= tm)
//		{
//			return get2(g[v][0], tl, tm, l, r);
//		}
//		return get2(g[v][0], tl, tm, l, tm) + get2(g[v][1], tm + 1, tr, tm + 1, r);
//	}
//} foo;
//
//int head[26];
//string s;
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	int n, q;
//	cin >> n >> q;
//	cin >> s;
//	FOR(i, 0, 26)
//	{
//		head[i] = foo.build(0, n - 1);
//	}
//	FOR(i, 0, SZ(s))
//	{
//		head[s[i]-'a'] = foo.upd(head[s[i]-'a'], 0, n - 1, i, i, 1);
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
//			PII curva = MP(foo.get2(head[ii], 0, n - 1, l, r), head[ii]);
//			head[ii] = curva.second;
//			int cnt = curva.first;
//			if (cnt)
//			{
//				head[ii] = foo.upd(head[ii], 0, n - 1, l, r, 0);
//				head[ii] = foo.upd(head[ii], 0, n-1, l + cur, l + cur + cnt - 1, 1);
//			}
//			cur += cnt;
//		}
//	}
//	FOR(i, 0, n)
//	{
//		FOR(j, 0, 26)
//		{
//			PII cur = MP(foo.get2(head[j], 0, n - 1, i, i), head[j]);
//			head[j] = cur.second;
//			if (cur.first)
//			{
//				cout << char(j + 'a');
//				break;
//			}
//		}
//	}
//
//}
