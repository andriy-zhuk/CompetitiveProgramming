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
//int n;
//LL a[500005];
//
//
//vector<LL> calc()
//{
//	vector<LL> ret;
//	vector<pair<LL, LL> > foo;
//	foo.PB(MP(0, 1));
//	ret.PB(0);
//	LL cur = 0;
//	FOR(i, 0, n)
//	{
//		int x = a[i];
//		int cnt = 0;
//		while (foo.size() && foo.back().first >= a[i])
//		{
//			pair<LL, LL> tod = foo.back();
//			cnt += tod.second;
//			cur -= tod.second * tod.first;
//			foo.pop_back();
//		}
//		cnt++;
//		cur += cnt * a[i];
//		ret.PB(cur);
//		foo.PB(MP(a[i], cnt));
//	}
//	return ret;
//}
//
//vector<LL> calc2(int n)
//{
//	vector<LL> ret;
//	vector<pair<LL, LL> > foo;
//	foo.PB(MP(0, 1));
//	FOR(i, 0, n)
//	{
//		int x = a[i];
//		int cnt = 0;
//		while (foo.size() && foo.back().first >= a[i])
//		{
//			pair<LL, LL> tod = foo.back();
//			cnt += tod.second;
//			foo.pop_back();
//		}
//		cnt++;
//		foo.PB(MP(a[i], cnt));
//	}
//	FOR(i, 0, foo.size())
//	{
//		FOR(j, 0, foo[i].second)
//			ret.PB(foo[i].first);
//	}
//	return ret;
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
//	vector<LL> pr = calc();
//	reverse(a, a + n);
//	vector<LL> sf = calc();
//	pair<LL, int> best = MP(0,0);
//	FOR(i, 0, pr.size())
//	{
//		best = max(best, MP(pr[i] + sf[(int)pr.size() - i - 1], i));
//	}
//	
//	int x = best.second;
//
//	reverse(a, a + n);
//	pr = calc2(x);
//	reverse(a, a + n);
//	sf = calc2((int)n - x);
//	reverse(ALL(sf));
//	FOR(i, 1, pr.size())
//	{
//		cout << pr[i] << ' ';
//	}
//	FOR(i, 0, sf.size() - 1)
//	{
//		cout << sf[i] << ' ';
//	}
//	cout << endl;
//
//
//	
//
//
//
//
//
//	return 0;
//}
//
