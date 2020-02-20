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
//string s;
//string t;
//int n;
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	int c1 = 0;
//	cin >> n >> s >> t;
//	FOR(i, 0, n)
//	{
//		if (s[i] == 'a')
//			c1++;
//	}
//	FOR(i, 0, n)
//	{
//		if (t[i] == 'a')
//			c1++;
//	}
//	vector<PII> ans;
//	vector<int> p1, p2;
//
//	FOR(i, 0, n)
//	{
//		if (s[i] == 'a' && t[i] == 'b')
//		{
//			p1.PB(i);
//		}
//		if (s[i] == 'b' && t[i] == 'a')
//		{
//			p2.PB(i);
//		}
//	}
//	while (p1.size() >= 2)
//	{
//		int x = p1.back(); p1.pop_back();
//		int y = p1.back(); p1.pop_back();
//		swap(s[x], t[y]);
//		ans.PB(MP(x, y));
//	}
//	while (p2.size() >= 2)
//	{
//		int x = p2.back(); p2.pop_back();
//		int y = p2.back(); p2.pop_back();
//		ans.PB(MP(x, y));
//		swap(s[x], t[y]);
//	}
//	if (p1.size() == 1 && p2.size() == 1)
//	{
//		int x = p1.back();
//		int y = p2.back();
//		swap(s[x], t[x]);
//		ans.PB(MP(x, x));
//		swap(s[x], t[y]);
//		ans.PB(MP(x, y));
//	}
//	if (s != t)
//	{
//		cout << -1 << endl;
//		return 0;
//	}
//	cout << ans.size() << endl;
//	FOR(i, 0, SZ(ans))
//	{
//		cout << ans[i].first+1 << ' ' << ans[i].second+1 << endl;
//	}
//
//	return 0;
//}