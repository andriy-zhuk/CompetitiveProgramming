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
//using namespace std;
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
//
//LL dp[2][2000006];
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	dp[0][1] = 0;
//	dp[1][1] = 0;
//	dp[0][2] = 0;
//	dp[1][2] = 0;
//
//	dp[0][3] = 0;
//	dp[1][3] = 1;
//
//	dp[0][4] = 1;
//	dp[1][4] = 1;
//
//	FOR(i, 5, 2000006)
//	{
//		dp[0][i] = 1LL * max(dp[0][i - 2], dp[1][i - 2]) * 2 % MOD;
//		dp[0][i] += max(dp[0][i - 1], dp[1][i - 1]);
//		dp[0][i] %= MOD;
//		dp[1][i] = 1 + 1LL * dp[0][i - 2] * 2 % MOD;
//		dp[1][i] %= MOD;
//		dp[1][i] += dp[0][i - 1];
//		dp[1][i] %= MOD;
//	}
//	
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int x;
//		cin >> x;
//		cout << max(dp[1][x], dp[0][x]) * 4 % MOD << endl;
//	}
//	return 0;
//}
//
