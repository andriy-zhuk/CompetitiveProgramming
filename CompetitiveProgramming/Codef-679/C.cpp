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
//int n, k;
//int a[505][505];
//int col[505][505];
//bool ok(int x, int y)
//{
//	if (min(x, y) < 0 || max(x, y) >= n) return 0;
//	return a[x][y];
//}
//
//vector<int> cost;
//vector<bool> used;
//vector<int> inside;
//int dx[] = { 1, 0, -1, 0 };
//int dy[] = { 0, 1, 0, -1 };
//void dfs(int x, int y, int c)
//{
//	col[x][y] = c;
//
//	FOR(k, 0, 4)
//	{
//		int nx = x + dx[k];
//		int ny = y + dy[k];
//		if (ok(nx, ny) && col[nx][ny] == -1)
//		{
//			dfs(nx, ny, c);
//		}
//	}
//}
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	//freopen("input.txt", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	cin >> n >> k;
//	FOR(i, 0, n)
//	{
//		string s;
//		cin >> s;
//		FOR(j, 0, s.size())
//		{
//			if (s[j] == '.')
//			{
//				a[i][j] = 1;
//			}
//		}
//	}
//	int c = 0;
//	FILL(col, -1);
//	FOR(i, 0, n)
//	{
//		FOR(j, 0, n)
//		{
//			if (col[i][j] == -1 && ok(i,j))
//				dfs(i, j, c++);
//		}
//	}
//	cost.resize(c, 0);
//	inside.resize(c, 0);
//	FOR(i, 0, n)
//	{
//		FOR(j, 0, n)
//		{
//			if (col[i][j] != -1)
//			{
//				cost[col[i][j]]++;
//			}
//		}
//	}
//	int best = 0;
//
//	int suma = 0;
//	int insuma = 0;
//	FOR(x, 0, n-k+1)
//	{
//		suma = k*k;
//		insuma = 0;
//		FOR(i, 0, k)
//		{
//			FOR(j, 0, k)
//			{
//				if (ok(i+x, j))
//				{
//					if (inside[col[i+x][j]] == 0)
//						suma += cost[col[i+x][j]];
//					inside[col[i + x][j]]++;
//					insuma++;
//				}
//			}
//			if (ok(i + x, k))
//			{
//				if (inside[col[i + x][k]] == 0)
//					suma += cost[col[i+x][k]];
//				inside[col[i + x][k]]++;
//			}
//			if (ok(x + k, i))
//			{
//				if (inside[col[x + k][i]] == 0)
//					suma += cost[col[x + k][i]];
//				inside[col[x + k][i]]++;
//			}
//			if (ok(x - 1, i))
//			{
//				if (inside[col[x - 1][i]] == 0)
//					suma += cost[col[x - 1][i]];
//				inside[col[x - 1][i]]++;
//			}
//		}
//
//		best = max(best, suma-insuma);
//		//cout << x << ' ' << suma <<'-' << insuma << endl;
//		FOR(y, 0, n - k)
//		{
//			FOR(i, 0, k)
//			{
//				if (ok(i + x, y + k))
//				{
//					insuma++;
//				}
//				if (ok(i + x, y + k + 1))
//				{
//					if (inside[col[i + x][y + k + 1]] == 0)
//						suma += cost[col[i + x][y + k + 1]];
//					inside[col[i + x][y + k + 1]]++;
//				}
//			}
//			if (ok(x + k, y + k))
//			{
//				if (inside[col[x + k][y + k]] == 0)
//					suma += cost[col[x + k][y + k]];
//				inside[col[x + k][y + k]]++;
//			}
//			if (ok(x - 1, y + k))
//			{
//				if (inside[col[x - 1][y + k]] == 0)
//					suma += cost[col[x - 1][y + k]];
//				inside[col[x - 1][y + k]]++;
//			}
//			FOR(i, 0, k)
//			{
//				if (ok(i + x, y))
//				{
//					insuma--;
//				}
//				if (ok(i + x, y - 1))
//				{
//					inside[col[i + x][y-1]]--;
//					if (inside[col[i + x][y-1]] == 0)
//					{
//						suma -= cost[col[i + x][y-1]];
//					}
//				}
//			}
//			if (ok(x + k, y))
//			{
//				inside[col[x + k][y]]--;
//				if (inside[col[x + k][y]] == 0)
//					suma -= cost[col[x + k][y]];
//			}
//			if (ok(x - 1, y))
//			{
//				inside[col[x - 1][y]]--;
//				if (inside[col[x - 1][y]] == 0)
//					suma -= cost[col[x - 1][y]];
//			}
//			best = max(best, suma - insuma);
//		//	cout << x << '+' << y << ' ' << suma - insuma << endl;
//		}
//		FOR(i, -1, k+1)
//		{
//			FOR(j, -1, k+1)
//			{
//				if (ok(i + x, j + n - k))
//				{
//					inside[col[i + x][j + n - k]] = 0;
//				}
//			}
//		}
//	}
//	cout << best << endl;
//
//
//
//
//
//	return 0;
//}
//
