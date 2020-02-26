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
//typedef vector<int> VI;
//
//const int INF = 1000 * 1000 * 1000;
//const LL LINF = 1LL * INF * INF;
//const int MAX = 100010;
//const long double PI = acos(-1.);
//const double EPS = 1e-6;
//const LL MOD = INF + 7;
//int a, b, c;
//
//
//
//void solve()
//{
//	cin >> a >> b >> c;
//	pair<int, pair<PII, int> > best = MP(b - a + c - b, MP(MP(b,b), b));
//	int n = 15 * 1000;
//	for (int A = 1; A <= n; ++A)
//	{
//		for (int k = 1; k <= n / A; ++k)
//		{
//			for (int j = 1; j <= n / A / k; ++j)
//			{
//				int B = A * k;
//				int C = B * j;
//				int val = abs(a - A) + abs(b - B) + abs(c - C);
//				best = min(best, MP(val, MP(MP(A, B), C)));
//			}
//		}
//	}
//
//	cout << best.first << endl;
//	cout << best.second.first.first << ' ' << best.second.first.second << ' ' << best.second.second << endl;
//}
//
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
