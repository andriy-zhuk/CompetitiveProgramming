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
//int n;
//vector<pair<PII, PII > > a;
//
//struct ST
//{
//	set<PII> t[4 * MAX];
//	void upd(int v, int tl, int tr, int l, PII cur, bool state)
//	{
//		if (state == true)
//		{
//			t[v].insert(cur);
//		}
//		else
//		{
//			t[v].erase(cur);
//		}
//		if (tl == tr)
//		{
//			return;
//		}
//		int tm = (tl + tr) / 2;
//		if (l <= tm)
//		{
//			upd(v + v, tl, tm, l, cur, state);
//		}
//		else
//		{
//			upd(v + v + 1, tm + 1, tr, l, cur, state);
//		}
//	}
//
//	void get(int v, int tl, int tr, int l, int r, set<PII> & ret)
//	{
//		if (ret.size() > 1)
//			return;
//		if (l == tl && r == tr)
//		{
//			auto it = t[v].begin();
//			while (it != t[v].end() && ret.size() <= 1)
//			{
//				ret.insert(*it);
//				it++;
//			}
//			return;
//		}
//
//		int tm = (tl + tr) / 2;
//
//		if (r <= tm)
//		{
//			get(v + v, tl, tm, l, r,ret);
//		}
//		else if (l >= tm + 1)
//		{
//			
//			auto it = t[v+v].lower_bound(MP(l, 0));
//			while (it != t[v + v].end() && ret.size() <= 1)
//			{
//				ret.insert(*it);
//				it++;
//			}
//			get(v + v + 1, tm + 1, tr, l, r,ret);
//		}
//		else
//		{
//			get(v + v, tl, tm, l, tm,ret);
//			get(v + v + 1, tm + 1, tr, tm + 1, r,ret);
//		}
//	}
//
//
//}q;
//
//struct ST2
//{
//	set<PII> t[4 * MAX];
//	void upd(int v, int tl, int tr, int l, PII cur, bool state)
//	{
//		if (state == true)
//		{
//			t[v].insert(cur);
//		}
//		else
//		{
//			if (t[v].lower_bound(cur) != t[v].end() && *t[v].lower_bound(cur) == cur)
//				t[v].erase(cur);
//		}
//		if (tl == tr)
//		{
//			return;
//		}
//		int tm = (tl + tr) / 2;
//		if (l <= tm)
//		{
//			upd(v + v, tl, tm, l, cur, state);
//		}
//		else
//		{
//			upd(v + v + 1, tm + 1, tr, l, cur, state);
//		}
//	}
//
//	void get(int v, int tl, int tr, int l, int r, set<PII>& ret)
//	{
//		if (l == tl && r == tr)
//		{
//			auto it = t[v].begin();
//			while (it != t[v].end())
//			{
//				ret.insert(*it);
//				it++;
//			}
//			return;
//		}
//
//		int tm = (tl + tr) / 2;
//
//		if (r <= tm)
//		{
//			get(v + v, tl, tm, l, r, ret);
//		}
//		else if (l >= tm + 1)
//		{
//
//			auto it = t[v + v].lower_bound(MP(l, 0));
//			while (it != t[v + v].end())
//			{
//				ret.insert(*it);
//				it++;
//			}
//			get(v + v + 1, tm + 1, tr, l, r, ret);
//		}
//		else
//		{
//			get(v + v, tl, tm, l, tm, ret);
//			get(v + v + 1, tm + 1, tr, tm + 1, r, ret);
//		}
//	}
//
//
//}alone;
//
//bool has(const set<PII>& a, PII x)
//{
//	auto it = a.lower_bound(x);
//	if (it == a.end())
//		return 0;
//	return *it == x;
//}
//
//
//struct ev
//{
//	int x;
//	int l, r;
//	int open;
//	int id;
//	bool operator<(const ev& e)
//	{
//		return MP(x, MP(open, id)) < MP(e.x, MP(e.open, e.id));
//	}
//
//};
//set<PII> ans[100005];
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	cin >> n;
//	vector<PII> foo[2];
//	vector<ev> e;
//	FOR(i, 0, n)
//	{
//		int a1, b, c, d;
//		cin >> a1 >> b >> c >> d;
//		d--;
//		a.PB( MP( MP(a1,b),MP(c,d ) )  );
//		foo[1].PB(MP(b, 2 * i));
//		foo[1].PB(MP(d, 2 * i+1));
//	}
//
//	sort(ALL(foo[1]));
//	int j = 0;
//	FOR(i, 0, foo[1].size())
//	{
//		if (i && foo[1][i].first != foo[1][i - 1].first)
//		{
//			j++;
//		}
//		if (foo[1][i].second % 2)
//		{
//			a[foo[1][i].second / 2].second.second = j;
//		}
//		else
//		{
//			a[foo[1][i].second / 2].first.second = j;
//		}
//	}
//	int ny = j + 1;
//	
//	FOR(i, 0, n)
//	{
//		e.PB({ a[i].first.first, a[i].first.second, a[i].second.second, 1 , i});
//		e.PB({ a[i].second.first, a[i].first.second, a[i].second.second, 0 , i});
//	}
//	sort(ALL(e));
//	
//	FOR(i, 0, e.size())
//	{
//		if (e[i].open == 1)
//		{
//			int id = e[i].id;
//			int l = e[i].l;
//			int r = e[i].r;
//			q.get(1, 0, ny - 1, l, r, ans[id]);
//			if (ans[id].size() == 0)
//			{
//				alone.upd(1, 0, ny - 1, l, MP(r, id), true);
//			}
//			else if (ans[id].size() == 1)
//			{
//				ans[ans[id].begin()->second].insert(MP(r, id));
//				alone.upd(1, 0, ny - 1, l, MP(r, id), true);
//			}
//			else
//			{
//				set<PII> cur;
//				cur.clear();
//				alone.get(1, 0, ny - 1, l, r, cur);
//				for (auto& iter : cur) // 
//				{
//				
//					ans[iter.second].insert(MP(r, id));
//					if (ans[iter.second].size() > 1)
//					{
//						alone.upd(1, 0, ny - 1, a[iter.second].first.second, MP(iter.first, iter.second), false);
//					}
//				}
//			}
//			q.upd(1, 0, ny - 1, l, MP(r, id), true);
//		}
//		else
//		{
//			int id = e[i].id;
//			int l = e[i].l;
//			int r = e[i].r;
//			q.upd(1, 0, ny - 1, l, MP(r, id), false);
//			alone.upd(1, 0, ny - 1, l, MP(r, id), false);
//		}
//	}
//	
//	map<PII, int> can;
//
//	FOR(i, 0, n)
//	{
//		if (ans[i].size() == 1)
//		{
//			can[MP(i, ans[i].begin()->second)] = 1;
//		}
//	}
//	int answer = 0;
//
//	for (auto& iter : can)	
//	{
//		if (can.count(MP(iter.first.second, iter.first.first)) )
//		{
//			answer++;
//		}
//	}
//
//
//
//	cout << answer/2 << endl;
//
//
//
//	return 0;
//}
//
///*
//3
//0 0 2 2
//1 1 3 3
//4 7 7 11
//
//5
//0 0 4 4
//2 2 3 3
//-2 -2 0 0
//4 4 5 5
//0 4 4 6
//
//*/