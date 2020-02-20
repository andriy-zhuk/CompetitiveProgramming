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
//int n, m;
//vector<int> b,a;
//
//int used[100005];
//void solve()
//{
//	vector<int> foo;
//	cin >> n >> m;
//	a.resize(n);
//	FOR(i, 0, n)
//	{
//		cin >> a[i];
//		a[i]--;
//	}
//	b.resize(m);
//	FOR(j, 0, m)
//	{
//		cin >> b[j];
//		b[j]--;
//		used[b[j]] = 1;
//	}
//	FOR(i, 0, n)
//	{
//		if (used[a[i]])
//			foo.PB(a[i]);
//	}
//	while (foo.size() && foo.back() == b.back())
//	{
//		used[foo.back()] = 0;
//		b.pop_back();
//		foo.pop_back();
//	}
//	reverse(ALL(b));
//	reverse(ALL(a));
//	while (a.size() && a.back() == b.back())
//	{
//		used[a.back()] = 0;
//		a.pop_back();
//		b.pop_back();
//	}
//	reverse(ALL(a));
//	int k = 0;
//	FOR(i, 0, a.size())
//	{
//		if (used[a[i]])
//			k = i;
//	}
//
//	cout << 2 * k + m << endl;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		solve();
//	}
//	return 0;
//}
//
