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
//int n;
//PII a[200005];
//LL ans = 0;
//multiset<LL> foo;
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//
//	cin >> n;
//	FOR(i, 0, n)
//	{
//		cin >> a[i].f;
//	}
//	FOR(i, 0, n)
//	{
//		cin >> a[i].s;
//	}
//	sort(a, a + n);
//	int last = a[0].f;
//	LL sumall = 0;
//	int i = 0;
//	while (i < n || foo.size())
//	{
//			while (i < n && a[i].first == last)
//		{
//			foo.insert(a[i].second);
//			sumall += a[i].second;
//			i++;
//		}
//		if (foo.size())
//		{
//			sumall -= *(--foo.end());
//			foo.erase(--foo.end());
//			ans += sumall;
//			last++;
//		}
//		else
//		{
//			if (i >= n)
//				break;
//			else
//				last = a[i].first;
//		}
//	}
//	cout << ans << endl;
//
//
//
//
//
//	return 0;
//}
//
