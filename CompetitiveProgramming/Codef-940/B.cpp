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
//LL n, k, A, B;
//
//LL solve(LL x, int y)
//{
//	if (y == 0)
//	{
//		return (x-1) * A;
//	}
//	if (x == 1)
//	{
//		return 0;
//	}
//	if (x % k == 0)
//	{
//		return solve(x/k, y - 1) + B;
//	}
//	return solve(x - x % k, y) + (x % k) * A;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n >> k >> A >> B;
//	if (n == 1)
//	{
//		cout << 0 << endl;
//		return 0;
//	}
//	if (k == 1)
//	{
//		cout << 1LL * (n-1) * A << endl;
//		return 0;
//	}
//	LL best = LINF;
//	FOR(i, 0, 32)
//	{
//		best = min(best, solve(n, i));
//	}
//	cout << best << endl;
//
//	return 0;
//}
//
