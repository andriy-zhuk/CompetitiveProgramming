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
//int n;
//LL dpT[200005];
//int nxt[200005];
//pair<LL, int> a[200005];
//int ans[200005];
//LL dp(int p)
//{
//	if (p == n)
//	{
//		return 0;
//	}
//	if (p >= n - 2)
//	{
//		return LINF;
//	}
//	if (dpT[p] != -1)
//		return dpT[p];
//
//	pair<LL, int> best = MP(LINF, -1);
//	FOR(i, p+3, min(p+6, n)+1)
//	{
//		best = min(best, MP(dp(i) + (a[i-1].first - a[p].first), i));
//	}
//	nxt[p] = best.second;
//	return dpT[p] = best.first;
//}
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	cin >> n;
//	FOR(i, 0, n)
//	{
//		cin >> a[i].first;
//		a[i].second = i;
//	}
//	sort(a, a + n);
//
//	FILL(dpT, -1);
//	FILL(nxt, -1);
//
//	cout << dp(0);
//
//	int cur = 0;
//	int step = 1;
//	while (cur != n)
//	{
//		int y = nxt[cur];
//		FOR(i, cur, y)
//		{
//			ans[a[i].second] = step;
//		}
//		step++;
//		cur = y;
//	}
//	cout << ' ' <<  step-1 << endl;
//
//	FOR(i, 0, n)
//	{
//		cout << ans[i] << " ";
//	}
//	cout << endl;
//
//	return 0;
//}
//
