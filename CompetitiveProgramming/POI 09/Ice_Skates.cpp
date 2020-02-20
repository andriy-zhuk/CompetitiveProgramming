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
const int MAX = 200010;
const long double PI = acos(-1.);
const double EPS = 1e-6;
const LL mod = INF + 7;

LL n, m, k, d;
struct val
{
	LL suma, pref, suf, best;
};

val combine(val a, val b)
{
	val res;
	res.suma = a.suma + b.suma;
	res.pref = max(a.pref, a.suma + b.pref);
	res.suf = max(b.suf, b.suma + a.suf);
	res.best = max(a.best, b.best);
	res.best = max(res.best, a.suf + b.pref);
	return res;
}

struct ST
{
	val t[4 * MAX];
	void build(int v, int tl, int tr)
	{
		if (tl == tr)
		{
			t[v] = { -k, 0, 0, 0 };
			return;
		}
		int tm = (tl + tr) / 2;
		build(v + v, tl, tm);
		build(v + v + 1, tm + 1, tr);
		t[v] = combine(t[v + v], t[v + v + 1]);
	}

	val get(int v, int tl, int tr, int l, int r)
	{
		if (tl == l && tr == r)
		{
			return t[v];
		}
		int tm = (tl + tr) / 2;
		if (l >= tm + 1)
		{
			return get(v + v + 1, tm + 1, tr, l, r);
		}
		if (r <= tm)
		{
			return get(v + v, tl, tm, l, r);
		}
		return combine(
			get(v + v, tl, tm, l, tm),
			get(v + v + 1, tm + 1, tr, tm + 1, r)
		);
	}
	//a[pos]+=val;
	void upd(int v, int tl, int tr, int pos, int val)
	{
		if (tl == tr)
		{
			LL cur = t[v].suma + val;
			t[v] = { cur, max(cur, 0LL), max(cur, 0LL), max(cur, 0LL) };
			return;
		}
		int tm = (tl + tr) / 2;
		if (pos <= tm)
		{
			upd(v + v, tl, tm, pos, val);
		}
		else
		{
			upd(v + v + 1, tm + 1, tr, pos, val);
		}
		t[v] = combine(t[v + v], t[v + v + 1]);
	}

} q;

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m >> k >> d;
	q.build(1, 0, n - 1);
	FOR(i, 0, m)
	{
		int x, y;
		cin >> x >> y;
		x--;
		if (y != 0)
		{
			q.upd(1, 0, n - 1, x, y);
		}
		if (q.get(1, 0, n - 1, 0, n - 1).best <= 1LL * k * d)
		{
			cout << "TAK" << endl;
		}
		else
		{
			cout << "NIE" << endl;
		}
	}


	return 0;
}

