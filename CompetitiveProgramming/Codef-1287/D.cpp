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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<
	int,
	null_type,
	less<int>,
	rb_tree_tag,
	tree_order_statistics_node_update>
	ordered_set;

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

int n;
vector<int> g[2002];
int c[2002];
int root;

int a[2002];
int l, r;
ordered_set foo;


void inc(int u, int x, int val)
{
	if (a[u] >= x)
	{
		a[u] += val;
	}
	if (val == 0 && a[u] != -INF)
		foo.insert(a[u]);
	FOR(i, 0, g[u].size())
	{
		int v = g[u][i];
		inc(v, x, val);
	}
}

void dfs(int u)
{
	FOR(i, 0, SZ(g[u]))
	{
		int v = g[u][i];
		dfs(v);
	}
	if (c[u] == 0)
	{
		a[u] = --l;
		//cout << u << ' ' << a[u] << endl;
	}
	else
	{
		foo.clear();
		a[u] = -INF;
		inc(u, -INF, 0);
		int cur = INF;
		auto it = foo.find_by_order(c[u]);
		if (it != foo.end())
		{
			cur = *it;
		}
		if (cur == INF)
			cur = r;
		++r;
		//cout << u << ' ' << c[u] << " " << cur << endl;
		inc(root, cur, 1);
		a[u] = cur;
	}

}

bool ok = true;

int check(int u, int val)
{
	int cur = 0;
	if (a[u] < val)
	{
		cur++;
	}
	FOR(i, 0, SZ(g[u]))
	{
		int v = g[u][i];
		cur += check(v, val);
	}
	return cur;
}


int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	FOR(i, 0, n)
	{
		int x, y;
		cin >> x >> y;
		x--;
		c[i] = y;
		if (x != -1)
			g[x].PB(i);
		else
			root = i;
	}

	r = l = 50000;
	FOR(i, 0, n)
	{
		a[i] = -INF;
	}
	dfs(root);

	FOR(i, 0, n)
	{
		if (check(i, a[i]) != c[i])
		{
			ok = false;
		}
	}

	if (ok)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
		return 0;
	}
	FOR(i, 0, n)
	{
		cout << a[i] << " ";
	}
	cout << endl;


	return 0;
}