//#pragma GCC optimize("Ofast")
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <bits/stdc++.h>
//
//using namespace std;
//#include <ext/pb_ds/assoc_container.hpp> 
//
//using namespace __gnu_pbds;
//
//typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag,
//	tree_order_statistics_node_update> ordered_set;
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
//int n, k;
//vector<pair<pair<int, PII>, int> > foo;
//
//pair<int, PII> a[200005];
//
//ordered_set os[100 * 1005 * 22];
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n >> k;
//	FOR(i, 0, n)
//	{
//		int x, r, q;
//		cin >> x >> r >> q;
//		foo.PB(MP(MP(q, MP(x, r)), i));
//	}
//	sort(ALL(foo));
//
//	int cur = 0;
//	FOR(i, 0, n)
//	{
//		if (!i)
//		{
//			a[foo[i].second] = MP(foo[i].first.second.second, MP(foo[i].first.second.first, cur));
//			continue;
//		}
//
//		if (foo[i].first.first != foo[i - 1].first.first)
//		{
//			cur += min(k + 1, foo[i].first.first - foo[i - 1].first.first);
//		}
//		a[foo[i].second] = MP(foo[i].first.second.second, MP(foo[i].first.second.first, cur)); // radius, x, iq
//	}
//
//	sort(a, a + n);
//	reverse(a, a + n);
//
//	LL ans = 0;
//	FOR(i, 0, n)
//	{
//		int x, r, iq;
//		r = a[i].first;
//		x = a[i].second.first;
//		iq = a[i].second.second;
//
//		FOR(i, max(0, iq - k), min(iq + k, cur) + 1)
//		{
//			ans += (os[i].order_of_key(MP(x + r, INF)) - os[i].order_of_key(MP(x - r, -INF)));
//		}
//		os[iq].insert(MP(x, i));
//	}
//
//	cout << ans << endl;
//
//
//
//
//	return 0;
//}