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
//const int INF = 1000 * 1000 * 1000 + 7;
//const LL LINF = 1LL * INF * INF;
//const int MAX = 300005;
//const long double PI = acos(-1.);
//const double EPS = 1e-6;
//const LL mod = INF + 7;
//
//namespace FEN
//{
//	vector<int> t(100005, INF);
//	int n = 100005;
//
//	int getmin(int r)
//	{
//		int result = INF;
//		for (; r >= 0; r = (r & (r + 1)) - 1)
//		{
//			result = min(result, t[r]);
//		}
//		return result;
//	}
//
//	void update(int i, int new_val)
//	{
//		for (; i < n; i = (i | (i + 1)))
//		{
//			t[i] = min(t[i], new_val);
//		}
//	}
//};
//
//
//int a[300005];
//int n;
//int c[300005];
//
//vector<int> foo;
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n;
//	FOR(i, 0, n)
//	{
//		cin >> a[i];
//		a[i + n] = a[i];
//		a[i + 2 * n] = a[i];
//		foo.PB(a[i]);
//	}
//	sort(ALL(foo));
//	n *= 3;
//	c[n - 1] = 1;
//	RFOR(i, n - 1, 0)
//	{
//		if (a[i] <= a[i + 1])
//		{
//			c[i] = c[i + 1] + 1;
//		}
//		else
//		{
//			int p = upper_bound(ALL(foo), (a[i] + 1) / 2 - 1)-foo.begin()-1;
//			int x = FEN::getmin(p);
//			if (x == INF)
//			{
//				c[i] = n - i;
//			}
//			else
//			{
//				c[i] = x - i;
//			}
//			c[i] = min(c[i], c[i + 1] + 1);
//		}
//		int p = lower_bound(ALL(foo), a[i])- foo.begin();
//		FEN::update(p, i);
//	}
//
//	n /= 3;
//	FOR(i, 0, n)
//	{
//		if (c[i] >= 2*n)
//		{
//			c[i] = -1;
//		}
//		cout << c[i] << " ";
//	}
//	return 0;
//}
//
