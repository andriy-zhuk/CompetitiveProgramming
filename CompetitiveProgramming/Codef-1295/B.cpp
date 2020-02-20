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
//LL n, x;
//string s;
//
//void solve()
//{
//	map<LL, int> foo;
//	cin >> n >> x;
//	cin >> s;
//	int cur = 0;
//	int L = 0;
//	int R = 0;
//	FOR(i, 0, s.size())
//	{
//		if (s[i] == '0')
//		{
//			cur++;
//		}
//		else
//		{
//			cur--;
//		}
//		foo[cur]++;
//		L = min(L, cur);
//		R = max(R, cur);
//	}
//
//	if (cur == 0)
//	{
//		if (x == 0 || foo.count(x) != 0)
//		{
//			cout << -1 << endl;
//		}
//		else
//		{
//			cout << 0 << endl;
//		}
//		return;
//	}
//	LL ans = (x==0);
//	if (L >= x && cur < 0)
//	{
//		x += ((L - x) / (-cur))*(-cur);
//	}
//	if (R <= x && cur > 0)
//	{
//		x -= ((x - R) / cur)*cur;
//	}
//
//	FOR(i, 0, 2*n)
//	{
//		ans += foo[x];
//		x -= cur;
//	}
//	cout << ans << endl;
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
