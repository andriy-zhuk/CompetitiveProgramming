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
//int n;
//LL a[1000006];
//LL b[1000006];
//
//LL val[1000006];
//void solve()
//{
//	LL suma = 0;
//	cin >> n;
//	FOR(i, 0, n)
//	{
//		val[i] = 0;
//	}
//	FOR(i, 0, n)
//	{
//		suma -= a[i];
//		cin >> a[i];
//	}
//	FOR(i, 0, n)
//	{
//		suma += b[i];
//		cin >> b[i];
//	}
//	LL mn = LINF;
//
//	RFOR(i,n-1,0)
//	{
//		val[i] = val[i + 1] + b[i] - a[i + 1];
//		mn = min(mn, val[i]);
//	}
//	if (mn > 0)
//		mn = 0;
//	FOR(i, 0, n)
//	{
//		val[i] -= mn;
//	}
//	FOR(i, 0, n)
//	{
//		if (val[i] > b[i] || suma != 0)
//		{
//			cout << "NO" << '\n';
//			return;
//		}
//	}
//	cout << "YES" << '\n';
//}
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
