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
int n;
int m;
vector<PII>g[5005];


PII nxt[5005][5005];
int st = 0;
void dfs(int u, int p = -1)
{
	FOR(i, 0, g[u].size())
	{
		int v = g[u][i].f;
		if (v == p)
			continue;
		nxt[st][v] = MP(u, g[u][i].second);
		dfs(v, u);
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	vector<int> e;
	FOR(i, 0, n-1)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		e.PB(-INF);
		g[x].PB(MP(y, i));
		g[y].PB(MP(x, i));
	}

	FOR(i, 0, n)
	{
		st = i;
		dfs(st);
	}
	cin >> m;
	vector<pair<int, PII>> zap;
	FOR(i, 0, m)
	{
		int x, y, z;
		cin >> x >> y >> z;
		x--, y--;

		zap.PB(MP(z, MP(x, y)));
	}
	sort(ALL(zap));
	FOR(i, 0, zap.size())
	{
		int x = zap[i].second.first;
		int y = zap[i].second.second;
		int z = zap[i].first;
		while (y != x)
		{
			e[nxt[x][y].second] = z;
			y = nxt[x][y].first;
		}
	}
	FOR(i, 0, e.size())
	{
		if (e[i] == -INF)
			e[i] = 1;
	}
	bool ok = true;
	FOR(i, 0, zap.size())
	{
		int x = zap[i].second.first;
		int y = zap[i].second.second;
		int z = zap[i].first;
		int cur = INF;
		while (y != x)
		{
			cur = min(cur, e[nxt[x][y].second]);
			y = nxt[x][y].first;
		}
		if (cur != z)
		{
			cout << "-1" << endl;
			return 0;
		}
	}

	FOR(i, 0, e.size())
	{
		cout << e[i] << ' ';
	}
	cout << endl;


	return 0;
}

