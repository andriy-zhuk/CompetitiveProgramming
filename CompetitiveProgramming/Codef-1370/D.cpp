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
//int n, k;
//vector<int> a;
//
//bool ok(int x)
//{
//	bool flag = true;
//	int cnt;
//	cnt = 0;
//	flag = true;
//	FOR(i, 0, n)
//	{
//		if (flag)
//		{
//			if (a[i] > x)
//				continue;
//			flag = !flag;
//			cnt++;
//		}
//		else
//		{
//			flag = !flag;
//			cnt++;
//		}
//	}
//	if (cnt >= k)
//	{
//		return true;
//	}
//	cnt = 0;
//	flag = true;
//	FOR(i, 0, n)
//	{
//		if (flag)
//		{
//			flag = !flag;
//			cnt++;
//		}
//		else
//		{
//			if (a[i] > x)
//				continue;
//			flag = !flag;
//			cnt++;
//		}
//	}
//	if (cnt >= k)
//	{
//		return true;
//	}
//	return false;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n >> k;
//	FOR(i, 0, n)
//	{
//		int x;
//		cin >> x;
//		a.PB(x);
//	}
//	vector<int> foo = a;
//	sort(ALL(foo));
//
//	int l = 0;
//	int r = n - 1;
//	while (abs(r - l) > 1)
//	{
//		int m = (r + l) / 2;
//		if (ok(foo[m]))
//		{
//			r = m;
//		}
//		else
//		{
//			l = m + 1;
//		}
//	}
//	if (l > r)
//		swap(l, r);
//	if (ok(foo[l]))
//	{
//		cout << foo[l] << endl;
//	}
//	else
//	{
//		cout << foo[r] << endl;
//	}
//
//
//	return 0;
//}
//
