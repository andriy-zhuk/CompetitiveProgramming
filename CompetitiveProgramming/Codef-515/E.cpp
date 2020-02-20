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


LL pref[MAX];
LL d[MAX];
LL h[MAX];
const pair<LL, int> DEFAULT = MP(-LINF, -1);
pair<LL, int> a[4];
struct ST
{
	pair<LL, int> t[4 * MAX][2];
	pair<pair<LL, int>, pair<LL, int> > combine(const pair<pair<LL, int>, pair<LL, int> > &l, const pair<pair<LL, int>, pair<LL, int> > &r)
	{
		a[0] = l.first, a[1] = l.second, a[2] = r.first, a[3] = r.second;
		FOR(i, 0, 4)
		{
			if (a[i] > a[0])
				swap(a[i], a[0]);
		}
		FOR(i, 1, 4)
		{
			if (a[i] > a[1])
				swap(a[1], a[i]);
		}
		return MP(a[0], a[1]);
	}
	void build(bool flag, int v, int tl, int tr)
	{
		if (tl == tr)
		{
			t[v][0].f = 2LL * h[tl];
			t[v][0].second = tl;
			if (tl)
			{
				if (flag)
				{
					t[v][0].f += pref[tl - 1];
				}
				else
				{
					t[v][0].f -= pref[tl - 1];
				}
			}
			t[v][1] = DEFAULT;
		}
		else
		{
			int tm = (tl + tr) >> 1;
			build(flag, v + v, tl, tm);
			build(flag, v + v + 1, tm + 1, tr);
			auto xxx = combine(MP(t[v+v+1][0], t[v+v+1][1]), MP(t[v+v][0], t[v+v][1]));
			t[v][0] = xxx.f, t[v][1] = xxx.second;
		}
	}

	pair<pair<LL, int>, pair<LL, int> > get(int v, int tl, int tr, int l, int r)
	{
		if (l > r)
			return MP(DEFAULT, DEFAULT);
		if (tl == l && r == tr)
		{
			return MP(t[v][0], t[v][1]);
		}
		int tm = (tl + tr) >> 1;
		get(v + v, tl, tm, l, min(r, tm));
		get(v + v + 1, tm + 1, tr, max(l, tm + 1), r);
		return combine(get(v + v, tl, tm, l, min(r, tm)), get(v + v + 1, tm + 1, tr, max(l, tm + 1), r));
	}
} foo, goo;

int n, m;

LL ans(int l, int r)
{
	pair<pair<LL, int>, pair<LL, int> > L, R;
	L = foo.get(1, 0, n - 1, l, r);
	R = goo.get(1, 0, n - 1, l, r);
	//cout << L.first.first << ' ' << L.second.first << '+' << R.first.first << ' ' << R.second.first << endl;
	if (L.first.second != R.first.second)
	{
		return L.first.first + R.first.first;
	}
	return max(L.second.first + R.first.first, L.first.first + R.second.first);
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	FOR(i, 0, n)
	{
		cin >> d[i];
		d[i + n] = d[i];
	}
	pref[0] = d[0];
	FOR(i, 1, 2 * n)
	{
		pref[i] = d[i] + pref[i - 1];
	}
	FOR(i, 0, n)
	{
		cin >> h[i];
		h[i + n] = h[i];
	}
	n *= 2;
	foo.build(1, 1, 0, n - 1);
	goo.build(0, 1, 0, n - 1);
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		int l, r;
		if (a <= b)
		{
			l = b+1, r = a + (n / 2)-1;
		}
		else
		{
			l = b+1, r = a-1;
		}
		cout << ans(l, r) << endl;
	}

	return 0;
}