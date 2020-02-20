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
const int MAX = 300010;
const long double PI = acos(-1.);
const double EPS = 1e-6;
const LL mod = INF + 9;

int fib[MAX];
int prefib[MAX];
int pref[MAX];
int n;
int a[MAX];


struct ST
{
	int a1[MAX*4], a2[MAX*4];
	int t[4 * MAX];

	int getFib(int n, int a, int b)
	{
		if (n == 1)
			return a;
		if (n == 2)
			return (1LL*a + b) % mod;
		return (1LL*fib[n - 1] * a % mod + 1LL*fib[n-2] * b % mod) % mod;
	}

	int getFibOnSegment(int a, int b, int n)
	{
		if (n == 1)
			return ;
		if (n == 2)
			return;
	}

	void push(int v, int tl, int tr)
	{
		if (!a1[v] && !a2[v])
			return;
		a1[v + v] += a1[v];
		if (a1[v + v] >= mod)
			a1[v + v] -= mod;
		a2[v + v] += a2[v];
		if (a2[v + v] >= mod)
			a2[v + v] -= mod;
		a1[v + v + 1] += getFib((tr - tl + 1), a1[v], a2[v]);
		a2[v + v + 1] += getFib((tr - tl), a1[v], a2[v]);
		if (a1[v + v + 1] >= mod)
			a1[v + v + 1] -= mod;
		if (a2[v + v + 1] >= mod)
			a2[v + v + 1] -= mod;
		a1[v] = 0;
		a2[v] = 0;
	}

	int getSuma(int v, int l, int r)
	{
		if (l > r)
			return 0;
		return t[v]+;
	}

	void update(int v, int tl, int tr, int l, int r, int a, int b)
	{
		if (l > r)
			return;
		if (l == tl && r == tr)
		{
			a1[v] += a;
			if (a1[v] >= mod) a1[v] -= mod;
			a2[v] += b;
			if (a2[v] >= mod) a2[v] -= mod;
		}
		else
		{
			int tm = (tl + tr) >> 1;
			push(v, tl, tm);
			update(v + v, tl, tm, l, min(tm, r), a, b);
			update(v + v + 1, tm + 1, tr, max(tm + 1, l), r, a, b);
			t[v] = getSuma(v + v, tl, tm) + getSuma(v + v + 1, tm+1, tr);
			if (t[v] >= mod)
				t[v] -= mod;

		}
	}

	int get(int v, int tl, int tr, int l, int r)
	{
		if (l > r)
			return 0;
		if (l == tl && r == tr)
		{
			return getSuma(v, tl, tr);
		}
		int tm = (tl + tr) >> 1;
		push(v, tl, tm);
		t[v] = getSuma(v + v, tl, tm) + getSuma(v + v + 1, tm + 1, tr);
		if (t[v] >= mod)
			t[v] -= mod;
		return (get(v + v, tl, tm, l, min(tm, r)) + get(v + v + 1, tm + 1, tr, max(tm + 1, r), r)) % mod;
	}
} foo;


int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int m;
	cin >> n;
	cin >> m;
	FOR(i, 0, n)
	{
		cin >> a[i];
		pref[i] = a[i];
		if (i)
			pref[i] += pref[i - 1];
		if (pref[i] >= mod)
			pref[i] -= mod;
	}
	fib[0] = 0;
	fib[1] = 1;
	prefib[0] = 0;
	prefib[1] = 1;
	FOR(i, 2, MAX)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
		if (fib[i] >= mod)
			fib[i] -= mod;
		prefib[i] = prefib[i - 1] + fib[i];
		if (prefib[i] >= mod)
			prefib[i] -= mod;
	}

	while (m--)
	{
		int z, l, r;
		cin >> z >> l >> r;
		l--, r--;
		if (z == 1)
		{
			foo.update(1, 0, n - 1, l, r, 1, 0);
		}
		else
		{
			int res = pref[r];
			if (l)
				res = res + mod - pref[l - 1];
			if (res >= mod) res -= mod;
			res += foo.get(1, 0, n - 1, l, r);
			if (res >= mod)
				res -= mod;
			cout << res << endl;
		}
	}


	return 0;
}