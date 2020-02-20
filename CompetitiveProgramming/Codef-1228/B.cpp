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
//const LL MOD = INF + 7;
//
//int n, m;
//int a[1004][1004];
//
//LL binpow(LL x, LL n)
//{
//	LL res = 1;
//	while (n)
//	{
//		if (n % 2)
//		{
//			res = (res * x)%MOD;
//		}
//		x = (x * x) % MOD;
//		n /= 2;
//	}
//	return res;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n >> m;
//	FOR(i, 0, n)
//	{
//		int x;
//		cin >> x;
//		FOR(j, 0, min(x+1, m))
//		{
//			a[i][j] = 1 + (j == x);
//		}
//	}
//	FOR(j, 0, m)
//	{
//		int x;
//		cin >> x;
//		FOR(i, 0, min(n, x+1))
//		{
//			if (i == x)
//			{
//				if (a[i][j] == 1)
//				{
//					cout << 0 << endl;
//					return 0;
//				}
//			}
//			else
//			{
//				if (a[i][j] == 2)
//				{
//					cout << 0 << endl;
//					return 0;
//				}
//			}
//			a[i][j] = 1;
//		}
//	}
//	int cc = 0;
//	FOR(i, 0, n)
//	{
//		FOR(j, 0, m)
//		{
//			if (!a[i][j])
//				cc++;
//		}
//	}
//
//	cout << binpow(2, cc) << endl;
//
//	return 0;
//}
//
