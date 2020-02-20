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
//int n, a, b, k;
//int m[200005];
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n >> a >> b >> k;
//	FOR(i, 0, n)
//	{
//		int x;
//		cin >> x;
//		int y = 0;
//		if (x % (a + b) <= a)
//		{
//			if (x % (a + b) == 0)
//			{
//				y = (a + b + a - 1) / a - 1;
//			}
//			else
//			{
//				y = 0;
//			}
//		}
//		else
//		{
//			y = (x % (a + b) + a - 1) / a - 1;
//		}
//		m[i] = y;
//		
//	}
//	sort(m, m + n);
//	int ans = 0;
//	FOR(i, 0, n)
//	{
//		if (k >= m[i])
//		{
//			ans++;
//			k -= m[i];
//		}
//	}
//	cout << ans << endl;
//
//	return 0;
//}
//
