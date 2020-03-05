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
//int n;
//int make(int x, int y)
//{
//	return x * n + y;
//}
//
//int dx[] = { 0, 1, 0, -1 };
//int dy[] = { 1, 0, -1, 0 };
//string napr = "LURDX";
//
//PII a[1003][1003];
//set<int> foo1,foo2;
//void invalid()
//{
//	cout << "INVALID" << endl;
//	exit(0);
//}
//int d[1003][1003];
//char ans[1003][1003];
//PII q[2000006];
//bool ok(int x, int y)
//{
//	return min(x, y) >= 0 && max(x, y) < n;
//}
//
//void bfs(int _x, int _y)
//{
//	int u = make(_x, _y);
//	int qt = 0;
//	int qh = 0;
//	d[_x][_y] = u;
//	ans[_x][_y] = 'X';
//	q[qt++] = MP(_x, _y);
//	while (qt != qh)
//	{
//		int x = q[qh].first;
//		int y = q[qh++].second;
//		FOR(k, 0, 4)
//		{
//			int nx = x + dx[k];
//			int ny = y + dy[k];
//			if (!ok(nx, ny))
//				continue;
//			if (d[nx][ny] == -1 && a[nx][ny] == MP(_x, _y))
//			{
//				ans[nx][ny] = napr[k];
//				d[nx][ny] = u;
//				q[qt++] = MP(nx, ny);
//			}
//		}
//	}
//}
//
//
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n;
//	FOR(i, 0, n)
//	{
//		FOR(j, 0, n)
//		{
//			int x, y;
//			cin >> a[i][j].first >> a[i][j].second;
//			if (a[i][j] == MP(-1, -1))
//			{
//				continue;
//			}
//			a[i][j].first--;
//			a[i][j].second--;
//			if (a[i][j] == MP(i, j))
//			{
//				foo1.insert(make(i, j));
//			}
//			foo2.insert(make(a[i][j].first, a[i][j].second));
//		}
//	}
//	if (foo1.size() != foo2.size())
//	{
//		invalid();
//	}
//	for (set<int>::iterator it1 = foo1.begin(), it2 = foo2.begin(); it1 != foo1.end() && it2 != foo2.end(); ++it1, ++it2)
//	{
//		if (*it1!=*it2)
//		{
//			invalid();
//		}
//	}
//	FILL(d, -1);
//	for (auto& iter : foo1)
//	{
//		bfs(iter / n, iter% n);
//	}
//	FOR(x, 0, n)
//	{
//		FOR(y, 0, n)
//		{
//			bool flag = false;
//			if (a[x][y] != MP(-1, -1) || ans[x][y] != 0)
//			{
//				continue;
//			}
//			FOR(k, 0, 4)
//			{
//				int nx = x + dx[k];
//				int ny = y + dy[k];
//				if (!ok(nx, ny))
//					continue;
//				if (a[nx][ny] != MP(-1, -1) || ans[nx][ny] != 0)
//				{
//					continue;
//				}
//				flag = true;
//				ans[nx][ny] = napr[k];
//				ans[x][y] = napr[(k + 2) % 4];
//				break;
//			}
//			if (flag == false)
//			{
//				FOR(k, 0, 4)
//				{
//					int nx = x + dx[k];
//					int ny = y + dy[k];
//					if (!ok(nx, ny))
//						continue;
//					if (a[nx][ny] != MP(-1, -1))
//					{
//						continue;
//					}
//					flag = true;
//					ans[x][y] = napr[(k + 2) % 4];
//					break;
//				}
//				if (flag == false)
//				{
//					invalid();
//				}
//			}
//		}
//	}
//	
//	FOR(i, 0, n)
//	{
//		FOR(j, 0, n)
//		{
//			if (ans[i][j] == 0)
//			{
//				invalid();
//			}
//		}
//	}
//	cout << "VALID" << endl;
//	FOR(i, 0, n)
//	{
//		FOR(j, 0, n)
//		{
//			cout << ans[i][j];
//		}
//		cout << endl;
//	}
//
//
//
//	return 0;
//}
//
