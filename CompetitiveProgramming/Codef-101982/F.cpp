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
//const int MAX = 200010;
//const long double PI = acos(-1.);
//const double EPS = 1e-6;
//const LL MOD = INF + 7;
//
//
//struct ST
//{
//	int t[2][4 * MAX];
//	int pushed[4 * MAX];
//	int get(int v, int d)
//	{
//		if (pushed[v])
//			return t[1 - d][v];
//		return t[d][v];
//	}
//	void build(int* a, int v, int tl, int tr)
//	{
//		pushed[v] = 0;
//		if (tl == tr)
//		{
//			t[0][v] = a[tl];
//			t[1][v] = 0;
//			return;
//		}
//		else
//		{
//			int tm = (tl + tr) / 2;
//			build(a, v + v, tl, tm);
//			build(a, v + v + 1, tm + 1, tr);
//			FOR(i, 0, 2)
//				t[i][v] = get(v + v, i) + get(v + v + 1, i);
//		}
//	}
//
//	void push(int v, int tl, int tr)
//	{
//		if (!pushed[v])
//			return;
//		swap(t[0][v], t[1][v]);
//		if (tl != tr)
//		{
//			pushed[v + v] ^= 1;
//			pushed[v + v + 1] ^= 1;
//		}
//		pushed[v] = 0;
//	}
//
//	void upd(int v, int tl, int tr, int l, int r)
//	{
//		if (l == tl && r == tr)
//		{
//			pushed[v] ^= 1;
//			return;
//		}
//		int tm = (tl + tr) / 2;
//		push(v, tl, tr);
//		if (l >= tm + 1)
//		{
//			upd(v + v + 1, tm + 1, tr, l, r);
//		}
//		else if (r <= tm)
//		{
//			upd(v + v, tl, tm, l, r);
//		}
//		else
//		{
//			upd(v + v, tl, tm, l, tm);
//			upd(v + v + 1, tm + 1, tr, tm + 1, r);
//		}
//		FOR(i, 0, 2)
//			t[i][v] = get(v + v, i) + get(v + v + 1, i);
//	}
//
//	int get(int v, int tl, int tr)
//	{
//		push(v, tl, tr);
//		return t[1][v];
//	}
//} q;
//int n;
//pair<PII, PII> a[100005];
//
//int b[200005];
//int val[200005];
//
//struct ev
//{
//	int x;
//	int l, r;
//	int open;
//
//	bool operator<(const ev& e)
//	{
//		return MP(x, open) < MP(e.x, e.open);
//	}
//};
//vector<ev> e;
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n;
//	vector<PII> foo;
//	FOR(i, 0, n)
//	{
//		cin >> a[i].first.first >> a[i].first.second >> a[i].second.first >> a[i].second.second;
//		foo.PB(MP(a[i].first.second, 2 * i));
//		foo.PB(MP(a[i].second.second, 2 * i + 1));
//
//	}
//	sort(ALL(foo));
//	int j = 0;
//	FOR(i, 0, foo.size())
//	{
//		if (i && foo[i].first != foo[i - 1].first)
//		{
//			j++;
//		}
//		if (foo[i].second % 2)
//		{
//			a[foo[i].second / 2].second.second = j;
//		}
//		else
//		{
//			a[foo[i].second / 2].first.second = j + 1;
//		}
//		b[j] = foo[i].first;
//	}
//	j++;
//	FOR(i, 0, j)
//	{
//		if (i)
//			val[i] = b[i] - b[i - 1];
//		else
//			val[i] = b[i];
//	}
//
//	q.build(val, 1, 0, j - 1);
//	FOR(i, 0, n)
//	{
//		e.PB({ a[i].first.first, a[i].first.second, a[i].second.second, 1 });
//		e.PB({ a[i].second.first, a[i].first.second, a[i].second.second, 0 });
//	}
//
//	sort(ALL(e));
//	LL ans = 0;
//	FOR(i, 0, e.size() - 1)
//	{
//		q.upd(1, 0, j - 1, e[i].l, e[i].r);
//		if (e[i].x != e[i + 1].x)
//		{
//			ans = ans + 1LL*(e[i + 1].x - e[i].x) * q.get(1, 0, j - 1);
//		}
//	}
//	cout << ans << endl;
//
//
//
//	return 0;
//}
//
