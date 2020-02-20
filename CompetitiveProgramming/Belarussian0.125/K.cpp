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
//#define rank rankpetro
//int n, m;
//vector<PII> rib;
//
//int rank[100005];
//int par[100005];
//
//int findset(int x)
//{
//	if (x == par[x])
//		return x;
//	return par[x] = findset(par[x]);
//}
//
//void unite(int x, int y)
//{
//	x = findset(x);
//	y = findset(y);
//	if (x == y)
//		return;
//	if (rank[x] < rank[y])
//		swap(x, y);
//
//	par[y] = x;
//	if (rank[x] == rank[y])
//		rank[x]++;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n >> m;
//	FOR(i, 0, m)
//	{
//		int x, y;
//		cin >> x >> y;
//		x--, y--;
//		rib.PB(MP(x, y));
//	}
//	reverse(ALL(rib));
//	FOR(i, 0, n)
//	{
//		rank[i] = 0;
//		par[i] = i;
//	}
//	int all = n;
//	FOR(i, 0, m)
//	{
//		int u = rib[i].first;
//		int v = rib[i].second;
//		if (findset(u) != findset(v))
//		{
//			all--;
//			unite(u, v);
//		}
//		if (all == 1)
//		{
//			cout << m - i << endl;
//			return 0;
//		}
//	}
//
//	return 0;
//}