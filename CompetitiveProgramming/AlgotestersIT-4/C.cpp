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

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<LL> VI;
typedef pair<LL, LL> PLL;

const int INF = 1000 * 1000 * 1000;
const LL LINF = 1LL * INF * INF;
const int MAX = 100010;
const long double PI = acos(-1.);
const double EPS = 1e-6;
const LL mod = INF + 7;
#define empty sdfsdfsdf

int n, m, d;
int a[1001][1001];

int dd[1001][1001];
PII q[1200];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool ok(int x, int y)
{
	return x >= 0 && y >= 0 && x < n && y < m && a[x][y] != -1;
}
vector<PII> rats;
vector<PII> empty;
vector<PII> bfs1(pair<int, int> p1)
{
	PII p2 = MP(-1, -1);
	int qt = 0;
	int qh = 0;
	
	dd[p1.f][p1.s] = 0;
	q[qt++] = p1;
	int cnt = 0;
	vector<PII> ans;
	while (qt != qh)
	{
		int x = q[qh].first;
		int y = q[qh++].second;
		ans.PB(MP(x, y));
		if (a[x][y] == 1)
			cnt++;
		if (dd[x][y] == 2*d)
		{
			continue;
		}
		FOR(k, 0, 4)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (ok(nx, ny) && dd[nx][ny] == -1)
			{
				dd[nx][ny] = dd[x][y] + 1;
				q[qt++] = MP(nx, ny);
			}
		}
	}

	if (cnt == rats.size())
	{
		FOR(i, 0, qt)
		{
			dd[q[i].first][q[i].second] = -1;
		}
		return ans;
	}
	FOR(i, 0, rats.size())
	{
		if (dd[rats[i].first][rats[i].second] == -1)
		{
			p2 = rats[i];
			break;
		}
	}

	FOR(i, -d, d + 1)
	{
		FOR(j, -d, d + 1)
		{
			if (ok(p2.first + i, p2.second + j) && dd[p2.first+i][p2.second+j] == -1)
				ans.PB(MP(p2.first + i, p2.second + j));
		}
	}

	FOR(i, 0, qt)
	{
		dd[q[i].first][q[i].second] = -1;
	}
	return ans;
}

void bfs(PII p1, PII p2)
{
	int qt = 0;
	int qh = 0;

	dd[p1.f][p1.s] = 0;
	dd[p2.f][p2.s] = 0;
	q[qt++] = p1;
	q[qt++] = p2;
	int cnt = 0;
	while (qt != qh)
	{
		int x = q[qh].first;
		int y = q[qh++].second;
		if (a[x][y] == 1)
			cnt++;
		if (dd[x][y] == d)
		{
			continue;
		}
		FOR(k, 0, 4)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (ok(nx, ny) && dd[nx][ny] == -1)
			{
				dd[nx][ny] = dd[x][y] + 1;
				q[qt++] = MP(nx, ny);
			}
		}
	}
	if (cnt == rats.size())
	{
		cout << p1.first + 1 << ' ' << p1.second + 1 << ' ' << p2.first + 1 << ' ' << p2.second + 1 << endl;
		exit(0);
	}
	FOR(i, 0, qt)
	{
		dd[q[i].first][q[i].second] = -1;
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> m >> d;
	FOR(i, 0, n)
	{
		string s;
		cin >> s;
		FOR(j, 0, m)
		{
			if (s[j] == 'X')
			{
				a[i][j] = -1;
			}
			if (s[j] == 'R')
			{
				rats.PB(MP(i, j));
				a[i][j] = 1;
			}
			if (s[j] == '.')
			{
				empty.PB(MP(i, j));
			}
		}
	}
	if (rats.size() == 1)
	{
		cout << rats.back().first + 1 << ' ' << rats.back().second + 1 << ' ' << empty.back().first + 1 << ' ' << empty.back().second + 1 << endl;
		return 0;
	}
	FILL(dd, -1);
	vector<PII> cur = bfs1(rats.back());
	FOR(i, 0, cur.size())
	{
		FOR(j, i + 1, cur.size())
		{
			if (cur[i] == cur[j])
				continue;
			bfs(cur[i], cur[j]);
			//cout << cur[i].first << ' ' << cur[i].second << endl;
			//cout << cur[j].first << ' ' << cur[j].second << endl;
		}
	}
	cout << -1 << endl;

	return 0;
}

