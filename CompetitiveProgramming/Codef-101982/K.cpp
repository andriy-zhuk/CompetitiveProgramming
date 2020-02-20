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
//
//vector<int> a[13][1 << 9];
//long double val[1 << 9];
//string val2[1 << 9];
//void prec()
//{
//	FOR(sum, 1, 13)
//	{
//		FOR(mask, 0, 1 << 9)
//		{
//			int s = mask;
//			while (s > 0) {
//				int suma = 0;
//				FOR(j, 0, 9)
//				{
//					if (s & (1 << j))
//					{
//						suma += j + 1;
//					}
//				}
//				if (suma == sum)
//				{
//					a[sum][mask].PB(s);
//				}
//				s = (s - 1) & mask;
//			}
//		}
//	}
//	FOR(mask, 0, 1 << 9)
//	{
//		string s = "";
//		FOR(j, 0, 9)
//		{
//			if (mask & (1 << j))
//			{
//				s += char('1' + j);
//			}
//		}
//		val2[mask] = s;
//		val[mask] = (long double)atoi(s.c_str());
//	}
//
//}
//
//
//namespace mx
//{
//	long double dpT[1 << 9];
//
//	long double dp(int mask)
//	{
//		if (mask == 0)
//		{
//			return 0;
//		}
//		if (dpT[mask] != -1.0)
//			return dpT[mask];
//		long double res = 0;
//		FOR(i, 1, 7)
//		{
//			FOR(j, 1, 7)
//			{
//				long double cur = -1e9;
//				if (a[i + j][mask].size() != 0)
//				{
//					FOR(k, 0, a[i + j][mask].size())
//					{
//						cur = max(cur, dp(a[i + j][mask][k] ^ mask));
//					}
//				}
//				else
//				{
//					cur = max(cur, val[mask]);
//				}
//				if (cur != -1e9)
//					res += cur;
//			}
//		}
//		return dpT[mask] = res/36.0;
//	}
//}
//
//namespace mn
//{
//	long double dpT[1 << 9];
//
//	long double dp(int mask)
//	{
//		if (mask == 0)
//		{
//			return 0;
//		}
//		if (dpT[mask] != -1.0)
//			return dpT[mask];
//		long double res = 0;
//		FOR(i, 1, 7)
//		{
//			FOR(j, 1, 7)
//			{
//				long double cur = 1e9;
//				if (a[i + j][mask].size() != 0)
//				{
//					FOR(k, 0, a[i + j][mask].size())
//					{
//						cur = min(cur, dp(a[i + j][mask][k] ^ mask));
//					}
//				}
//				else
//				{
//					cur = min(cur, val[mask]);
//				}
//				if (cur != 1e9)
//					res += cur;
//			}
//		}
//		return dpT[mask] = res / 36.0;
//	}
//}
//
//
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	prec();
//	string s;
//	int x, y;
//	cin >> s >> x >> y;
//	int mask = 0;
//	FOR(i, 0, s.size())
//	{
//		mask |= (1 << (s[i] - '1'));
//	}
//	pair<long double, int> best = MP(1e9, mask);
//
//	FOR(i, 0, 1 << 9)
//	{
//		mn::dpT[i] = -1.0;
//	}
//	FOR(i, 0, a[x + y][mask].size())
//	{
//		int m = a[x + y][mask][i];
//		best = min(best, MP(mn::dp(mask^m), m));
//	}
//
//	cout << fixed << setprecision(5);
//	if (best.first == 1e9)
//		cout << -1 << ' ' << val[best.second] << endl;
//	else
//		cout << val2[best.second] << ' ' << best.first << endl;
//
//
//	best = MP(-1e9, mask);
//
//	FOR(i, 0, 1 << 9)
//	{
//		mx::dpT[i] = -1.0;
//	}
//	FOR(i, 0, a[x + y][mask].size())
//	{
//		int m = a[x + y][mask][i];
//		best = max(best, MP(mx::dp(mask ^ m), m));
//	}
//
//	cout << fixed << setprecision(5);
//	if (best.first == -1e9)
//		cout << -1 << ' ' << val[best.second] << endl;
//	else
//		cout << val2[best.second] << ' ' << best.first << endl;
//	
//
//
//
//	return 0;
//}
//
