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
//LL m[1005][1005];
//LL a[1004];
//bool ok(int x)
//{
//	a[0] = x;
//	FOR(i, 1, n)
//	{
//		if (m[i][0] % x != 0)
//			return 0;
//		a[i] = m[i][0] / x;
//	}
//	FOR(i, 0, n)
//	{
//		FOR(j, 0, n)
//		{
//			if (i == j)
//				continue;
//			if (m[i][j] != 1LL*a[i] * a[j])
//				return 0;
//		}
//	}
//	return 1;
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
//		FOR(j, 0, n)
//		{
//			cin >> m[i][j];
//		}
//	}
//
//	int x = m[0][1];
//	for (LL i = 1; i * i <= x; ++i)
//	{
//		if (x % i != 0)
//			continue;
//		if (ok(i))
//		{
//			a[0] = i;
//			FOR(i, 1, n)
//			{
//				a[i] = m[i][0] / a[0];
//			}
//			FOR(i, 0, n)
//			{
//				cout << a[i] << ' ';
//			}
//			cout << endl;
//			return 0;
//		}
//		if (ok(x/i))
//		{
//			a[0] = x/i;
//			FOR(i, 1, n)
//			{
//				a[i] = m[i][0] / a[0];
//			}
//			FOR(i, 0, n)
//			{
//				cout << a[i] << ' ';
//			}
//			cout << endl;
//			return 0;
//		}
//	}
//
//	return 0;
//}