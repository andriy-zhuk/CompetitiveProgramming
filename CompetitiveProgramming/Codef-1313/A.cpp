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
//int a[3];
//int dpT[10][10][10][10];
//
//
//int dp(int pos, int a, int b, int c)
//{
//	if (pos == 8)
//	{
//		return 0;
//	}
//	if (dpT[pos][a][b][c] != -1)
//	{
//		return dpT[pos][a][b][c];
//	}
//	int best = dp(pos + 1, a, b, c);
//	if ((pos & 1) <= a  && ((pos>>1) & 1) <= b && ((pos>>2) & 1) <= c)
//	{
//		best = max(best, 1+dp(pos + 1, a - (pos & 1), b - ((pos >> 1) & 1), c - ((pos >> 2) & 1) ) );
//	}
//	return dpT[pos][a][b][c] = best;
//}
//
//
//void solve()
//{
//	cin >> a[0] >> a[1] >> a[2];
//	FILL(dpT, -1);
//	cout << dp(1, a[0], a[1], a[2]) << endl;;
//}
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
