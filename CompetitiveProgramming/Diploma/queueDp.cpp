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
//int c[1005];
//int dp[1005];
//int r[1005];
//int n;
//
//int random(int l, int r)
//{
//	return rand() % (r - l+1) + l;
//}
//
//
//void init()
//{
//	r[1] = random(1, n);
//	for (int i = 2; i < n; ++i)
//	{
//		r[i] = random(r[i - 1], n);
//	}
//	for (int i = 1; i <= n; ++i)
//	{
//		c[i] = random(1, 512);
//	}
//}
//int dp2[1005];
//void brute()
//{
//	dp2[1] = c[1];
//	for (int i = 2; i <= n; ++i)
//	{
//		int val = 1000 * 1000 * 1000;
//		for (int j = 1; j < i; ++j)
//		{
//			if (i <= r[j])
//				val = min(val, dp2[j]);
//		}
//		if (val == 1e9)
//			val = 0;
//		dp2[i] = val + c[i];
//	}
//}
//
//void calculateDp()
//{
//	deque<pair<int, int> > q;
//	for (int k = 1; k <= n; ++k)
//	{
//		while ((not q.empty()) && q.front().second < k)
//		{
//			q.pop_front();
//		}
//		if (q.empty())
//		{
//			dp[k] = c[k];
//		}
//		else
//		{
//			dp[k] = q.front().first + c[k];
//		}
//		while ((not q.empty()) && q.back().first > dp[k])
//		{
//			q.pop_back();
//		}
//		q.push_back(make_pair(dp[k], r[k]));
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
//	for (int i = 1; i<1000; ++i)
//	{
//		if (dp[i] != dp2[i])
//		{
//			cout << "LOSHARA";
//		}
//	}
//}
