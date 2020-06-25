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
//
//int n, k;
//void solve()
//{
//	cin >> n >> k;
//	vector<LL> a;
//	FOR(i, 0, n)
//	{
//		int x;
//		cin >> x;
//		a.PB(x);
//	}
//	vector<int> w;
//	FOR(i, 0, k)
//	{
//		int x;
//		cin >> x;
//		w.PB(x);
//	}
//	sort(ALL(a));
//	LL ans = 0;
//	sort(ALL(w));
//	reverse(ALL(w));
//	while (w.size())
//	{
//		int x = w.back();
//		if (x>2)
//		{
//			break;
//		}
//		w.pop_back();
//		if (x == 1)
//		{ 
//			ans += 1LL* a.back() * 2;
//			a.pop_back();
//			continue;
//		}
//		if (x == 2)
//		{
//			ans += a.back();
//			a.pop_back();
//			ans += a.back();
//			a.pop_back();
//		}
//	}
//	FOR(i, 0, w.size())
//	{
//		ans += a.back();
//		a.pop_back();
//		w[i]--;
//	}
//	while (w.size())
//	{
//		int x = w.back();
//		FOR(i, 0, x - 1)
//		{
//			a.pop_back();
//		}
//		ans += a.back();
//		a.pop_back();
//		w.pop_back();
//	}
//	cout << ans << endl;
//	return;
//}
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		solve();
//	}
//	return 0;
//}
//
