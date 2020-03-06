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
//typedef vector<int> VI;
//
//const int INF = 1000 * 1000 * 1000;
//const LL LINF = 1LL * INF * INF;
//const int MAX = 100010;
//const long double PI = acos(-1.);
//const double EPS = 1e-6;
//const LL MOD = INF + 7;
//int n, p, k;
//
//struct player
//{
//	int b;
//	vector<int> p;
//	bool operator<(const player& p)
//	{
//		return b < p.b;
//	}
//
//};
//player a[100005];
//
//int popcount(int x)
//{
//	int ans = 0;
//	FOR(i, 0, p)
//	{
//		if ((1 << i) & x)
//			ans++;
//	}
//	return ans;
//}
//
//
//LL dpT[100005][1 << 7];
//
//LL dp(int pos, int mask)
//{
//	if (pos == n)
//	{
//		return 0;
//	}
//	if (dpT[pos][mask] != -1)
//	{
//		return dpT[pos][mask];
//	}
//	LL cur = -LINF;
//	if (pos - popcount(mask) < k)
//	{
//		cur = max(cur, a[pos].b + dp(pos + 1, mask));
//	}
//	else
//	{
//		cur = max(cur, dp(pos + 1, mask));
//	}
//	FOR(i, 0, p)
//	{
//		if (mask & (1 << i))
//			continue;
//		cur = max(cur, dp(pos + 1, mask | (1 << i)) + a[pos].p[i]);
//	}
//	return dpT[pos][mask] = cur;
//}
//
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n >> p >> k;
//	FOR(i, 0, n)
//	{
//		cin >> a[i].b;
//	}
//	FOR(i, 0, n)
//	{
//		FOR(j, 0, p)
//		{
//			int x;
//			cin >> x;
//			a[i].p.PB(x);
//		}
//	}
//	sort(a, a + n);
//	reverse(a, a + n);
//	FILL(dpT, -1);
//	
//	cout << dp(0,0)<< endl;
//
//	return 0;
//}
//
