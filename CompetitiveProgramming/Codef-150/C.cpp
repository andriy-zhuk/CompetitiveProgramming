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
//int n, m, c;
//int cords[200005];
//int p[200005];
//double values[200005];
//double pref[200005];
//
//struct node
//{
//	long double pref, suf, res, sum;
//};
//
//node def = {1e18, 1e18, 1e18, 1e18};
//
//struct ST
//{
//	node t[4 * MAX];
//
//	node combine(node l, node r)
//	{
//		node tt;
//		if (r.pref == def.pref && r.suf == def.suf && r.res == def.res&& r.sum == def.sum)
//			return l;
//		if (l.pref == def.pref && l.suf == def.suf && l.res == def.res && l.sum == def.sum)
//			return r;
//		tt.suf = min((long double)0, min(r.suf, r.sum + l.suf));
//		tt.pref = min((long double)0, min(l.pref, l.sum + r.pref));
//		tt.sum = l.sum + r.sum;
//		tt.res = max((long double)0, tt.sum - l.pref - r.suf);
//		tt.res = max(tt.res, r.res);
//		tt.res = max(tt.res, l.res);
//		return tt;
//	}
//	void build(int v, int tl, int tr)
//	{
//		if (tl == tr)
//		{
//			t[v].pref = min(pref[tr], 0.0);
//			t[v].suf = min(pref[tr], 0.0);
//			t[v].res = max(pref[tr], 0.0);
//			t[v].sum = pref[tr];
//		}
//		else
//		{
//			int tm = (tl + tr) >> 1;
//			build(v + v, tl, tm);
//			build(v + v + 1, tm + 1, tr);
//			t[v] = combine(t[v+v], t[v+v+1]);
//		}
//	}
//
//
//	node get(int v, int tl, int tr, int l, int r)
//	{
//		if (l > r)
//			return def;
//		if (tl == l && tr == r)
//		{
//			return t[v];
//		}
//		int tm = (tl + tr) >> 1;
//		return combine(get(v + v, tl, tm, l, min(tm, r)), get(v+v+1, tm+1, tr, max(l, tm+1), r));
//	}
//} foo;
//
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n >> m >> c;
//	
//	FOR(i, 0, n)
//	{
//		cin >> cords[i];
//	}
//	n--;
//	FOR(i, 0, n)
//	{
//		cin >> p[i];
//	}
//	FOR(i, 0, n)
//	{
//		cords[i] = cords[i + 1] - cords[i];
//	}
//
//	FOR(i, 0, n)
//	{
//		values[i] = (cords[i] * 1.0 / 2.0 - 1.0 * p[i]/100.0 * c);
//		pref[i] = values[i];
//		//pref[i+1] += pref[i];
//	}
//	/*FOR(i, 0, n + 1)
//	{
//		cout << pref[i] << ' ';
//	}
//	*///cout << endl << endl;
//	double ans = 0.0;
//	n--;
//	foo.build(1, 0, n);
//	FOR(i, 0, m)
//	{
//		int a, b;
//		cin >> a >> b;
//		a--, b-=2;
//		double cur = foo.get(1, 0, n , a, b).res;
//		//cout << foo.get(1, 0, n, a, b).res << ' ' << foo.get(1, 0, n, a, b).sum << ' ' << foo.get(1, 0, n, a, b).pref << ' ' << foo.get(1, 0, n, a, b).suf << endl;;
//	//	cout << cur << endl;
//		ans += cur;
//	}
//
//	cout << fixed << setprecision(8) << ans << endl;
//
//
//
//
//	return 0;
//}