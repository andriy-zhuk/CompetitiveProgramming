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
//using namespace std;
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
//typedef vector<int> VI;
//
//const int INF = 1000 * 1000 * 1000;
//const LL LINF = 1LL * INF * INF;
//const int MAX = 100010;
//const long double PI = acos(-1.);
//const double EPS = 1e-6;
//const LL MOD = INF + 7;
//struct ST
//{
//	LL t[400005 * 4];
//	LL a[400005 * 4];
//
//	void build(int v, int tl, int tr)
//	{
//		if (tl == tr)
//		{
//			t[v] = tl;
//			return;
//		}
//		int tm = (tl + tr) / 2;
//		build(v + v, tl, tm);
//		build(v + v + 1, tm + 1, tr);
//		t[v] = max(t[v + v], t[v + v + 1]);
//	}
//	LL get(int v)
//	{
//		return a[v] + t[v];
//	}
//	void push(int v, int tl, int tr)
//	{
//		if (a[v] == 0)
//			return;
//		if (tl == tr)
//			return;
//		a[v + v] += a[v];
//		a[v + v + 1] += a[v];
//		a[v] = 0;
//	}
//	LL get(int v, int tl, int tr, int l, int r)
//	{
//		if (tl == l && tr == r)
//		{
//			return get(v);
//		}
//		push(v, tl, tr);
//		int tm = tl + tr; tm /= 2;
//		LL ret = 0;
//		if (l > tm)
//		{
//			ret = get(v + v + 1, tm + 1, tr, l, r);
//		} else if (r <= tm)
//		{
//			ret = get(v + v, tl, tm, l, r);
//		}
//		else
//		{
//			ret = max(get(v + v, tl, tm, l, tm), get(v + v + 1, tm + 1, tr, tm + 1, r));
//		}
//		t[v] = max(get(v + v), get(v + v + 1));
//		return ret;
//	}
//	void upd(int v, int tl, int tr, int l, int r, int x)
//	{
//		if (tl == l && tr == r)
//		{
//			a[v] += x;
//			return;
//		}
//		push(v, tl, tr);
//		int tm = (tl + tr) / 2;
//		if (l > tm)
//		{
//			upd(v + v + 1, tm + 1, tr, l, r,x);
//		}
//		else if (r <= tm)
//		{
//			upd(v + v, tl, tm, l, r, x);
//		}
//		else
//		{
//			upd(v + v, tl, tm, l, tm, x);
//			upd(v + v + 1, tm + 1, tr, tm + 1, r, x);
//		}
//		t[v] = max(get(v + v), get(v + v + 1));
//	}
//} q;
//int n, m , k;
//set<PII> foo;
//int get(int x, int y)
//{
//	return  y + abs(x - k);
//}
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n >> k>> m;
//	k--;
//	q.build(1, 0, 2 * n);
//	multiset<int> goo;
//	FOR(i, 0, m)
//	{
//		int x, y;
//		cin >> x >> y;
//		x--, y--;
//		int val = 1;
//		if (foo.lower_bound(MP(x, y)) != foo.end() && *foo.lower_bound(MP(x, y)) == MP(x, y))
//		{
//			val = -1;
//			foo.erase(MP(x, y));
//			goo.erase(goo.find(get(x, y)));
//		}
//		else
//		{
//			foo.insert(MP(x, y));
//			goo.insert(get(x, y));
//		}
//		int ny = get(x, y);
//		q.upd(1, 0, 2 * n, 0, ny, val);
//		if (goo.size() == 0)
//		{
//			cout << 0 << endl;
//		}
//		else
//		{
//			int upper = *(--goo.end());
//			cout << max(q.get(1, 0, 2 * n, 0, upper)-n, 0LL) << endl;
//		}
//	}
//	return 0;
//}
//
