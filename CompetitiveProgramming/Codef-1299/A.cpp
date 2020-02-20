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
//int n;
//int a[200005];
//int ober[200005];
//int ps[200005];
//int ss[200005];
//
//int get(int x)
//{
//	int cur = 0;
//	FOR(i, 0, 31)
//	{
//		if (x & (1 << i));
//		else
//			cur |= (1 << i);
//	}
//	return cur;
//}
//
//int calc(int i)
//{
//	int cur = a[i];
//	if (i)
//		cur &= ps[i - 1];
//	if (i != n - 1)
//		cur &= ss[i + 1];
//	return cur;
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
//		cin >> a[i];
//		ober[i] = get(a[i]);
//	}
//	if (n == 1)
//	{
//		cout << a[0] << endl;
//		return 0;
//	}
//
//	FOR(i, 0, n)
//	{
//		ps[i] = ober[i];
//		if (i)
//			ps[i] &= ps[i - 1];
//	}
//
//	RFOR(i, n, 0)
//	{
//		ss[i] = ober[i];
//		if (i != n - 1)
//			ss[i] &= ss[i + 1];
//	}
//	PII best = MP(0,0);
//	FOR(i, 0, n)
//	{
//		best = max(best, MP(calc(i),i));
//	}
//	
//	cout << a[best.second] << ' ';
//	FOR(i, 0, n)
//	{
//		if (i != best.second)
//		{
//			cout << a[i] << ' ';
//		}
//	}
//	cout << endl;
//
//	return 0;
//}
//
