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
//int n, m;
//vector<int> g[100005];
//vector<vector<int> > jedi;
//
//bool check(const vector<int>& x, const vector<int>& y)
//{
//	if (x.size() != y.size())
//		return 0;
//	FOR(i, 0, SZ(x))
//	{
//		if (x[i] != y[i])
//			return 0;
//	}
//	return 1;
//}
//int color[100005];
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	cin >> n >> m;
//	FOR(i, 0, m)
//	{
//		int x, y;
//		cin >> x >> y;
//		x--, y--;
//		g[x].PB(y);
//		g[y].PB(x);
//	}
//	FOR(i, 0, n)
//	{
//		sort(ALL(g[i]));
//	}
//	FOR(i, 0, n)
//	{
//		bool ok = false;
//		FOR(j, 0, jedi.size())
//		{
//			if (check(g[i], jedi[j]))
//			{
//				color[i] = j+1;
//				ok = true;
//				break;
//			}
//		}
//		if (ok)
//		{
//			continue;
//		}
//		if (jedi.size() == 3)
//		{
//			cout << -1 << endl;
//			return 0;
//		}
//		color[i] = SZ(jedi)+1;
//		jedi.PB(g[i]);
//	}
//	if (jedi.size() != 3)
//	{
//		cout << -1 << endl;
//		return 0;
//	}
//	FOR(i, 0, n)
//	{
//		cout << color[i] << ' ';
//	}
//	cout << endl;
//
//
//
//
//	return 0;
//}
//
