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

// assignment on a segment, suma on a segment query
struct ST6
{
	int t[4 * MAX], n;
	int col[4 * MAX];
	int value(int v, int tl, int tr)
	{
		if (col[v] != -1)
			return (tr - tl + 1) * col[v];
		return t[v];
	}
	void push(int v)
	{
		if (col[v] != -1)
		{
			col[(v << 1)] = col[(v << 1) + 1] = col[v];
			col[v] = -1;
		}
	}

	void build(int a[], int v, int tl, int tr)
	{
		if (tl == tr)
		{
			t[v] = a[tl];
			col[v] = -1;
		}
		else
		{
			int tm = (tl + tr) >> 1;
			build(a, (v << 1), tl, tm);
			build(a, (v << 1) + 1, tm + 1, tr);
			t[v] = t[(v << 1)] + t[(v << 1) + 1];
			col[v] = -1;
		}
	}

	void assign(int v, int tl, int tr, int l, int r, int val)
	{
		if (l > r)
			return;
		if (tl == l && tr == r)
		{
			col[v] = val;
		}
		else
		{
			push(v);
			int tm = (tl + tr) >> 1;
			assign(v + v, tl, tm, l, min(tm, r), val);
			assign(v + v + 1, tm + 1, tr, max(tm + 1, l), r, val);
			t[v] = value(v + v, tl, tm) + value(v + v + 1, tm + 1, tr);
		}
	}

	int suma(int v, int tl, int tr, int l, int r)
	{
		if (l > r)
			return 0;
		if (tl == l && tr == r)
		{
			return value(v, tl, tr);
		}
		int tm = (tl + tr) >> 1;
		push(v);
		t[v] = value(v + v, tl, tm) + value(v + v + 1, tm + 1, tr);
		return
			suma(v + v, tl, tm, l, min(tm, r)) +
			suma(v + v + 1, tm + 1, tr, max(tm + 1, l), r);
	}
};

ST6 foo[26];
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	cin >> s;
	FOR(i, 0, SZ(s))
	{
		foo[s[i] - 'a'].assign(1, 0, n - 1, i, i, 1);
	}

	while (q--)
	{
		int l, r, k;
		cin >> l >> r >> k;
		l--, r--;
		int cur = 0;
		FOR(i, 0, 26)
		{
			int ii = i;
			if (!k)
				ii = 25 - i;
			int cnt = foo[ii].suma(1, 0, n - 1, l, r);
			foo[ii].assign(1, 0, n - 1, l, r, 0);
			foo[ii].assign(1, 0, n - 1, l + cur, l + cur + cnt - 1, 1);
			cur += cnt;
		}
	}
	FOR(i, 0, n)
	{
		FOR(j, 0, 26)
		{
			if (foo[j].suma(1, 0, n - 1, i, i))
			{
				cout << char(j + 'a');
				break;
			}
		}
	}

}

