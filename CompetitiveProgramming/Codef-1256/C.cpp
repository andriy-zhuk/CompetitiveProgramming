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
//
//int n, m, d;
//int a[1002];
//int ans[1002];
//int p[1002];
//
//bool can()
//{
//	int x = 0;
//	x += d;
//	FOR(i, 0, m)
//	{
//		x += a[i]-1;
//		x += d;
//	}
//	return (x >= n);
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	cin >> n >> m >> d;
//	int suma = 0;
//	FOR(i, 0, m)
//	{
//		cin >> a[i];
//		suma += a[i];
//	}
//	if (!can())
//	{
//		cout << "NO" << endl;
//		return 0;
//	}
//	cout << "YES" << endl;
//	suma = n - suma+1;
//	int x = 0;
//	FOR(i, 0, m)
//	{
//		int y = min(suma, d);
//		x += y;
//		p[i] = x;
//		suma -= y-1;
//		x += a[i] - 1;
//	}
//
//	FOR(i, 0, m)
//	{
//		FOR(j, p[i], p[i] + a[i])
//		{
//			ans[j] = i + 1;
//		}
//	}
//	FOR(i, 1, n+1)
//	{
//		cout << ans[i] << ' ';
//	}
//	cout << endl;
//
//	return 0;
//}
//
