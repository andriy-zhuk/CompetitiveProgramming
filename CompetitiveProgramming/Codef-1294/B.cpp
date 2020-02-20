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
//PII a[1003];
//int n;
//void solve()
//{
//	cin >> n;
//	n++;
//	a[0] = MP(0, 0);
//	FOR(i, 1, n)
//	{
//		cin >> a[i].first>> a[i].second;
//	}
//	string s = "";
//
//	sort(a, a + n);
//
//	FOR(i, 1, n)
//	{
//		if (a[i].first < a[0].first)
//		{
//			cout << "NO" << endl;
//			return;
//		}
//		while (a[i].first > a[0].first)
//		{
//			s += 'R';
//			a[0].first++;
//		}
//		if (a[i].second < a[0].second)
//		{
//			cout << "NO" << endl;
//			return;
//		}
//		while (a[i].second > a[0].second)
//		{
//			s += 'U';
//			a[0].second++;
//		}
//	}
//	cout << "YES" << endl;
//	cout << s << endl;
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
