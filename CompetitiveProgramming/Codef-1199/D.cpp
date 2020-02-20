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
//const int MAX = 400010;
//const long double PI = acos(-1.);
//const double EPS = 1e-6;
//const LL mod = INF + 7;
//
//map<int, int> col;
//struct ST
//{
//	int t[4 * MAX];
//	void upd(int v, int tl, int tr, int pos, int c)
//	{
//		if (tl == tr)
//		{
//			t[v] = c;
//			return;
//		}
//		int tm = (tl + tr) >> 1;
//		if (pos <= tm)
//		{
//			upd(v + v, tl, tm, pos, c);
//		}
//		else
//		{
//			upd(v + v + 1, tm + 1, tr, pos, c);
//		}
//		t[v] = max(t[v + v], t[v+v+1]);
//	}
//
//	int get(int v, int tl, int tr, int l, int r)
//	{
//		if (l > r)
//			return 0;
//		if (tl == l && r == tr)
//		{
//			return t[v];
//		}
//		int tm = (tl + tr) >> 1;
//		return max(get(v + v, tl, tm, l, min(r, tm)), get(v + v + 1, tm + 1, tr, max(l, tm + 1), r));
//	}
//} foo;
//
//int n;
//int a[200005];
//PII best[200005];
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	cin >> n;
//	int curcha = 0;
//	FOR(i, 0, n)
//	{
//		int x;
//		cin >> x;
//		a[i] = x;
//		best[i] = MP(x, -1);
//	}
//	int q;
//	cin >> q;
//	FOR(i,0,q)
//	{
//		int x, p, k;
//		cin >> x >> p;
//		if (x == 1)
//		{
//			cin >> k;
//			best[p - 1] = MP(k, i);
//		}
//		else
//		{
//			foo.upd(1, 0, q - 1, i, p);
//		}
//	}
//
//	FOR(i, 0, n)
//	{
//		int last = best[i].second;
//		int val = foo.get(1, 0, q - 1, last + 1, q - 1);
//		last = max(best[i].first, val);
//		cout << last << ' ';
//	}
//
//	return 0;
//}