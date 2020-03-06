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
//int n, m, q;
//int a[303][303];
//int ans[2000006];
//
//struct ev
//{
//	int time;
//	int x;
//	int y;
//};
//vector<ev> open[2000006];
//vector<ev> close[2000006];
//
//int dx[] = { 0, 1, 0, -1 };
//int dy[] = { 1, 0, -1, 0 };
//
//int make(int x, int y)
//{
//	return x * m + y;
//}
//
//namespace DSU
//{
//	int parent[303 * 303];
//	int rank[303 * 303];
//	void make_set(int v) {
//		parent[v] = v;
//		rank[v] = 0;
//	}
//	void init()
//	{
//		FOR(i, 0, n * m)
//			make_set(i);
//	}
//
//	int find_set(int v) {
//		if (v == parent[v])
//			return v;
//		return parent[v] = find_set(parent[v]);
//	}
//
//	void union_sets(int a, int b) {
//		a = find_set(a);
//		b = find_set(b);
//		if (a != b) {
//			if (rank[a] < rank[b])
//				swap(a, b);
//			parent[b] = a;
//			if (rank[a] == rank[b])
//				++rank[a];
//		}
//	}
//
//	bool equal(int u, int v)
//	{
//		return find_set(u) == find_set(v);
//	}
//
//}
//
//bool ok(int x, int y)
//{
//	return min(x, y) >= 0 && x < n && y < m;
//}
//
//void calc(vector<ev>& e, int k)
//{
//	DSU::init();
//	FOR(i, 0, n)
//		memset(a[i], 0, sizeof(int) * m);
//	FOR(i, 0, e.size())
//	{
//		int x = e[i].x;
//		int y = e[i].y;
//		int u = make(x, y);
//		a[x][y] = 1;
//		int suma = 1;
//		FOR(k, 0, 4)
//		{
//			int nx = x + dx[k];
//			int ny = y + dy[k];
//			if (!ok(nx, ny))
//				continue;
//			int v = make(nx, ny);
//			if (a[nx][ny] == 1)
//			{
//				if (!DSU::equal(u, v))
//				{
//					suma -= 1;
//					DSU::union_sets(u, v);
//				}
//			}
//		}
//		ans[e[i].time] += suma * k;
//	}
//}
//
//
//vector<pair<PII, int> > zap;
//int old[2000006];
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n >> m >> q;
//	int maxCol = 1;
//	FOR(i, 0, q)
//	{
//		int x, y, c;
//		cin >> x >> y >> c;
//		x--, y--;
//		open[c].PB({ i, x,y });
//		close[a[x][y]].PB({ i, x, y });
//		a[x][y] = c;
//		maxCol = max(maxCol, c+1);
//	}
//	
//	FOR(i, 0, n)
//	{
//		FOR(j, 0, m)
//		{
//			close[a[i][j]].PB({ q, i, j });
//		}
//	}
//	FOR(i, 0, maxCol)
//	{
//		calc(open[i], 1);
//	}
//	FOR(i, 0, maxCol)
//	{
//		reverse(ALL(close[i]));
//		calc(close[i], -1);
//	}
//	int cur = 1;
//	FOR(i, 0, q)
//	{
//		cur += ans[i]; 
//		cout << cur << '\n';
//	}
//
//
//
//	return 0;
//}
//
