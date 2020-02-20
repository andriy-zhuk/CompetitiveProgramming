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
//set<pair<PII, int> > segm;
//int n, m;
//struct ST
//{
//	LL t[4 * MAX], p[4 * MAX];
//	void push(int v, int tl, int tr)
//	{
//		if (p[v])
//		{
//			t[v] += 1LL * (tr - tl + 1) * p[v];
//			if (tl != tr)
//			{
//				p[v + v] += p[v];
//				p[v + v + 1] += p[v];
//			}
//			p[v] = 0;
//		}
//	}
//	LL get(int v, int tl, int tr, int l, int r)
//	{
//		//cout << v << ' ' << tl << ' ' << tr << ' ' << l << ' ' << r <<  ' ' << t[v] << endl;
//		push(v, tl, tr);
//		if (l > r)
//			return 0;
//		if (tl == l && tr == r)
//			return t[v];
//		int tm = (tl + tr) / 2;
//		LL val = get(v + v, tl, tm, l, min(tm, r)) + get(v + v + 1, tm + 1, tr, max(tm + 1, l), r);
//		t[v] = t[v + v] + t[v + v + 1];
//		return val;
//	}
//
//	void upd(int v, int tl, int tr, int l, int r, int val)
//	{
//		push(v, tl, tr);
//		if (l > r)
//			return;
//		if (tl == l && tr == r)
//		{
//			p[v] += val;
//			push(v, tl, tr);
//			return;
//		}
//		int tm = (tl + tr) / 2;
//		upd(v + v, tl, tm, l, min(tm, r), val);
//		upd(v + v + 1, tm + 1, tr, max(tm + 1, l), r, val);
//		t[v] = t[v + v] + t[v + v + 1];
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
//	cin >> n >> m;
//	FOR(i, 0, n)
//	{
//		segm.insert(MP(MP(i, i), i+1));
//	}
//	FOR(i, 0, m)
//	{
//		int t;
//		cin >> t;
//		if (t == 1)
//		{
//			int l, r, x;
//			cin >> l >> r >> x;
//			l--, r--;
//
//			auto iter = segm.upper_bound(MP(MP(l, l), -1));
//			if (iter != segm.begin())
//				iter--;
//			vector<pair<PII, int> > toDel;
//			vector<pair<PII, int> > toAdd;
//			toAdd.clear();
//			toDel.clear();
//			toAdd.PB(MP(MP(l, r), x));
//			while (iter != segm.end())
//			{
//				pair<PII, int> cur = *iter;
//				if (cur.first.first > r)
//				{
//					break;
//				}
//				if (cur.first.second < l || cur.first.first > r)
//				{
//					iter++;
//					continue;
//				}
//				if (cur.first.first <= l && cur.first.second >= r)
//				{
//					toDel.PB(cur);
//					if (cur.first.first <= l - 1)
//					{
//						toAdd.PB(MP(MP(cur.first.first, l - 1), cur.second));
//					}
//					if (r + 1 <= cur.first.second)
//					{
//						toAdd.PB(MP(MP(r + 1, cur.first.second), cur.second));
//					}
//					foo.upd(1, 0, n - 1, l, r, abs(cur.second - x));
//
//				} 
//				else if (cur.first.first <= l)
//				{
//					toDel.PB(cur);
//					if (cur.first.first <= l - 1)
//					{
//						toAdd.PB(MP(MP(cur.first.first, l - 1), cur.second));
//					}
//					foo.upd(1, 0, n - 1, l, cur.first.second, abs(cur.second - x));
//				}
//				else if (cur.first.second <= r)
//				{
//					toDel.PB(cur);
//					foo.upd(1, 0, n - 1, cur.first.first, cur.first.second, abs(cur.second - x));
//				}
//				else
//				{
//					toDel.PB(cur);
//					if (r + 1 <= cur.first.second)
//					{
//						toAdd.PB(MP(MP(r + 1, cur.first.second), cur.second));
//					}
//					foo.upd(1, 0, n - 1, cur.first.first, r, abs(cur.second - x));
//				}
//				iter++;
//			}
//			for (auto& it : toDel)
//			{
//				segm.erase(it);
//			}
//			for (auto& it : toAdd)
//			{
//				segm.insert(it);
//			}
//		}
//		else
//		{
//			int l, r;
//			cin >> l >> r;
//			l--, r--;
//			cout << foo.get(1, 0, n - 1, l, r) << endl;
//		}
//	}
//	return 0;
//}