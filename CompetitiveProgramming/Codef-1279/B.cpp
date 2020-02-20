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
//LL n, s;
//LL a[100050];
//LL pref[100005];
//void solve()
//{
//	cin >> n >> s;
//	set<pair<LL, int>> foo;
//	LL suma = 0;
//	int ans = 0;
//	bool ok = true;
//	FOR(i, 0, n)
//	{
//		cin >> a[i];
//			suma += a[i];
//		if (ok)
//		{
//			foo.insert(MP(-a[i], i));
//			if (suma + foo.begin()->first <= s)
//			{
//				ans = foo.begin()->second;
//			}
//			else
//			{
//				ok = false;
//			}
//		}
//	}
//	if (suma <= s)
//	{
//		cout << 0 << endl;
//		return;
//	}
//	cout << ans+1 << endl;
//	
//}
//
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
