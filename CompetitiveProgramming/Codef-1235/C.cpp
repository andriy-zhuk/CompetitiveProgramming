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
//int n;
//int ans[200005];
//vector<PII> g[200005];;
//
//vector<int> lysty;
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n;
//	FOR(i, 0, n-1)
//	{
//		int x, y;
//		cin >> x >> y;
//		x--, y--;
//		g[x].PB(MP(y, i));
//		g[y].PB(MP(x, i));
//	}
//	FILL(ans, -1);
//	if (n == 2)
//	{
//		cout << 0 << endl;
//		return 0;;
//	}
//	FOR(i, 0, n)
//	{
//		if (g[i].size() == 1)
//		{
//			lysty.PB(i);
//		}
//	}
//	if (lysty.size() == 2)
//	{
//		FOR(i, 0, n - 1)
//		{
//			cout << i << endl;
//		}
//		return 0;
//	}
//	FOR(i, 0, 3)
//	{
//		int u = lysty[i];
//		ans[g[u][0].second] = i;
//	}
//	int tt = 3;
//	FOR(i, 0, n - 1)
//	{
//		if (ans[i] == -1)
//		{
//			ans[i] = tt++;
//		}
//	}
//	FOR(i, 0, n - 1)
//	{
//		cout << ans[i] << endl;
//	}
//	return 0;
//}
//
