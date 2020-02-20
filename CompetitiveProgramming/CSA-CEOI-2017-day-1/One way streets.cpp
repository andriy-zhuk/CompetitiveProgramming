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

int n, m, p;

namespace
{
	const int MAXN = 1000005;
	vector<int> g[MAXN];
	bool used[MAXN];
	int timer, tin[MAXN], fup[MAXN];

	void dfs(int v, int p = -1) {
		used[v] = true;
		tin[v] = fup[v] = timer++;
		for (size_t i = 0; i < g[v].size(); ++i) {
			int to = g[v][i];
			if (to == p)  continue;
			if (used[to])
				fup[v] = min(fup[v], tin[to]);
			else {
				dfs(to, v);
				fup[v] = min(fup[v], fup[to]);
				if (fup[to] > tin[v])
					IS_BRIDGE(v, to);
			}
		}
	}

	void find_bridges() {
		timer = 0;
		for (int i = 0; i < n; ++i)
			used[i] = false;
		for (int i = 0; i < n; ++i)
			if (!used[i])
				dfs(i);
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	return 0;
}

