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
//int n;
//
//int pp[1000005];
//vector<int> p;
//void prec()
//{
//	int nn = 1000005;
//	FOR(i, 2, nn)
//	{
//		if (pp[i] == 0)
//			p.PB(i);
//		else
//			continue;
//		LL j = 1LL * i * i;
//		while (j < nn)
//		{
//			pp[j] = 1;
//			j += i;
//		}
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	prec();
//	cin >> n;
//	bool ok = 0;
//	int m;
//	vector<PII> foo;
//	FOR(i, 0, n)
//	{
//		foo.PB(MP(i, (i + 1) % n));
//	}
//	FOR(x, 0, n / 2)
//	{
//		int i = lower_bound(ALL(p), n + x) - p.begin();
//		if (p[i] == n + x)
//		{
//			ok = 1;
//			break;
//		}
//		foo.PB(MP(x, x + n / 2));
//	}
//	cout << foo.size() << endl;
//	FOR(i, 0, foo.size())
//	{
//		cout << 1+foo[i].first << ' ' << 1+foo[i].second << endl;
//	}
//	
//
//
//	return 0;
//}