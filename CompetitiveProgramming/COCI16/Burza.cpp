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

int n, k;
vector<int> g[500];
int val[500];
vector<int> sons[500];


int dfs(int u, int p = -1)
{
	if (SZ(g[u]) == 1 && p != -1)
	{
		val[u] = 0;
		return 0;
	}
	FOR(i, 0, SZ(g[u]))
	{
		int v = g[u][i];
		if (v != p)
		{
			sons[u].PB(dfs(v, u));
		}
	}
	sort(ALL(sons[u]));
	if (sons[u].size() == 1)
	{
		val[u] = 1;
		return 1;
	}
	sons[u].pop_back();
	FOR(i, 0, SZ(g[u]))
	{
		int v = g[u][i];
		if (v != p && val[v] == sons[u].back())
		{
			val[u] = val[v] + 1;
			return val[u];
		}
	}
	return 0;
}


int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> k;
	FOR(i, 0, n - 1)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].PB(y);
		g[y].PB(x);
	}
	cout << dfs(0) << endl;
	if (dfs(0) <= k)
	{
		cout << "DA" << endl;
	}
	else
	{
		cout << "NE" << endl;
	}

	return 0;
}

