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
//const int maxn = 100 * 1000+7;
//
//map<int, int> foo;
//vector<int> positions[100005];
//int compr[100005];
//int a[100005], old[100005];
//int real[100005];
//int n;
//
//namespace ST
//{
//	int cnt = 1;
//	int g[maxn*30][2];
//	int t[maxn*30];
//
//	int build(int tl, int tr)
//	{
//		int v = cnt++;
//		if (tl == tr)
//		{
//			return v;
//		}
//		int tm = (tl + tr) / 2;
//		g[v][0] = build(tl, tm);
//		g[v][1] = build(tm + 1, tr);
//		return v;
//	}
//
//	int get(int v, int tl, int tr, int l, int r)
//	{
//		if (tl == l && tr == r)
//		{
//			return t[v];
//		}
//		int tm = (tl + tr) / 2;
//		if (r <= tm)
//		{
//			return get(g[v][0], tl, tm, l, r);
//		}
//
//		if (l > tm)
//		{
//			return get(g[v][1], tm + 1, tr, l, r);
//		}
//		return get(g[v][0], tl, tm, l, tm) + get(g[v][1], tm + 1, tr, tm + 1, r);
//	}
//
//	int upd(int v, int tl, int tr, int pos)
//	{
//		int u = cnt++;
//		g[u][0] = g[v][0];
//		g[u][1] = g[v][1];
//		t[u] = t[v];
//
//		if (tl == tr)
//		{
//			t[u] = old[pos];
//			return u;
//		}
//		int tm = (tl + tr) / 2;
//		
//		if (pos <= tm)
//		{
//			g[u][0] = upd(g[u][0], tl, tm, pos);
//		}
//		else
//		{
//			g[u][1] = upd(g[u][1], tm + 1, tr, pos);
//		}
//		t[u] = t[g[u][0]] + t[g[u][1]];
//		return u;
//	}
//}
//int head[100005];
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	int SUMA = 0;
//	cin >> n;
//	int cnt = 0;
//	vector<PII> zhepa;
//	FOR(i, 0, n)
//	{
//		cin >> a[i];
//		zhepa.PB(MP(a[i], i));
//		old[i] = a[i];
//	}
//	sort(ALL(zhepa));
//	FOR(i,0,n)
//	{
//		if (foo.count(zhepa[i].f) == 0)
//		{
//			real[cnt] = zhepa[i].f;
//			foo[zhepa[i].f] = cnt++;
//		}
//		compr[zhepa[i].s] = foo[zhepa[i].f];
//		positions[compr[zhepa[i].s]].PB(zhepa[i].s);
//	}
//	int last = ST::build(0, n - 1);
//	FOR(i, 0, cnt)
//	{
//		FOR(j, 0, SZ(positions[i]))
//		{
//			int id = positions[i][j];
//			head[i] = ST::upd(last, 0, n - 1, id);
//			last = head[i];
//		}
//	}
//	sort(a, a + n);
//	int m;
//	cin >> m;
//	while (m--)
//	{
//		int l, r;
//		cin >> l >> r;
//		l--, r--;
//		if (a[0] != 1)
//		{
//			cout << 1 << endl;
//			continue;
//		}
//
//		int curH = 0;
//		int suma = ST::get(head[curH], 0, n-1, l, r);
//		int res = ST::get(head[cnt-1], 0, n-1, l, r)+1;
//		while (curH < cnt)
//		{
//			curH = upper_bound(a, a+n, suma+1) - a - 1;
//			if (curH == n-1)
//			{
//				break;
//			}
//			curH = foo[a[curH]];
//			int nSuma = ST::get(head[curH], 0, n - 1, l, r);
//			if (nSuma == suma)
//			{
//				res = suma+1;	
//				break;
//			}
//			suma = nSuma;
//		}
//		cout << res << endl;
//	}
//
//
//
//	return 0;
//}