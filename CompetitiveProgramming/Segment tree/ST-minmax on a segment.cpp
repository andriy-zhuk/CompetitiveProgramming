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

struct ST
{
	int n, t[4 * MAX];
	int trash[200];
	int DEFAULT = INF;

	void build(int a[], int v, int tl, int tr)
	{
		if (tl == tr)
		{
			t[v] = a[tl];
		}
		else
		{
			int tm = (tl + tr) >> 1;
			build(a, (v << 1), tl, tm);
			build(a, (v << 1), tm + 1, tr);
		}
	}

	int minimum(int v, int tl, int tr, int l, int r)
	{
		if (l > r)
			return DEFAULT;
		if (l == tr && r == tr)
			return t[v];
		int tm = (tl + tr) >> 1;
		return min(minimum((v << 1), tl, tm, l, min(r, tm)),
			minimum((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r));
	}

	void update(int v, int tl, int tr, int pos, int val)
	{
		if (tl == tr)
		{
			t[v] = val;
		}
		int tm = (tl + tr) >> 1;
		if (pos > tm)
			update((v << 1) + 1, tm + 1, tr, pos, val);
		else
			update((v << 1), tl, tm, pos, val);
		t[v] = min(t[(v << 1)], t[(v << 1) + 1]);
	}

	void u_update(int pos, int val)
	{
		int p = 0, v = 1, tl = 0, tr = n - 1;
		while (tl != tr)
		{
			trash[p++] = v;
			int tm = (tl + tr) >> 1;
			if (pos > tm)
			{
				v = (v << 1) + 1;
				tl = tm + 1;
			}
			else
			{
				v = (v << 1);
				tr = tm;
			}
		}
		t[v] = val;
		while (p)
		{
			v = trash[--p];
			t[v] = min(t[(v << 1)], t[(v << 1) + 1]);
		}
	}
};



int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	return 0;
}