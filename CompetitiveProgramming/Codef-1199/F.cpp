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
//int pref[55][55];
//int a[55][55];
//int n;
//int dp[55][55][55][55];
//
//int rect(int x1, int y1, int x2, int y2)
//{
//	int anton = pref[x2][y2];
//	if (x1)
//		anton -= pref[x1 - 1][y2];
//	if (y1)
//		anton -= pref[x2][y1 - 1];
//	if (x1 && y1)
//		anton += pref[x1 - 1][y1 - 1];
//	return anton;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	
//	cin >> n;
//	FOR(i, 0, n)
//	{
//		string s;
//		cin >> s;
//		FOR(j, 0, n)
//		{
//			if (s[j] == '#')
//			{
//				a[i][j] = 1;
//			}
//		}
//	}
//	FOR(i, 0, n)
//	{
//		FOR(j, 0, n)
//		{
//			pref[i][j] = a[i][j];
//			if (i)
//				pref[i][j] += pref[i - 1][j];
//			if (j)
//				pref[i][j] += pref[i][j - 1];
//			if (i && j)
//				pref[i][j] -= pref[i - 1][j - 1];
//		}
//	}
//	if (n == 1)
//	{
//		cout << pref[0][0] << endl;
//		return 0;
//	}
//
//	FOR(dx, 0, n)
//	{
//		FOR(dy, 0, n)
//		{
//			FOR(x1,0,n-dx)
//			{
//				FOR(y1, 0, n-dy)
//				{
//					int x2 = x1 + dx;
//					int y2 = y1 + dy;
//
//					int cur = dp[x1][y1][x2][y2];
//					cur = max(x2 - x1 + 1, y2 - y1 + 1);
//					if (rect(x1, y1, x2, y2) == 0)
//						cur = min(cur, 0);
//					FOR(k, x1, x2+1)
//					{
//						if (rect(k, y1, k, y2) == 0)
//						{
//							int val = 0;
//							if (k)
//								val += dp[x1][y1][k - 1][y2];
//							if (k != n - 1)
//								val += dp[k + 1][y1][x2][y2];
//							cur = min(cur, val);
//						}
//					}
//					FOR(k, y1, y2 + 1)
//					{
//						if (rect(x1, k, x2, k) == 0)
//						{
//							int val = 0;
//							if (k)
//								val += dp[x1][y1][x2][k - 1];
//							if (k != n - 1)
//								val += dp[x1][k + 1][x2][y2];
//							cur = min(cur, val);
//						}
//					}
//					dp[x1][y1][x2][y2] = cur;
//				}
//			}
//		}
//	}
//	cout << dp[0][0][n - 1][n - 1] << endl;
//
//
//
//
//	
//	return 0;
//}
//
///*
//3
//#.#
//...
//...
//
//
//*/