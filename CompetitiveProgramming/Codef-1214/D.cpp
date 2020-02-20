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
//int n, m;
//vector<vector<int> > a;
//vector<vector<int> > d;
//PII q[1000005], p1[1000005], p2[1000005];
//int siz;
//
//bool ok(int x, int y)
//{
//	if (min(x, y) < 0)
//		return 0;
//	if (x >= n || y >= m)
//		return 0;
//	return a[x][y] == 0;
//}
//
//void path(PII *path, vector<int> dx, vector<int> dy)
//{
//	int last = 0;
//	FOR(i, 0, n)
//	{
//		FOR(j, 0, m)
//		{
//			d[i][j] = -1;
//		}
//	}
//	d[0][0] = 0;
//	int qh = 0, qt = 0;
//	q[qt++] = MP(0, 0);
//	while (qh != qt)
//	{
//		PII cur = q[qh++];
//		int x = cur.first;
//		int y = cur.second;
//		FOR(j, 0, 2)
//		{
//			int nx = x + dx[j];
//			int ny = y + dy[j];
//			if (ok(nx, ny) && d[nx][ny] == -1)
//			{
//				d[nx][ny] = d[x][y] + 1;
//				q[qt++] = MP(nx, ny);
//			}
//		}
//	}
//	if (d[n - 1][m - 1] == -1)
//	{
//		siz = 0;
//		return;
//	}
//	PII cur = MP(n-1, m-1);
//	while (cur != MP(0, 0))
//	{
//		if (cur != MP(n-1, m-1))
//		{
//			path[last++] = cur;
//		}
//		int x = cur.first;
//		int y = cur.second;
//		FOR(j, 0, 2)
//		{
//			int nx = x - dx[j];
//			int ny = y - dy[j];
//			if (ok(nx, ny) && d[nx][ny] == d[x][y] - 1)
//			{
//				cur = MP(nx, ny);
//				break;
//			}
//		}
//	}
//	siz = last;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n >> m;
//	a.resize(n, vector<int>(m, 0));
//	d.resize(n, vector<int>(m, -1));
//	FOR(i, 0, n)
//	{
//		string s;
//		cin >> s;
//		FOR(j, 0, m)
//		{
//			if (s[j] == '#')
//			{
//				a[i][j] = 1;
//			}
//		}
//	}
//
//	vector<int> dx(2),dy(2);
//	dx[0] = 0; dy[0] = 1;
//	dx[1] = 1; dy[1] = 0;
//
//	path(p1, dx, dy);
//	if (siz == 0)
//	{
//		cout << 0;
//		return 0;
//	}
//	path(p2, dy, dx);
//	FOR(i, 0, siz)
//	{
//		if (p1[i] == p2[i])
//		{
//			cout << 1 << endl;
//			return 0;
//		}
//	}
//	cout << 2 << endl;
//	return 0;
//
//
//
//
//}