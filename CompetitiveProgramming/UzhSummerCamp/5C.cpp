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
#include <cassert>

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
const int maxn = 1 << 16;

namespace ST
{
	PII t[4 * maxn];
	void init()
	{
		FILL(t, 0);
	}
	void build(int *a, int v, int tl, int tr)
	{
		if (tl == tr)
		{
			t[v] = MP(a[tl], tl);
			return;
		}
		int tm = (tl + tr) / 2;
		build(a, v + v, tl, tm);
		build(a, v + v + 1, tm + 1, tr);
		t[v] = min(t[v + v], t[v + v + 1]);
	}

	PII get(int v, int tl, int tr, int l, int r)
	{
		if (tl == l && tr == r)
		{
			return t[v];
		}
		int tm = (tl + tr) / 2;
		if (r <= tm)
		{
			return get(v + v, tl, tm, l, r);
		}
		if (l > tm)
		{
			return get(v + v + 1, tm + 1, tr, l, r);
		}
		return min(get(v + v, tl, tm, l, tm), get(v + v + 1, tm + 1, tr, tm + 1, r));
	}
}

namespace BOR // tr = 2^LOG -1
{
	int cnt = 1;
	int t[maxn * 30];
	int g[maxn * 30][2];
	int LOG;
	void init()
	{
		FILL(t, 0);
		FILL(g, 0);
		LOG = 0;
		while ((1 << LOG) < maxn)
		{
			LOG++;
		}
	}
	int build(int tl, int tr)
	{
		int nval = cnt++;
		if (tl == tr)
		{
			return nval;
		}
		int tm = (tl + tr) / 2;
		g[nval][0] = build(tl, tm);
		g[nval][1] = build(tm + 1, tr);
		return nval;
	}

	int upd(int v, int tl, int tr, int pos)
	{
		int nval = cnt++;
		t[nval] = t[v];
		if (tl == tr)
		{
			t[nval]++;
			return nval;
		}
		g[nval][0] = g[v][0];
		g[nval][1] = g[v][1];
		int tm = (tl + tr) / 2;
		if (pos <= tm)
		{
			g[nval][0] = upd(g[nval][0], tl, tm, pos);
		}
		else
		{
			g[nval][1] = upd(g[nval][1], tm + 1, tr, pos);
		}
		t[nval] = t[g[nval][0]] + t[g[nval][1]];
		return nval;
	}

	// bit = LOG-1;
	int get(int v, int tl, int tr, int xored, int bit, int w)
	{
		if (tl == tr)
		{
			return t[v];
		}
		int tm = (tl + tr) / 2;
		int l = g[v][0];
		int r = g[v][1];
		if (w & (1 << bit)) 
		{
			if (xored & (1 << bit)) // take all right: x(1)^1 < w(1), x(1)^0 <= w(1)
			{
				return t[r] + get(l, tl, tm, xored, bit - 1, w);
			}
			else // take all left: x(0)^0 < w(1), x(0)^1<=w(1)
			{
				return t[l] + get(r, tm + 1, tr, xored ^ (1<<bit), bit - 1, w);
			}
		}
		else
		{
			if (xored & (1 << bit)) // dont take left: x(1)^1 <= w(0), x(1)^0 > w(0)
			{
				return get(r, tm + 1, tr, xored ^ (1<<bit), bit - 1, w);
			}
			else // dont take right: x(0)^1 > w(0), x(0)^0 <= w(0)
			{
				return get(l, tl, tm, xored, bit - 1, w);
			}
		}
	}
}

int n, k;
int a[maxn];
int pref[maxn];
int head[maxn];

LL solve(int l, int r, LL w)
{
	if (l > r)
		return 0;
	if (l == r)
	{
		return (1LL * a[l] * a[l] <= w);
	}
	PII minval = ST::get(1, 0, n - 1, l, r);
	int pos = minval.second;
	LL value = w / minval.first; // ????
	value = min(value, (1LL << BOR::LOG) - 1);
//	cout << l << ' ' << r << ' ' << pos << endl;
	LL ans = 0;
	if (pos - l <= r - pos)
	{
		FOR(ll, l, pos+1)
		{
			int px = 0;
			if (ll)
				px = pref[ll - 1];
			//[pos,r]
			ans += BOR::get(head[r], 0, (1 << BOR::LOG) - 1, px, BOR::LOG - 1, value);
		//	cout << ll << ' ' << r << ' ' << BOR::get(head[r], 0, (1 << BOR::LOG) - 1, px, BOR::LOG - 1, value) << endl;
 			if (pos)
			{
				ans -= BOR::get(head[pos-1], 0, (1 << BOR::LOG) - 1, px, BOR::LOG - 1, value);
			}
		}
	}
	else
	{
		FOR(rr, pos, r + 1)
		{
			int px = 0;
			px = pref[rr];
			//[l-1,pos-1]
			ans += BOR::get(head[pos-1], 0, (1 << BOR::LOG) - 1, px, BOR::LOG - 1, value);
		//	cout << l << ' ' << rr << ' ' << BOR::get(head[r], 0, (1 << BOR::LOG) - 1, px, BOR::LOG - 1, value) << endl;
			if (l-2>=0)
			{
				ans -= BOR::get(head[l - 2], 0, (1 << BOR::LOG) - 1, px, BOR::LOG - 1, value);
			}
		}
	}
	ans += solve(pos + 1, r, w);
	ans += solve(l, pos - 1, w);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ST::init();
	BOR::init();
	int last = BOR::build(0, (1 << BOR::LOG) - 1);
	cin >> n >> k;
	FOR(i, 0, n)
	{
		cin >> a[i];
		pref[i] = a[i];
		if (i)
			pref[i] ^= pref[i-1];
		head[i] = BOR::upd(last, 0, (1 << BOR::LOG) - 1, pref[i]);
		last = head[i];
	}
	ST::build(a, 1, 0, n - 1);
	LL l = 0, r = (1LL << BOR::LOG) * 50000;
	//r = 100;
	while (l < r)
	{
		LL m = (l + r) / 2;
		if (solve(0, n - 1, m) < k)
		{
			l = m+1;
		}
		else
		{
			r = m;
		}
	}
	if (solve(0, n - 1, l) < k)
	{
		return -1;
	}
	cout << l << endl;


	return 0;
}