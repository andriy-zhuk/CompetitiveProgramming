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

const int H = 35 * 600 * 1000 + 5;
struct PST
{
#define tm (tl+tr)/2
	int t[H];
	int g[H][2];
	int cnt = 0;
	int build(int tl, int tr)
	{
		int v = cnt++;
		if (tl == tr)
		{
			t[v] = 0;
			return v;
		}
		g[v][0] = build(tl, tm);
		g[v][1] = build(tm + 1, tr);
		t[v] = t[g[v][0]] + t[g[v][1]];
		return v;
	}
	int upd(int old, int tl, int tr, int pos, int val)
	{
		int v = cnt++;
		t[v] = t[old];
		g[v][0] = g[old][0];
		g[v][1] = g[old][1];
		if (tl == tr)
		{
			t[v] = val;
			return v;
		}
		if (pos <= tm)
		{
			g[v][0] = upd(g[v][0], tl, tm, pos, val);
		}
		else
		{
			g[v][1] = upd(g[v][1], tm + 1, tr, pos, val);
		}
		t[v] = t[g[v][0]] + t[g[v][1]];
		return v;
	}

	PII get(int v, int tl, int tr, int l, int r) // val, vert
	{
		if (tl == l && tr == r)
		{
			return MP(t[v], v);
		}
		PII cur;
		if (r <= tm)
		{
			cur = get(g[v][0], tl, tm, l, r);
			g[v][0] = cur.second;
		}
		else if (l >= tm + 1)
		{
			cur = get(g[v][1], tm + 1, tr, l, r);
			g[v][1] = cur.second;
		}
		else
		{
			PII a = get(g[v][0], tl, tm, l, tm);
			PII b = get(g[v][1], tm + 1, tr, tm + 1, r);
			g[v][0] = a.second;
			g[v][1] = b.second;
			cur.first = a.first + b.first;
		}
		t[v] = t[g[v][0]] + t[g[v][1]];
		return MP(cur.first, v);
	}
#undef tm
} q;
int n, m;
int a[600005];
int nxt[600005];
int last[600005];
int minimal[300005];
int maximal[300005];

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m;
	FOR(i, 0, n)
	{
		a[i] = n - i - 1;
		minimal[i] = i;
		maximal[i] = i;
	}
	FOR(i, 0, m)
	{
		cin >> a[i + n];
		a[i + n]--;
		minimal[a[i + n]] = 0;
	}

	int nm = n + m;
	FILL(last, -1);
	RFOR(i, nm, 0)
	{
		nxt[i] = last[a[i]];
		last[a[i]] = i;
	}
	int head = q.build(0, nm - 1);
	RFOR(i, nm, 0)
	{
		if (nxt[i] != -1)
		{
			head = q.upd(head, 0, nm - 1, nxt[i], 0);
			PII cur = q.get(head, 0, nm - 1, i, nxt[i]);
			maximal[a[i]] = max(maximal[a[i]], cur.first);
			head = cur.second;
		}
		else
		{
			PII cur = q.get(head, 0, nm - 1, i, nm - 1);
			maximal[a[i]] = max(maximal[a[i]], cur.first);
			head = cur.second;
		}
		head = q.upd(head, 0, nm - 1, i, 1);
	}

	FOR(i, 0, n)
	{
		cout << minimal[i] + 1 << ' ' << maximal[i] + 1 << endl;
	}



	return 0;
}

