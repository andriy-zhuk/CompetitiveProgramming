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
//typedef vector<int> VI;
//
//const int INF = 1000 * 1000 * 100;
//const LL LINF = 1LL * INF * INF;
//const int MAX = 100010;
//const long double PI = acos(-1.);
//const double EPS = 1e-6;
//const LL MOD = INF + 7;
//int n;
//PII a[200005];
//
//namespace FEN
//{
//	int n;
//	pair<LL, LL> t[200005];
//	void init()
//	{
//		FILL(t, 0);
//	}
//	pair<LL, LL> sum(int r)
//	{
//		pair<LL, LL> result = MP(0,0);
//		for (; r >= 0; r = (r & (r + 1)) - 1)
//		{
//			result.first += t[r].first;
//			result.second += t[r].second;
//		}
//		return result;
//	}
//
//	void inc(int i, int delta)
//	{
//		for (; i < n; i = (i | (i + 1)))
//		{
//			t[i].first += delta;
//			t[i].second += 1;
//
//		}
//	}
//
//	pair<LL, LL> sum(int l, int r)
//	{
//		pair<LL, LL>  ans = sum(r);
//		pair<LL, LL> b = sum(l - 1);
//		ans.first -= b.first;
//		ans.second -= b.second;
//		return ans;
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	LL ans = 0;
//	cin >> n;
//	FOR(i, 0, n)
//	{
//		cin >> a[i].first;
//	}
//	FOR(i, 0, n)
//	{
//		cin >> a[i].second;
//	}
//	vector<PII> foo;
//	FOR(i, 0, n)
//	{
//		if (a[i].second >= 0)
//		{
//			foo.PB(MP(a[i].second, i));
//		}
//	}
//	sort(ALL(foo));
//	int j = 1;
//	FOR(i, 0, foo.size())
//	{
//		if (i && foo[i].first != foo[i - 1].first)
//		{
//			j++;
//		}
//		a[foo[i].second].second = j;
//	}
//	foo.clear();
//	j++;
//	FEN::n = j;
//	FEN::init();
//	sort(a, a+n);
//	
//	RFOR(i, n, 0)
//	{
//		if (a[i].second < 0)
//			continue;
//		pair<LL, LL> cur = FEN::sum(a[i].second, FEN::n-1); // suma, cnt
//		LL dst = INF - a[i].first;
//		ans += dst * cur.second - cur.first;
//		FEN::inc(a[i].second, dst);
//	}
//	LL cc = 0;
//	LL suma = 0;
//	FOR(i, 0, n)
//	{
//		LL dst = INF - a[i].first;
//		if (a[i].second < 0)
//		{
//			suma += dst;
//			cc++;
//		}
//		else
//		{
//			ans += suma - dst * cc;
//		}
//	}
//	FOR(i, 0, n)
//	{
//		a[i].second *= -1;
//	}
//	FOR(i, 0, n)
//	{
//		if (a[i].second > 0)
//		{
//			foo.PB(MP(a[i].second, i));
//		}
//	}
//	sort(ALL(foo));
//	j = 1;
//	FOR(i, 0, foo.size())
//	{
//		if (i && foo[i].first != foo[i - 1].first)
//		{
//			j++;
//		}
//		a[foo[i].second].second = j;
//	}
//	foo.clear();
//	j++;
//	FEN::n = j;
//	FEN::init();
//
//	FOR(i, 0, n)
//	{
//		if (a[i].second < 0)
//			continue;
//		pair<LL, LL> cur = FEN::sum(a[i].second, FEN::n - 1); // suma, cnt
//		LL dst = INF - a[i].first;
//		ans += cur.first - dst * cur.second;
//		FEN::inc(a[i].second, dst);
//	}
//	cout << ans << endl;
//
//
//	return 0;
//}
//
