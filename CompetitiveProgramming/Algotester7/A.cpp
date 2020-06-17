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
//pair<long double, long double> foo[10];
//
//long double calc(pair<long double, long double> x)
//{
//	long double cur = 0;
//	FOR(i, 0, n)
//	{
//		long double res = (x.first - foo[i].first) * (x.first - foo[i].first) + (x.second- foo[i].second) * (x.second - foo[i].second);
//		res = sqrt(res);
//		cur = max(cur, res);
//	}
//	return cur;
//}
//
//long double tern1(long double x)
//{
//	long double l = -1e3 - 10;
//	long double r = 1e3 + 10;
//
//	FOR(ii, 0, 60)
//	{
//		long double m1 = l + (r - l) / 3;
//		long double m2 = m1 + (r - l) / 3;
//
//		if (calc(MP(x, m1)) > calc(MP(x, m2)))
//		{
//			l = m1;
//		}
//		else
//		{
//			r = m2;
//		}
//	}
//	return calc(MP(x, l));
//}
//
//
//long double tern()
//{
//	long double l = -1e3-10;
//	long double r = 1e3+10;
//
//	FOR(ii, 0, 60)
//	{
//		long double m1 = l + (r - l) / 3;
//		long double m2 = m1 + (r - l) / 3;
//
//		if (tern1(m1) > tern1(m2))
//		{
//			l = m1;
//		}
//		else
//		{
//			r = m2;
//		}
//	}
//	return tern1(l);
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
//	n = 10;
//	FOR(i, 0, n)
//	{
//		cin >> foo[i].first >> foo[i].second;
//	}
//
//
//	cout << fixed << setprecision(5) << tern() << endl;
//
//
//
//	return 0;
//}
//
//
//
