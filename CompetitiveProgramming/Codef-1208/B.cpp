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
//
//
//int n;
//int a[2005];
//int b[2005];
//int nones;
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n;
//	vector<PII> foo;
//	FOR(i, 0, n)
//	{
//		cin >> a[i];
//		foo.PB(MP(a[i], i));
//
//	}
//	sort(ALL(foo));
//	int nn = 0;
//	FOR(i, 0, foo.size())
//	{
//		if (!i || foo[i].first != foo[i - 1].first)
//		{
//			a[foo[i].second] = ++nn;
//		}
//		else
//		{
//			a[foo[i].second] = nn;
//		}
//	}
//
//	FOR(i, 0, n)
//	{
//		b[a[i]]++;
//	}
//	FOR(i, 0, 2005)
//	{
//		if (b[i] > 1)
//		{
//			nones++;
//		}
//	}
//
//	int val = nones;
//	int best = n;
//	if (nones == 0)
//	{
//		best = 0;
//	}
//	FOR(i, 0, n)
//	{
//		val = nones;
//		FOR(j, i, n)
//		{
//			b[a[j]]--;
//			if (b[a[j]] == 1)
//			{
//				val--;
//			}
//			if (val == 0)
//			{
//				best = min(best, (j - i + 1));
//			}
//		}
//		FOR(j, i, n)
//		{
//			b[a[j]]++;
//		}
//	}
//	cout << best << endl;
//
//
//	return 0;
//}