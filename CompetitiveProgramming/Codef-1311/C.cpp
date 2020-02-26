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
//typedef vector<int> VI;
//
//const int INF = 1000 * 1000 * 1000;
//const LL LINF = 1LL * INF * INF;
//const int MAX = 100010;
//const long double PI = acos(-1.);
//const double EPS = 1e-6;
//const LL MOD = INF + 7;
//int n, m;
//string s;
//int a[200005];
//int sf[200005];
//int ans[26];
//void solve()
//{
//	cin >> n >> m;
//	FOR(i, 0, n)
//	{
//		sf[i] = 0;
//		a[i] = 0;
//	}
//	cin >> s;
//	FOR(i, 0, m)
//	{
//		int x;
//		cin >> x;
//		a[x - 1]++;
//	}
//	a[n - 1]++;
//	RFOR(i, n, 0)
//	{
//		sf[i] = a[i];
//		if (i != n - 1)
//			sf[i] += sf[i + 1];
//	}
//	FILL(ans, 0);
//	FOR(i, 0, s.size())
//	{
//		ans[s[i] - 'a'] += sf[i];
//	}
//	FOR(i, 0, 26)
//	{
//		cout << ans[i] << ' ';
//	}
//	cout << endl;
//
//
//
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
