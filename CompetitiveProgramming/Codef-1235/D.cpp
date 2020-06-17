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
//LL u, v;
//
//void calc()
//{
//	LL a = 0, b = 0, uu = u, vv = v;
//	RFOR(i, 61, 0)
//	{
//		if (uu & (1LL << i))
//		{
//			a += 1LL << i;
//			vv -= 1LL << i;
//			continue;
//		}
//		if (vv < 1LL << (i + 1))
//		{
//			continue;
//		}
//		else
//		{
//			vv -= 1LL << (i + 1);
//			a += 1LL << i;
//			b += 1LL << i;
//		}
//	}
//	if (a + b == v && (a ^ b) == u)
//	{
//		cout << 2 << endl << a << ' ' << b << endl;
//		exit(0);
//	}
//}
//
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> u >> v;
//	if (v < u || u % 2 != v % 2)
//	{
//		cout << -1 << endl;
//		return 0;
//	}
//	if (u == 0)
//	{
//		if (v == 0)
//		{
//			cout << 0 << endl;
//		}
//		else
//		{
//			calc();
//			cout << -1 << endl;
//		}
//		return 0;
//	}
//	if (v == u)
//	{
//		cout << 1 << endl << v << endl;
//		return 0;
//	}
//	calc();
//	LL x = v - u;
//	x /= 2;
//	cout << 3 << endl;
//	cout << u << ' ' << x << ' ' << x << endl;
//
//
//	return 0;
//}
//
