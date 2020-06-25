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
//using namespace std;
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
//typedef vector<int> VI;
//
//const int INF = 1000 * 1000 * 1000;
//const LL LINF = 1LL * INF * INF;
//const int MAX = 100010;
//const long double PI = acos(-1.);
//const double EPS = 1e-6;
//const LL MOD = INF + 7;
//int n;
//int a[2002];
//vector<PII> ans;
//vector<int> foo[2];
//
//void solve()
//{
//	cin >> n;
//	FOR(i, 0, 2*n)
//	{
//		cin >> a[i];
//		foo[a[i] % 2].PB(i+1);
//	}
//	while (ans.size() < n - 1)
//	{
//		FOR(i, 0, 2)
//		{
//			if (foo[i].size() > 1)
//			{
//				int x = foo[i].back();
//				foo[i].pop_back();
//				int y = foo[i].back();
//				foo[i].pop_back();
//				ans.PB(MP(x, y));
//			}
//		}
//	}
//	FOR(i, 0, n-1)
//	{
//		cout << ans[i].first << ' ' << ans[i].second << '\n';
//	}
//	ans.clear();
//	foo[0].clear();
//	foo[1].clear();
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		solve();
//	}
//	return 0;
//}
//
