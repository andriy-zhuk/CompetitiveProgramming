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

#define prev sdfsdfsdfsdfprev

int dpT[4004][4004];
PII prev[4004][4004];
int n, m;
vector<int> k;
vector<int> kp;
vector<PII> xy;
vector<int> g[4004];
int used[4004];

void read()
{
	cin >> n >> m;
	FOR(i, 0, m)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		xy.PB(MP(x, y));
	}
}
int dfs(int u, int col)
{
	used[u] = col;
	int ret = 1;
	FOR(i, 0, g[u].size())
	{
		int v = g[u][i];
		if (!used[v])
		{
			ret += dfs(v, col);
		}
	}
	return ret;
}

int dp(int pos, int suma)
{
	if (pos == k.size())
		return dpT[pos][suma] = 1;
	if (dpT[pos][suma] != -1)
		return dpT[pos][suma];
	dpT[pos][suma] = max(dp(pos + 1, suma + k[pos]), dp(pos + 1, suma));
	prev[pos + 1][suma + k[pos]] = MP(pos, suma);
	prev[pos + 1][suma] = MP(pos, suma);
	return dpT[pos][suma] = 1;
}

void makeGraph()
{
	FOR(i, 0, xy.size())
	{
		int l = xy[i].first;
		int r = xy[i].second;
		FOR(i, l, r)
		{
			int j = (r - i + l);
			if (i >= j)
				break;
			g[i].PB(j);
			g[j].PB(i);
		}
	}
	FILL(used, 0);
	FOR(i, 0, n)
	{
		if (!used[i])
		{
			k.PB(dfs(i, SZ(k) + 1));
		}
	}
	FILL(dpT, -1);
	FILL(prev, -1);
	dp(0, 0);
}


int solve(int t)
{
	cout << "Case #" << t << ": ";
	read();
	makeGraph();

	pair<int, PII> best = MP(INF, MP(-1, -1));

	FOR(sum, 0, 4004)
	{
		if (dpT[SZ(k) - 1][sum] == 1)
		{
			best = min(best, MP(abs(sum - n), MP(SZ(k) - 1, sum)));
		}
	}
	PII cur = best.second;
	while (prev[cur.first][cur.second] != MP(-1, -1))
	{
		PII nxt = prev[cur.first][cur.second];
		if (nxt.second == cur.second)
		{
			kp.PB(0);
		}
		else
		{
			kp.PB(1);
		}
		cur = nxt;
	}
	reverse(ALL(kp));

	FOR(i, 0, n)
	{
		cout << kp[used[i] - 1];
	}
	cout << endl;

	xy.clear();
	k.clear();
	kp.clear();
	FOR(i, 0, 4004)
	{
		g[i].clear();
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	FOR(i, 0, t)
	{
		solve(i + 1);
	}
	return 0;
}