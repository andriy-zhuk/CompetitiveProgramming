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
//void solve()
//{
//	string s;
//	cin >> s;
//	vector<int> a;
//	int n = s.size();
//	int cur = 0;
//	FOR(i, 0, s.size())
//	{
//		if (s[i] == '-')
//			cur--;
//		else
//			cur++;
//		a.PB(cur);
//	}
//	a.PB(-INF);
//	cur = 0;
//	LL ans = 0;
//	for (int i = 0; i <= n; ++i)
//	{
//		while (a[i] >= cur)
//		{
//			i++;
//		}
//		LL k = 1;
//		if (i != n)
//		{
//			k = cur - a[i];
//		}
//		ans += k*(i + (i!=n));
//		cur = a[i];
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
