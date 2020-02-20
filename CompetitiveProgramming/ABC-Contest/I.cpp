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
//int n, m;
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n >> m;
//	if (n == 1 && m == 1)
//	{
//		cout << 1 << ' ' << 1 << endl;
//		return 0;
//	}
//	if (n % 2 && m % 2)
//	{
//		cout << -1 << endl;
//		return 0;
//	}
//	if (n == 1 || m == 1)
//	{
//		cout << -1 << endl;
//		return 0;
//	}
//
//	cout << 1 << ' ' << 1 << endl;
//
//	if (n % 2 == 0)
//	{
//		cout << "R";
//		FOR(i, 0, n/2)
//		{
//			FOR(j, 0, m - 2)
//			{
//				cout << "R";
//			}
//			cout << "D";
//			FOR(j, 0, m - 2)
//			{
//				cout << "L";
//			}
//			if (i != n / 2-1)
//			{
//				cout << "D";
//			}
//		}
//		cout << "L";
//		FOR(i, 0, n-1)
//		{
//			cout << "U";
//		}
//		cout << endl;
//		return 0;
//	}
//
//	if (m % 2 == 0)
//	{
//		swap(n, m);
//		cout << "D";
//		FOR(i, 0, n / 2)
//		{
//			FOR(j, 0, m - 2)
//			{
//				cout << "D";
//			}
//			cout << "R";
//			FOR(j, 0, m - 2)
//			{
//				cout << "U";
//			}
//			if (i != n / 2-1)
//			{
//				cout << "R";
//			}
//		}
//		cout << "U";
//		FOR(i, 0, n - 1)
//		{
//			cout << "L";
//		}
//		cout << endl;
//	}
//
//
//
//	return 0;
//}
//
