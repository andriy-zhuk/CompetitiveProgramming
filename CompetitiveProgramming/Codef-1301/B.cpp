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
//const int MAX = 100010;
//const long double PI = acos(-1.);
//const double EPS = 1e-6;
//const LL MOD = INF + 7;
//
//int n;
//int a[200005];
//
//
//void solve()
//{
//	cin >> n;
//	int best = 0;
//	FOR(i, 0, n)
//	{
//		cin >> a[i];
//	}
//	FOR(i, 0, n - 1)
//	{
//		if (a[i] != -1 && a[i + 1] != -1)
//		{
//			best = max(best, abs(a[i + 1] - a[i]));
//		}
//	}
//	vector<int> foo;
//	FOR(i, 0, n)
//	{
//		if (a[i] == -1)
//			continue;
//		if ((i && a[i - 1] == -1) || (i != n - 1 && a[i + 1] == -1))
//			foo.PB(a[i]);
//	}
//	if (foo.size() == 0)
//	{
//		cout << 0 << ' ' << 0 << endl;
//		return;
//	}
//	sort(ALL(foo));
//	int k = abs(foo[0] + foo.back())/2;
//	best = max(best, abs(foo[0] - k));
//	best = max(best, abs(foo.back() - k));
//	cout << best << ' ' << k << endl;
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
