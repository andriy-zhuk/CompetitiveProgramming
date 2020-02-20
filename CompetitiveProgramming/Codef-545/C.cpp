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
//int a[200005];
//int h[200005];
//int n;
//int dpT[200005][3];
//int dp(int pos, int stan) // 0 = left, 1 stay, 2 right
//{
//	if (pos == n)
//		return 0;
//	if (dpT[pos][stan] != -1)
//		return dpT[pos][stan];
//
//	int cur = 0;
//	int r = a[pos] + h[pos];
//	int l = a[pos] - h[pos];
//
//	LL baned = -LINF;
//	if (pos)
//		baned = a[pos - 1];
//
//	if (stan == 2)
//	{
//		baned += h[pos - 1];
//	}
//	if (l > baned)
//	{
//		cur = max(cur, dp(pos + 1, 0) + 1);
//	}
//	cur = max(cur, dp(pos + 1, 1));
//	baned = LINF;
//	if (pos != n - 1)
//	{
//		baned = a[pos + 1];
//	}
//	if (r < baned)
//	{
//		cur = max(cur, dp(pos + 1, 2) + 1);
//	}
//	return dpT[pos][stan] = cur;
//}
//
//
//
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> a[i] >> h[i];
//	}
//	memset(dpT, -1, sizeof dpT);
//	cout << dp(0, 0) << endl;
//
//
//	return 0;
//}