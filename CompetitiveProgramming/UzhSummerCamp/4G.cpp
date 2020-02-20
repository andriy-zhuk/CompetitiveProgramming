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
//struct node
//{
//	int l, r;
//	nodeValue val;
//};
//
//struct nodeValue
//{
//	int siz;
//	int best;
//	int pref;
//	int suf;
//};
//
//nodeValue combine(nodeValue a, nodeValue b)
//{
//	if (a.siz == INF)
//		return b;
//	if (b.siz == INF)
//		return a;
//	nodeValue res;
//	res.best = max(a.best, max(b.best, a.suf + b.pref));
//	res.pref = a.pref;
//	res.siz = a.siz + b.siz;
//	if (res.pref == a.siz)
//	{
//		res.pref += b.pref;
//	}
//	res.suf = b.suf;
//	if (res.suf == b.siz)
//	{
//		res.suf += a.suf;
//	}
//	return res;
//}
//
//vector<node> t;
//
//int upd(int v, int tl, int tr, int pos, int val)
//{
//	if (tl == tr)
//	{
//		t[v].val = { 1, val, val, val };
//		return;
//	}
//	int tm = (tl + tr) / 2;
//	int 
//	if (pos <= tm)
//	{
//		upd(v + v, tl, tm, pos, val);
//	}
//	else
//	{
//		upd(v + v + 1, tm + 1, tr, pos, val);
//	}
//	nodeValue nval = combine(t[v + v].val, t[v + v + 1].val);
//	if (nval != t[v].val)
//	{
//
//	}
//}
//
//
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	return 0;
//}