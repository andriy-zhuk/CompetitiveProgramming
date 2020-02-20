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
//int a[1000006];
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0); cout.tie(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	
//	cin >> n;
//	FOR(i, 0, n)
//	{
//		cin >> a[i];
//	}
//	vector<pair<double, int> > foo;
//	foo.reserve(1000006);
//	foo.PB(MP(a[0], 1));
//
//	FOR(i, 1, n)
//	{
//		foo.PB(MP(a[i],1));
//		while (foo.size() > 1 && foo.back().first - foo[foo.size()-2].first < 1e-9)
//		{
//			double x = foo.back().first;
//			int y = foo.back().second;
//			foo.pop_back();
//			double l = foo.back().first;
//			int m = foo.back().second;
//			foo.pop_back();
//			x = x * y + l * m;
//			y += m;
//			x /= y;
//			foo.PB(MP(x, y));
//		}
//	}
//	if (n == 1000000)
//	{
//	//	cout << "KKAK" << endl;
//		//	return 0;
//	}
//
//	int k = 0;
//	FOR(i, 0, foo.size())
//	{
//		k += foo[i].second;
//	}
//	if (k != n)
//	{
//		return -1;
//	}
//	cout << fixed << setprecision(9);
//	FOR(i, 0, foo.size())
//	{
//		FOR(j, 0, foo[i].second)
//		{
//			cout << foo[i].first << endl;;
//		}
//	}
//
//
//
//	return 0;
//}
//
