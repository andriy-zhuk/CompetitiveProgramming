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
//int a[11];
//int len[11];
//int beg[11];
//int en[11];
//
//int dpT[1 << 10][10];
//
//int dp(int mask, int last)
//{
//	if (mask == (1 << n) - 1)
//		return 2;
//	if (dpT[mask][last] != -1)
//		return dpT[mask][last];
//	int best = 2;
//
//	FOR(i, 0, n)
//	{
//		if (mask & (1 << i))
//		{
//			continue;
//		}
//		if (en[last] == -1)
//			continue;
//		if (beg[i] == -1)
//			continue;
//		if (beg[i] != en[last])
//			continue;
//		best = max(best, dp(mask | (1 << i), i) + len[i] - 2);
//	}
//	return dpT[mask][last] = best;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n;
//	FOR(i, 0, n)
//	{
//		int x;
//		cin >> x;
//		a[i] = x;
//		VI foo;
//		foo.clear();
//		while (x)
//		{
//			foo.PB(x % 10);
//			len[i]++;
//			x /= 10;
//		}
//		if (a[i] == 0)
//		{
//			foo.PB(0);
//			len[i] = 1;
//		}
//		reverse(ALL(foo));
//
//		x = a[i];
//		beg[i] = -1;
//		if (foo.size() >= 2)
//		{
//			beg[i] = foo[0] * 10 + foo[1];
//		}
//		en[i] = -1;
//		if (foo.size() >= 2)
//		{
//			en[i] = a[i] % 100;
//		}
//	}
//	FILL(dpT, -1);
//
//	int best = 0;
//	FOR(i, 0, n)
//	{
//		best = max(best, len[i]);
//		if (len[i] >= 2)
//			best = max(best, dp(1 << i, i) + len[i] - 2);
//	}cout << best << endl;
//	
//
//
//	return 0;
//}
//
