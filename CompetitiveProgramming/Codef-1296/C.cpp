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
//void solve()
//{
//	map<PII, int> foo;
//	int n;
//	cin >> n;
//	string s;
//	cin >> s;
//	int x = 0, y = 0;
//	foo[MP(x, y)] = -1;
//	pair<int, PII> best = MP(INF, MP(0, 0));
//	FOR(i, 0, s.size())
//	{
//		if (s[i] == 'L')
//		{
//			x--;
//		}
//		if (s[i] == 'R')
//		{
//			x++;
//		}
//		if (s[i] == 'U')
//		{
//			y++;
//		}
//		if (s[i] == 'D')
//		{
//			y--;
//		}
//		if (foo.count(MP(x, y)))
//		{
//			int val = foo[MP(x, y)];
//			best = min(best, MP(i - val, MP(val, i)));
//		}
//		foo[MP(x, y)] = i;
//	}
//	if (best.first != INF)
//	{
//		cout << best.second.first+2 << ' ' << best.second.second +1<< endl;
//		return;
//	}
//	cout << -1 << endl;
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
