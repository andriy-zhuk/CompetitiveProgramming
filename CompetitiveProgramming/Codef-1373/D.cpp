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
//int a[200005];
//LL f[200005];
//LL pref[200005];
//void solve()
//{
//	cin >> n;
//	LL ans = 0;
//	FOR(i, 0, n)
//	{
//		cin >> a[i];
//		if (i % 2 == 0)
//		{
//			ans += a[i];
//			f[i] = a[i];
//		}
//		else
//		{
//			f[i] = -a[i];
//		}
//		pref[i] = f[i];
//		if (i)
//			pref[i] += pref[i - 1];
//	}
//	LL best = 0;
//	LL c0 = 0;
//	LL c1 = pref[0];
//	FOR(i, 1, n)
//	{
//		if (i % 2)
//		{
//			best = min(best, pref[i] - c0);
//			c0 = max(c0, pref[i]);
//		}
//		else
//		{
//			best = min(best, pref[i] - c1);
//			c1 = max(c1, pref[i]);
//		}
//	}
//	ans -= best;
//	cout << ans << endl;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	int t;
//	cin >> t;
//
//	while (t--)
//	{
//		solve();
//	}
//	return 0;
//}
//
