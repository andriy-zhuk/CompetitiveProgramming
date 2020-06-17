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
//LL dp[1005];
//
//LL matr[4][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {3, 2, 1} };
//void init()
//{
//	dp[0] = 4;
//	dp[1] = 7;
//	dp[2] = 47;
//}
//void brute(int n)
//{
//	init();
//	FOR(i, 3, n + 1)
//	{
//		dp[i] = 1 * dp[i - 1] + 2 * dp[i - 2] + 3 * dp[i - 3];
//		dp[i] %= MOD;
//	}
//}
//
//struct vec
//{
//	LL a[3];
//	void copy(const vec& v)
//	{
//		FOR(i, 0, 3)
//		{
//			a[i] = v.a[i];
//		}
//	}
//};
//
//void mult(vec& a, const vec& b)
//{
//	LL c[20];
//	FILL(c, 0);
//	FOR(i, 0, 3)
//	{
//		FOR(j, 0, 3)
//		{
//			c[i + j] = (c[i + j] + (a.a[i] * b.a[j]) % MOD) % MOD;
//		}
//	}
//	RFOR(i, 9, 3)
//	{
//		c[i - 1] += 1 * c[i];
//		c[i - 2] += 2 * c[i];
//		c[i - 3] += 3 * c[i];
//		c[i - 1] %= MOD;
//		c[i - 2] %= MOD;
//		c[i - 3] %= MOD;
//		c[i] = 0;
//	}
//	a.a[0] = c[0];
//	a.a[1] = c[1];
//	a.a[2] = c[2];
//}
//
//vec a, b, c;
//
//void binpow(int n) // in a, out b;
//{
//	int pw = 1;
//
//	while (n)
//	{
//		if (pw <= 3)
//		{
//			FOR(i, 0, 3)
//			{
//				a.a[i] = matr[pw][i];
//			}
//		}
//		pw *= 2;
//		if (n % 2)
//		{
//			mult(b, a);
//		}
//		c.copy(a);
//		mult(a, c);
//		n /= 2;
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	int x;
//	x = 1;
//	brute(100);
//	b.a[0] = 1;
//	b.a[1] = 0;	
//	b.a[2] = 0;
//	binpow(x);
//	LL cur = b.a[2]*dp[2]%MOD + b.a[1] * dp[1]%MOD + b.a[0]*dp[0]%MOD;
//	cur %= MOD;
//	FOR(i, 0, 100)
//	{
//		if (dp[i] == cur)
//		{
//			cout << i << endl;
//		}
//	}
//	cout << dp[x] << ' ' << cur << endl;
//
//	return 0;
//}
//
