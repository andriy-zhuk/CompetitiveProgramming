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
#include <queue> 

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

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef pair<LL, LL> PLL;

const int INF = 1000 * 1000 * 1000;
const LL LINF = 1LL * INF * INF;
const int MAX = 100010;
const long double PI = acos(-1.);
const double EPS = 1e-6;
const LL MOD = INF + 7;

struct ST
{
	LL g[4 * 200005];
	LL t[4 * 200005];
	LL get(int v, int tl, int tr)
	{
		return g[v] + t[v];
	}

	void upd(int v, int tl, int tr, int l, int r)
	{
		if (l == tl && r == tr)
		{
			g[v] += tr-tl+1;
			return; 
		}
		int tm = (tl + tr) / 2;
		if (l >= tm + 1)
		{
			upd(v + v + 1, tm + 1, tr, l, r);
		}
		else if (r <= tm)
		{
			upd(v + v, tl, tm, l, r);
		}
		else
		{
			upd(v + v, tl, tm, l, tm);
			upd(v + v + 1, tm + 1, tr, tm + 1, r);
		}
		t[v] = get(v + v, tl, tm) + get(v + v + 1, tm + 1, tr);
	}

	LL get(int v, int tl, int tr, int l, int r)
	{
		if (l == tl && r == tr)
		{
			return g[v];
		}
		int tm = (tl + tr) / 2;
		if (l >= tm + 1)
		{
			return g[v] + get(v + v + 1, tm + 1, tr, l, r);
		}
		else if (r <= tm)
		{
			return g[v] + get(v + v, tl, tm, l, r);
		}
		else
		{
			return g[v] + get(v + v, tl, tm, l, tm) + get(v + v + 1, tm + 1, tr, tm + 1, r);
		}
	}
} q;


string s, a, b;
int n, m;

vector<int> zet(string& s) {
	int n = (int)s.length();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	return z;
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	cin >> a >> b >> s;
	a = s + a;
	VI az = zet(a);

	reverse(ALL(az));

	FOR(i, 0, m)
	{
		az.pop_back();
	}
	reverse(ALL(az));

	reverse(ALL(b));
	reverse(ALL(s));
	b = s + b;
	VI bz = zet(b);
	reverse(ALL(bz));
	FOR(i, 0, m)
	{
		bz.pop_back();
	}
	reverse(ALL(bz));

	FOR(i, 0, bz.size())
	{
		int r = m-1;
		int l = m - bz[i];
		if (l > r)
		{
			continue;
		}
		q.upd(1, 0, m - 1, l, r);
	}

	LL ans = 0;
	FOR(i, 0, az.size())
	{
		int l = 0;
		int r = az[i] - 1;

		if (l > r)
			continue;

		ans += q.get(1, 0, m - 1, l, r);
	}

	cout << ans << endl;
















	return 0;
}

