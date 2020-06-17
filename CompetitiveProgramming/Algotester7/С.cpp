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
//#include <bitset>
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
//int n, m;
//
//
//vector<int> g[200005];
//int used[200005];
//
//void dfs(int u, int c)
//{
//	used[u] = c;
//	FOR(i, 0, SZ(g[u]))
//	{
//		int v = g[u][i];
//		if (!used[v])
//			dfs(v, c);
//	}
//}
//int cnt[200005];
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
//		g[x].PB(y);
//		g[y].PB(x);
//	}
//
//	int col = 0;
//	FOR(i, 0, n)
//	{
//		if (!used[i])
//		{
//			dfs(i, ++col);
//		}
//	}
//	col++;
//	FOR(i, 0, n)
//	{
//		cnt[used[i]]++;
//	}
//
//
//	bitset<100002> foo;
//	foo.set(0, 1);
//	
//
//
//	FOR(i, 1, col)
//	{
//		bitset<100002> cur = foo << cnt[i];
//		foo |= cur;
//	}
//
//	cout << foo.count();
//
//
//	return 0;
//}
//
//
//
///*
//7 7
//1 4
//4 7
//2 5
//2 6
//5 3
//4 1
//6 5
//*/