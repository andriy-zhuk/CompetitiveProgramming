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
//int n;
//int a[202];
//
//int f(int x)
//{
//	x++;
//	int cur = 0;
//	FOR(i, 0, n)
//	{
//		cur += a[i] / x;
//	}
//	return cur;
//}
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
//	}
//
//	int l = 0;
//	int r = INF+7;
//
//	while (abs(r - l) > 1)
//	{
//		int m = (1LL * r + l) / 2;
//		if (f(m) >= 8)
//		{
//			l = m+1;
//		}
//		else
//		{
//			r = m;
//		}
//	}
//	if (l > r)
//		swap(l, r);
//	if (f(l)< 8)
//	{
//		cout << l << endl;
//	}
//	else
//	{
//		cout << r << endl;
//	}
//
//
//	return 0;
//}
//
