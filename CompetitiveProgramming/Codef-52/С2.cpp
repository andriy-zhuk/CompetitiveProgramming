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
//#include <sstream>
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
//int t[MAX * 40 * 4];
//int g[MAX * 40 * 4][2];
//int col[MAX * 40 * 4];
//int vcount = 0;
//struct PST
//{
//	void copy(int v, int old)
//	{
//		t[v] = t[old];
//		col[v] = col[old];
//		g[v][0] = g[old][0];
//		g[v][1] = g[old][1];
//	}
//
//	void push(int v, int tl, int tr)
//	{
//		if (tl == tr)
//		{
//			t[v] += col[v];
//			col[v] = 0;
//			return;
//		}
//		int oldL = g[v][0];
//		int oldR = g[v][1];
//		g[v][0] = vcount++;
//		g[v][1] = vcount++;
//		copy(g[v][0], oldL);
//		copy(g[v][1], oldR);
//		col[g[v][0]] += col[v];
//		col[g[v][1]] += col[v];
//		t[v] += col[v];
//		col[v] = 0;
//	}
//
//	int getVal(int v)
//	{
//		return t[v] + col[v];
//	}
//
//	int build(int *a, int tl, int tr)
//	{
//		int v = vcount++;
//		if (tl == tr)
//		{
//			t[v] = a[tl];
//			return v;
//		}
//		int tm = (tl + tr) / 2;
//		g[v][0] = build(a, tl, tm);
//		g[v][1] = build(a, tm + 1, tr);
//		t[v] = min(t[g[v][0]], t[g[v][1]]);
//		return v;
//	}
//
//	int updZH(int v, int tl, int tr, int l, int r, int val)
//	{
//		int old = v;
//		v = vcount++;
//		copy(v, old);
//
//		upd(v, tl, tr, l, r, val);
//		return v;
//	}
//
//	void upd(int v, int tl, int tr, int l, int r, int val)
//	{
//		push(v, tl, tr);
//		if (tl == l && tr == r)
//		{
//			col[v] += val;
//			return;
//		}
//		int tm = (tl + tr) / 2;
//		if (r <= tm)
//		{
//			upd(g[v][0], tl, tm, l, r, val);
//		}
//		else if (l >= tm + 1)
//		{
//			upd(g[v][1], tm + 1, tr, l, r, val);
//		}
//		else
//		{
//			upd(g[v][0], tl, tm, l, tm, val);
//			upd(g[v][1], tm + 1, tr, tm + 1, r, val);
//		}
//		t[v] = min(getVal(g[v][0]), getVal(g[v][1]));
//	}
//
//
//
//	int get(int v, int tl, int tr, int l, int r)
//	{
//		if (tl == l && tr == r)
//		{
//			return t[v] + col[v];
//		}
//		int tm = (tl + tr) / 2;
//		if (l >= tm + 1)
//		{
//			int cur = get(g[v][1], tm + 1, tr, l, r);
//			return col[v] + cur;
//		}
//		if (r <= tm)
//		{
//			int cur = get(g[v][0], tl, tm, l, r);
//			return col[v] + cur;
//		}
//		int cur = get(g[v][0], tl, tm, l, tm);
//		int bur = get(g[v][1], tm + 1, tr, tm + 1, r);
//
//		return col[v] + min(cur, bur);
//	}
//} foo;
//
//int head;
//int n, a[200005];
//LL rmq(int l, int r)
//{
//	if (l > r)
//	{
//		return min(rmq(0, r), rmq(l, n - 1));
//	}
//	return foo.get(head, 0, n - 1, l, r);
//}
//
//void add(int l, int r, int val)
//{
//	if (l > r)
//	{
//		add(0, r, val);
//		add(l, n - 1, val);
//		return;
//	}
//	head = foo.updZH(head, 0, n - 1, l, r, val);
//}
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n;
//	FOR(i, 0, n)
//	{
//		cin >> a[i];
//	}
//	head = foo.build(a, 0, n - 1);
//	
//	int m;
//	cin >> m;
//	string s;
//	getline(cin, s);
//	FOR(i, 0, m)
//	{
//		getline(cin, s);
//		stringstream sts;
//		sts.str(s);
//		vector<int> gg;
//		gg.clear();
//		int x;
//		while (sts >> x)
//			gg.PB(x);
//		if (SZ(gg) == 2)
//		{
//			cout << rmq(gg[0], gg[1]) << endl;
//		}
//		else
//		{
//			add(gg[0], gg[1], gg[2]);
//		}
//	}
//
//
//
//	return 0;
//}