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
//
//namespace FEN
//{
//	vector<int> t;
//	int n;
//
//	void init(int nn)
//	{
//		n = nn;
//		t.assign(n, 0);
//	}
//
//	int sum(int r)
//	{
//		int result = 0;
//		for (; r >= 0; r = (r & (r + 1)) - 1)
//			result += t[r];
//		return result;
//	}
//
//	void inc(int i, int delta)
//	{
//		for (; i < n; i = (i | (i + 1)))
//			t[i] += delta;
//	}
//
//	int sum(int l, int r)
//	{
//		return sum(r) - sum(l - 1);
//	}
//}
//
//int n;
//int a[400005];
//int b[400005];
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
//	}
//	FOR(i, 0, n)
//	{
//		cin >> b[i];
//		a[i] -= b[i];
//	}
//	vector<PII> foo;
//	FOR(i, 0, n)
//	{
//		foo.PB(MP(a[i], i));
//		foo.PB(MP(-a[i], i + n));
//	}
//	sort(ALL(foo));
//	int ii = 0;
//	FOR(i, 0, 2*n)
//	{
//		if (i && foo[i].first != foo[i - 1].first)
//			ii++;
//		a[foo[i].second] = ii;
//	}
//	FEN::init(foo.size()+10);
//	LL ans = 0;
//	FOR(i, 0, n)
//	{
//		ans += FEN::sum(a[i+n] + 1, FEN::n-1);
//		FEN::inc(a[i], 1);
//	}
//	cout << ans << endl;
//
//
//	return 0;
//}
//
