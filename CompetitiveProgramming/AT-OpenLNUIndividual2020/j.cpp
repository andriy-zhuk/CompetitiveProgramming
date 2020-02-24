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
//int n, m;
//int k;
//
//int used[202][202];
//bool can(int x, int y)
//{
//	if (min(x, y) < 0)
//		return 0;
//	if (x >= n || y >= m)
//		return 0;
//	return used[x][y] == 0;
//}
//
//int dx[] = {0, 1, 0, -1};
//int dy[] = {1,0,-1,0};
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> m >> n;
//	cin >> k;
//	bool ok = true;
//	int dir = 0;
//	int x = 0;
//	int y = 0;
//	k--;
//	if (k == 0)
//	{
//		cout << y + 1 << ' ' << x + 1 << endl;
//		return 0;
//	}
//	used[x][y] = 1;
//	while (ok)
//	{
//		ok = false;
//		FOR(i, 0, 4)
//		{
//			while (true)
//			{
//				int nx = dx[dir] + x;
//				int ny = dy[dir] + y;
//				if (can(nx, ny))
//				{
//					k--;
//					used[nx][ny] = 1;
//					x = nx;
//					y = ny;
//					ok = true;
//					if (k == 0)
//					{
//						cout << y+1 << ' ' << x+1 << endl;
//						return 0;
//					}
//				}
//				else
//				{
//					break;
//				}
//			}
//			dir = dir + 1;
//			dir %= 4;
//		}
//	}
//	cout << -1 << ' ' << -1 << endl;
//	return 0;
//}
//
