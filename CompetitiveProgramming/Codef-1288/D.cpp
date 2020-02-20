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
//const int INF = 1000 * 1000 * 1000+7;
//const LL LINF = 1LL * INF * INF;
//const int MAX = 100010;
//const long double PI = acos(-1.);
//const double EPS = 1e-6;
//const LL mod = INF + 7;
//int n, m;
//
//int a[300005][9];
//int b[300005][1 << 8];
//int pw[9] = { 1, 2, 4, 8, 16, 32, 64, 128, 256 };
//int rev(int x)
//{
//	return ((1 << m) - 1) ^ x;
//}
//
//int get(int i, int mask)
//{
//	int cur = INF;
//	FOR(j, 0, m)
//	{
//		if (mask & pw[j])
//			cur = min(cur, a[i][j]);
//	}
//	return cur;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	cin >> n >> m;
//	FOR(i, 0, n)
//	{
//		FOR(j, 0, m)
//		{
//			cin >> a[i][j];
//		}
//	}
//	FOR(i, 0, n)
//	{
//		int cur = INF;
//		FOR(k, 0, (1 << m))
//			b[i][k] = get(i, k);
//	}
//	pair<int, PII> best = MP(0, MP(0,0));
//	FOR(k, 0, (1 << m))
//	{
//		PII mn1 = MP(-INF, -1);
//		PII mn2 = MP(-INF, -1);
//		int l = rev(k);
//		FOR(i, 0, n)
//		{
//			mn1 = max(mn1, MP(b[i][k], i));
//			mn2 = max(mn2, MP(b[i][l], i));
//		}
//		best = max(best, MP(min(mn1.f, mn2.f), MP(mn1.second, mn2.second)));
//	}
//	cout << best.second.first+1 << ' ' << best.second.second+1 << endl;
//
//
//
//	return 0;
//}
//
