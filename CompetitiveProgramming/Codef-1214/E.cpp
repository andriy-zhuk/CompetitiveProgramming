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
//int n;
//vector<PII> d;
//vector<PII> ans;
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n;
//	d.resize(n);
//	FOR(i, 0, n)
//	{
//		cin >> d[i].f;
//		d[i].second = 2*(i+1);
//	}
//	sort(ALL(d));
//	reverse(ALL(d));
//	FOR(i, 0, n)
//	{
//		if (i)
//			ans.PB(MP(d[i].second, d[i - 1].second));
//		int j = i + d[i].first - 1;
//		if (j == SZ(d) - 1)
//		{
//			ans.PB(MP(d.back().second, d[i].second - 1));
//			d.PB(MP(d[i].first, d[i].second - 1));
//		}
//		else
//		{
//			ans.PB(MP(d[j].second, d[i].second - 1));
//		}
//	}
//
//	if (ans.size() != 2 * n - 1)
//	{
//		return -1;
//	}
//	//cout << ans.size() << endl;
//	FOR(i, 0, SZ(ans))
//	{
//		cout << ans[i].first << ' ' << ans[i].second << endl;
//	}
//
//	return 0;
//}
