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
//const int MAX = 200010;
//const long double PI = acos(-1.);
//const double EPS = 1e-6;
//const LL mod = INF + 7;
//
//struct ST
//{
//	LL t[4*MAX];
//	LL g[4*MAX];
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
//			build(a, v + v, tl, tm);
//			build(a, v + v + 1, tm + 1, tr);
//			t[v] = min(t[v + v], t[v + v + 1]);
//		}
//	}
//
//	void update(int v, int tl, int tr, int l, int r, LL val)
//	{
//		if (l > r)
//			return;
//		if (tl == l && tr == r)
//		{
//			g[v] += val;
//		}
//		else
//		{
//			int tm = (tl + tr) >> 1;
//			update(v + v, tl, tm, l, min(tm, r), val);
//			update(v + v + 1, tm + 1, tr, max(tm + 1, l), r, val);
//			t[v] = min(t[v + v] + g[v + v], t[v + v + 1] + g[v + v + 1]);
//		}
//	}
//
//	LL get(int v, int tl, int tr, int l, int r)
//	{
//		if (l > r)
//			return LINF;
//		if (tl == l && tr == r)
//		{
//			return t[v] + g[v];
//		}
//		int tm = (tl + tr) >> 1;
//		int ret = min(
//			get(v + v, tl, tm, l, min(tm, r)),
//			get(v + v + 1, tm + 1, tr, max(l, tm + 1), r)
//		);
//		return ret + g[v];
//	}
//} foo;
//
//int n, a[200005];
//LL rmq(int l, int r)
//{
//	if (l > r)
//	{
//		return min(rmq(0, r), rmq(l, n - 1));
//	}
//	return foo.get(1, 0, n - 1, l, r);
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
//	foo.update(1, 0, n - 1, l, r, val);
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
//	foo.build(a, 1, 0, n-1);
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