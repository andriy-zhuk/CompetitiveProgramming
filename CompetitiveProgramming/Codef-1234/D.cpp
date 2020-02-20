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
//struct ST
//{
//	int t[4 * MAX];
//	void upd(int v, int tl, int tr, int pos, int val)
//	{
//		if (tl == tr)
//		{
//			t[v] = val;
//			return;
//		}
//		int tm = (tl + tr) / 2;
//		if (pos <= tm)
//		{
//			upd(v + v, tl, tm, pos, val);
//		}
//		else
//		{
//			upd(v + v + 1, tm + 1, tr, pos, val);
//		}
//		t[v] = t[v + v] + t[v + v + 1];
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
//			return get(v + v, tl, tm, l, r);
//		}
//		if (l >= tm + 1)
//			return get(v + v + 1, tm + 1, tr, l, r);
//		return 
//			get(v + v, tl, tm, l, tm) +
//			get(v + v + 1, tm + 1, tr, tm + 1, r);
//	}
//} q[26];
//
//int n;
//string s;
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> s;
//	n = SZ(s);
//	FOR(i, 0, s.size())
//	{
//		q[s[i] - 'a'].upd(1, 0, n - 1, i, 1);
//	}
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int op;
//		cin >> op;
//		if (op == 1)
//		{
//			int p;
//			char c;
//			cin >> p >> c;
//			p--;
//			q[s[p] - 'a'].upd(1, 0, n - 1, p, 0);
//			s[p] = c;
//			q[s[p] - 'a'].upd(1, 0, n - 1, p, 1);
//		}
//		else
//		{
//			int l, r;
//			cin >> l >> r;
//			l--, r--;
//			int cur = 0;
//			FOR(i, 0, 26)
//			{
//				if (q[i].get(1, 0, n - 1, l, r))
//					cur++;
//			}
//			cout << cur << endl;
//		}
//	}
//
//
//	return 0;
//}
//
