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
//LL pref[200005];
//struct ST
//{
//	LL t[4 * 200005];
//	LL g[4 * 200005];
//	void build(int v, int tl, int tr)
//	{
//		t[v]= pref[tl];
//		g[v] = 0;
//		if (tl == tr)
//		{
//			return;
//		}
//		int tm = (tl + tr) / 2;
//		build(v + v, tl, tm);
//		build(v + v + 1, tm + 1, tr);
//	}
//	void upd(int v, int tl, int tr, int l, int r, int x) // += x;
//	{
//		if (l == tl && r == tr)
//		{
//			g[v] += x;
//			return;
//		}
//		int tm = (tl + tr) / 2;
//		if (r <= tm)
//		{
//			upd(v + v, tl, tm, l, r, x);
//		}
//		else if (l >= tm + 1)
//		{
//			upd(v + v + 1, tm + 1, tr, l, r, x);
//		}
//		else
//		{
//			upd(v + v, tl, tm, l, tm, x);
//			upd(v + v + 1, tm + 1, tr, tm + 1, r, x);
//		}
//		t[v] = min((t[v + v] + g[v + v]), (t[v + v + 1]+ g[v + v + 1])); 	
//	}
//} q;
//
//
//LL p[200005];
//LL a[200005];
//
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	int n;
//	cin >> n;
//	FOR(i, 0, n)
//	{
//		cin >> p[i];
//		p[i]--;;
//	}
//	FOR(i, 0, n)
//	{
//		cin >> a[i];
//		pref[p[i]] = a[i];	
//	}
//	FOR(i, 1, n)
//	{
//		pref[i] += pref[i - 1];
//	}
//	q.build(1, 0, n - 1);
//
//	LL best = a[0];
//	if (p[0] == 0)
//		best = 0;
//	FOR(i, 0, n-1)
//	{
//		int x = p[i];
//		int val = a[i];
//		q.upd(1, 0, n - 1, x, n - 1, -val);
//		if (x)
//		{
//			q.upd(1, 0, n - 1, 0, x - 1, val);
//		}
//
//		best = min(best, (q.t[1] + q.g[1]));
//	}
//	cout << best << endl;
//
//
//
//
//	return 0;
//}
