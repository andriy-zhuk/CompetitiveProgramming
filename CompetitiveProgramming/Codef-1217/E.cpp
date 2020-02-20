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
const int LINF = INF + INF;
const int MAX = 100010;
const long double PI = acos(-1.);
const double EPS = 1e-6;
const LL mod = INF + 7;

struct num
{
	int x;
	int pos;
};

num combine(num a, num b)
{
	if (a.x < b.x)
		return a;
	if (b.x < a.x)
		return b;
	if (a.pos < b.pos)
		return a;
	return b;
}

struct ST
{
	num t[4 * 200005];

	num get(int v, int tl, int tr, int l, int r)
	{
		if (tl == l && tr == r)
			return t[v];
		int tm = (tl + tr) / 2;
		if (r <= tm)
		{
			return get(v + v, tl, tm, l, r);
		}
		if (l >= tm + 1)
		{
			return get(v + v + 1, tm + 1, tr, l, r);
		}
		return combine(get(v + v, tl, tm, l, tm), get(v + v + 1, tm + 1, tr, tm + 1, r));
	}

	void upd(int v, int tl, int tr, int pos, int val)
	{
		if (tl == tr)
		{
			t[v] = { val, pos };
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
} q[10];
int n, m;
int t[200005];

int get(int d, int l, int r, int m)
{
	int ans = LINF;
	if (m - l > 0)
	{
		ans = min(ans, q[d].get(1, 0, n - 1, l, m - 1).x);
	}
	if (r - m > 0)
	{
		ans = min(ans, q[d].get(1, 0, n - 1, m + 1, r).x);
	}
	return ans;
}


int main()
{
	//ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//cin.tie(0);
	scanf("%d %d", &n, &m);
	FOR(i, 0, 10)
	{
		FOR(j, 0, n)
		{
			q[i].upd(1, 0, n - 1, j, INF);
		}
	}
	FOR(ii, 0, n)
	{
		int x;
		scanf("%d", &x);
		t[ii] = x;
		int i = 0;
		while(x)
		{
			if (x%10 != 0)
			{
				q[i].upd(1, 0, n - 1, ii, t[ii]);
			}
			else
			{
				q[i].upd(1, 0, n - 1, ii, INF);
			}
			i++;
			x /= 10;
		}
	}
	while (m--)
	{
		int typ;
		scanf("%d", &typ);
		if (typ == 1)
		{
			int ii, x;
			scanf("%d %d", &ii, &x);
			ii--;
			int i = 0;
			t[ii] = x;
			while (x)
			{
				if (x % 10 != 0)
				{
					q[i].upd(1, 0, n - 1, ii, t[ii]);
				}
				else
				{
					q[i].upd(1, 0, n - 1, ii, INF);
				}
				i++;
				x /= 10;
			}
		}
		else
		{
			int l, r;
			scanf("%d %d", &l, &r);
			l--, r--;
			if (l == r)
			{
				printf("-1\n");
				continue;
			}
			int ans = LINF;
			FOR(dig, 0, 9)
			{
				num fst = q[dig].get(1, 0, n - 1, l, r);
				if (fst.x == INF)
					continue;
				int snd = get(dig, l, r, fst.pos);
				if (snd == INF)
					continue;
				//cout << fst.x << ' ' << snd << endl;
				int cur = min(LINF, snd + fst.x);
				ans = min(ans, cur);
			}
			if (ans == LINF)
			{
				ans = -1;
			}
			printf("%d\n", ans);
		}
	}

	return 0;
}