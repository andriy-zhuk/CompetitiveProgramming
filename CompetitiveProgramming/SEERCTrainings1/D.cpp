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
//const int MAX = 1000 * 1000 + 47;
//const long double PI = acos(-1.);
//const double EPS = 1e-6;
//const LL mod = INF + 7;
//int n, m;
//
//
//struct PST
//{
//	int t[MAX * 30];
//	int g[MAX * 30][2];
//	int vcount = 1;
//	int build(int tl, int tr)
//	{
//		int v = vcount++;
//		
//		if (tl == tr)
//		{
//			return v;
//		}
//		int tm = (tl + tr) / 2;
//		g[v][0] = build(tl, tm);
//		g[v][1] = build(tm + 1, tr);
//		return v;
//	}
//	void copy(int& v, int old)
//	{
//		t[v] = t[old];
//		g[v][0] = g[old][0];
//		g[v][1] = g[old][1];
//	}
//	int upd(int old, int tl, int tr, int pos, int val)
//	{
//		int v = vcount++;
//		copy(v, old);
//		if (tl == tr)
//		{
//			t[v] += val;
//			return v;
//		}
//		int tm = (tl + tr) / 2;
//		if (pos <= tm)
//		{
//			g[v][0] = upd(g[v][0], tl, tm, pos, val);
//		}
//		else
//		{
//			g[v][1] = upd(g[v][1], tm + 1, tr, pos, val);
//		}
//		t[v] = t[g[v][0]] + t[g[v][1]];
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
//		if (l >= tm + 1)
//		{
//			return get(g[v][1], tm + 1, tr, l, r);
//		}
//		return get(g[v][0], tl, tm, l, tm) + get(g[v][1], tm + 1, tr, tm + 1, r);
//	}
//} q;
//
//
//int head[MAX];
//vector<PII> e[MAX];
//int pts[300005];
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	int n, m;
//	cin >> n >> m;
//	FOR(i, 0, n)
//	{
//		int l, r;
//		cin >> l >> r;
//		l--, r--;
//		e[r].PB(MP(l, r));
//	}
//	head[MAX - 1] = q.build(0, MAX - 1);
//	RFOR(i, MAX - 1, 0)
//	{
//		head[i] = head[i + 1];
//		FOR(j, 0, e[i].size())
//		{
//			head[i] = q.upd(head[i], 0, MAX - 1, e[i][j].first, 1);
//		}
//	}
//	FOR(i, 0, m)
//	{
//		int siz;
//		cin >> siz;
//		FOR(i, 0, siz)
//		{
//			cin >> pts[i];
//			pts[i]--;
//		}
//		int answer = 0;
//		RFOR(i, siz, 0)
//		{
//			int cur = pts[i];
//			int val = q.get(head[cur], 0, MAX - 1, 0, cur);
//			answer += val;
//			//cout << '+' << val << endl;
//			if (i != siz-1)
//			{
//				cur = pts[i + 1];
//				int val = q.get(head[cur], 0, MAX - 1, 0, pts[i]);
//				answer -= val;
//				//cout << '-' << val << endl;
//			}
//		}
//		cout << answer << endl;
//	}
//
//	return 0;
//}
//
