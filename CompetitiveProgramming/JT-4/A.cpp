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
//int n;
//set<int> a[100005];
//vector<int> foo[100005];
//vector<PII> ans;
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	cin >> n;
//	FOR(i, 2, n + 1)
//	{
//		FOR(k, 1, n + 1)
//		{
//			if (1LL*i * k > n)
//				break;
//			a[i].insert(i * k);
//			foo[i * k].PB(i);
//		}
//	}
//
//	RFOR(i, n+2, 2)
//	{
//		if (a[i].size() % 2 == 1)
//			continue;
//		for (set<int>::iterator it = a[i].begin(); it != a[i].end(); it++)
//		{
//			int ax = *it;
//			it++;
//			if (it == a[i].end())
//			{
//				break;
//			}
//			int bx = *it;
//
//			ans.PB(MP(ax, bx));
//
//			FOR(ii, 0, foo[ax].size())
//			{
//				if(foo[ax][ii] != i)
//					a[foo[ax][ii]].erase(ax);
//			}
//			FOR(ii, 0, foo[bx].size())
//			{
//				if (foo[bx][ii] != i)
//					a[foo[bx][ii]].erase(bx);
//			}
//		}
//		a[i].clear();
//	}
//	RFOR(i, n + 2, 2)
//	{
//		if (a[i].size() == 1)
//			continue;
//		for (set<int>::iterator it = a[i].begin(); it != a[i].end(); it++)
//		{
//			int ax = *it;
//			it++;
//			if (it == a[i].end())
//			{
//				break;
//			}
//			int bx = *it;
//
//			ans.PB(MP(ax, bx));
//
//			FOR(ii, 0, foo[ax].size())
//			{
//				if (foo[ax][ii] != i)
//					a[foo[ax][ii]].erase(ax);
//			}
//			FOR(ii, 0, foo[bx].size())
//			{
//				if (foo[bx][ii] != i)
//					a[foo[bx][ii]].erase(bx);
//			}
//		}
//		a[i].clear();
//	}
//	cout << ans.size() << endl;;
//	FOR(i, 0, SZ(ans))
//	{
//		cout << ans[i].first << ' ' << ans[i].second << endl;
//	}
//
//
//	return 0;
//}
//
