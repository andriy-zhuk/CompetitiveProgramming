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
const LL mod = 998244353;

int n;
LL fact[200005];
int sub[200005];
vector<int> g[200005];

void dfs(int u, int p = -1)
{
	sub[u] = 1;
	FOR(i, 0, SZ(g[u]))
	{
		int v = g[u][i];
		if (v == p)
			continue;
		dfs(v, u);
		sub[u] += sub[v];
	}
}

LL dp(int u, int p = -1)
{
	LL ans = 1;
	ans *= fact[SZ(g[u])];
	ans %= mod;
	FOR(i, 0, SZ(g[u]))
	{
		int v = g[u][i];
		if (v == p)
			continue;
		ans *= dp(v, u);
		ans %= mod;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	FOR(i, 0, n - 1)
	{
		int x, y;
		cin >> x >> y;
		x--; y--;
		g[x].PB(y);
		g[y].PB(x);
	}
	dfs(0);
	fact[0] = 1;
	FOR(i, 1, 200005)
	{
		fact[i] = 1LL * fact[i - 1] * i % mod;
	}

	cout << (1LL*n*dp(0))%mod << endl;;








	return 0;
}