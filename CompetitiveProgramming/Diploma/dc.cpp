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
//const int MOD = 10007;
//
//int c[1005][1005];
//int dp[1005][1005];
//int a[1005][1005];
//int r[1005];
//int n;
//
//int random(int l, int r)
//{
//	return rand() % (r - l + 1) + l;
//}
//
//
//void init()
//{
//	int mx = 100;
//	for (int i = 1; i <= n; ++i)
//	{
//		r[i] = random(r[i - 1], mx);
//		mx++;
//	}
//	for (int i = 1; i <= n; ++i)
//	{
//		for (int j = i+1; j <= n; ++j)
//		{
//			c[i][j] = r[j] - r[i];
//		}
//	}
//}
//
//int dp2[1005][1005];
//void brute()
//{
//	for (int i = 1; i <= n; ++i)
//	{
//		dp2[1][i] = c[1][i];
//	}
//	for (int i = 2; i <= n; ++i)
//	{
//		for (int j = 1; j <= n; ++j)
//		{
//			int best = 1000 * 1000 * 1000;
//			for (int k = 1; k <= j; ++k)
//			{
//				best = min(best, dp2[i - 1][k] + c[k][j]);
//			}
//			dp2[i][j] = best;
//		}
//	}
//}
//
//
//void dnc(int _i, int l, int r, int al, int ar)
//{
//	if (l > r)
//		return;
//	int m = (l + r)/2;
//	dp[_i][m] = 1000*1000*1000;
//	a[_i][m] = -1;
//
//	for (int i = max(al, a[_i-1][m]); i <= min(m, ar); ++i)
//	{
//		int cur = dp[_i - 1][i] + c[i][m];
//		if (dp[_i][m] > cur)
//		{
//			dp[_i][m] = cur;
//			a[_i][m] = i;
//		}
//	}
//	dnc(_i, l, m - 1, al, a[_i][m]);
//	dnc(_i, m + 1, r, a[_i][m], ar);
//}
//
//void calculateDp()
//{
//	for (int i = 1; i <= n; ++i)
//	{
//		dp[1][i] = c[1][i];
//	}
//	for (int i = 2; i <= n; ++i)
//	{
//		dnc(i, 1, n, 1, n);
//	}
//}
//
//
//
//
//int main()
//{
//	n = 1000;
//	init();
//	brute();
//	calculateDp();
//	
//	for (int i = 1; i <= n; ++i)
//	{
//		for (int j = 1; j <= n; ++j)
//		{
//			if (dp[i][j] != dp2[i][j])
//			{
//				cout << i << ' ' << j << endl;
//				cout << dp[i][j] << ' ' << dp2[i][j] << endl;
//				cout << "LOSHARA" << endl;
//			}
//		}
//	}
//
//}
