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
//
//
//int n, m;
//int k;
//set<int> in[200005];
//set<int> out[200005];
//
//struct kurka {
//	bool operator() (const PII& lhs, const PII& rhs) const {
//		int x = lhs.second;
//		int y = rhs.second;
//		if (in[x].size() * out[x].size() == 0 && in[y].size() * out[y].size() == 0)
//		{
//			return lhs < rhs;
//		}
//		if (in[x].size() * out[x].size() != 0 && in[y].size() * out[y].size() != 0)
//		{
//			return lhs < rhs;
//		}
//		if (in[x].size() * out[x].size() != 0 && in[y].size() * out[y].size() == 0)
//		{
//			return false;
//		}
//		if (in[x].size() * out[x].size() == 0 && in[y].size() * out[y].size() != 0)
//		{
//			return true;
//		}
//	}
//};
//
//set<PII, kurka> foo;
//void solve()
//{
//	set<PII> aa;
//	cin >> n >> m;
//	FOR(i, 0, m)
//	{
//		int x, y;
//		cin >> x >> y;
//		x--, y--;
//		aa.insert(MP(x, y));
//	}
//	for (auto &iter: aa)
//	{
//		int x = iter.first;
//		int y = iter.second;
//		out[x].insert(y);
//		in[y].insert(x);
//	}
//	FOR(i, 0, n)
//	{
//		foo.insert(MP(in[i].size() + out[i].size(), i));
//	}
//	k = 4 * n;
//	k /= 7;
//	vector<int> ans;
//	while (k--)
//	{
//		int x = (--foo.end())->second;
//		ans.PB(x);
//		foo.erase(--foo.end());
//		
//		for (auto& v : out[x])
//		{
//			foo.erase(MP(in[v].size() + out[v].size(), v));
//			in[v].erase(x);
//			foo.insert(MP(in[v].size() + out[v].size(), v));
//		}
//		for (auto& v : in[x])
//		{
//			foo.erase(MP(in[v].size() + out[v].size(), v));
//			out[v].erase(x);
//			foo.insert(MP(in[v].size() + out[v].size(), v));
//		}
//	}
//
//	cout << ans.size() << endl;
//	FOR(i, 0, ans.size())
//	{
//		cout << ans[i] + 1 << ' ';
//	}
//	cout << endl;
//	FOR(i, 0, n)
//	{
//		in[i].clear();
//		out[i].clear();
//	}
//	foo.clear();
//	ans.clear();
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
