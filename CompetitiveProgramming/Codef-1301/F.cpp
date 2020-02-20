#pragma GCC optimize("Ofast")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <string>
#include <deque>
#include <stack>
#include <cmath>
#include <iterator>
#include <string.h>
#include <queue> 

using namespace std;
#ifndef DEBUGING
ostream cnull(NULL);
#define cerr cnull
#endif // !DEBUGING

#define PB push_back
#define MP make_pair
#define f first
#define s second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i, b, a) for (int i = b-1; i>=a; --i)
#define FILL(a, b) memset(a, b, sizeof a)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)a.size()

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<LL> VI;
typedef pair<LL, LL> PLL;

const int INF = 1000 * 1000 * 1000;
const LL LINF = 1LL * INF * INF;
const int MAX = 100010;
const long double PI = acos(-1.);
const double EPS = 1e-6;
const LL MOD = INF + 7;

int n, m ,k;

int a[1003][1003];
bool ok(int x, int y)
{
	return min(x,y) >=0 && x < n && y < m;
}
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

PII q[2000005];
int d[40][1003][1003];

vector<PII> foo[40];
void bfs(int x, int y)
{
	int col = y;
	int qh = 0;
	int qt = 0;
	FILL(d[col], -1);
	d[col][x][y] = 0;
	FOR(i, 0, foo[y].size())
	{
		int nx = foo[y][i].first;
		int ny = foo[y][i].second;
		if (d[col][nx][ny] == -1)
		{
			d[col][nx][ny] = 0;
			q[qt++] = MP(nx, ny);
		}
	}
	while (qh != qt)
	{
		int x = q[qh].first;
		int y = q[qh++].second;
		if (x == 1002)
		{
			FOR(i, 0, foo[y].size())
			{
				int nx = foo[y][i].first;
				int ny = foo[y][i].second;
				if (d[col][nx][ny] == -1)
				{
					d[col][nx][ny] = d[col][x][y]+1;
					q[qt++] = MP(nx, ny);
				}
			}
			continue;
		}
		FOR(k, 0, 4)
		{
			int nx = dx[k] + x;
			int ny = dy[k] + y;
			if (!ok(nx, ny))
				continue;
			if (d[col][nx][ny] == -1)
			{
				d[col][nx][ny] = d[col][x][y] + 1;
				q[qt++] = MP(nx, ny);
			}
		}

		int nx = 1002;
		int ny = a[x][y];
		if (d[col][nx][ny] == -1)
		{
			d[col][nx][ny] = d[col][x][y];
			q[--qh] = MP(nx, ny);
		}
			/*if (d[col][1002][a[nx][ny]] == -1)
			{
				d[col][1002][a[nx][ny]] = d[col][nx][ny];
				FOR(i, 0, foo[a[nx][ny]].size())
				{
					int nnx = foo[a[nx][ny]][i].first;
					int nny = foo[a[nx][ny]][i].second;
					if (d[col][nnx][nny] == -1)
					{
						d[col][nnx][nny] = d[col][nx][ny] + 1;
						q[qt++] = MP(nnx, nny);
					}
				}
			}
		}*/
	}
	


}
#define y2 sdfsdfsadfa
int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m >> k;
	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			cin >> a[i][j];
			a[i][j]--;
			foo[a[i][j]].PB(MP(i, j));
		}
	}

	FOR(i, 0, k)
	{
		bfs(1002, i);
	}

	
	int q;
	cin >> q;
	while (q--)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--, x2--, y1--, y2--;

		register int best = abs(x1 - x2) + abs(y1 - y2);
		FOR(i, 0, k)
		{
			best = min(best, d[i][x1][y1] +d[i][x2][y2]+ 1);
		}
		cout << best << endl;
	}



	return 0;
}