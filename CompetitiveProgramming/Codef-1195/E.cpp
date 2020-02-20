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
const int MAX = 3003;
const long double PI = acos(-1.);
const double EPS = 1e-6;
const LL mod = INF + 7;

int n, m,a,b;
vector<vector<int> > h, mb;
LL g0, x, y, z;

struct ST2
{
	int t[4 * MAX];
	int DEFAULT = INF + 10;

	void build(const vector<int>& a, int v, int tl, int tr)
	{
		if (tl == tr)
		{
			t[v] = a[tl];
		}
		else
		{
			int tm = (tl + tr) >> 1;
			build(a, v+v, tl, tm);
			build(a, v+v+1, tm + 1, tr);
			t[v] = min(t[v+v], t[v + v + 1]);
		}
	}

	int minimum(int v, int tl, int tr, int l, int r)
	{
		if (l > r)
			return DEFAULT;
		if (l == tl && r == tr)
			return t[v];
		int tm = (tl + tr) >> 1;
		return min(minimum((v << 1), tl, tm, l, min(r, tm)),
			minimum((v << 1) + 1, tm + 1, tr, max(l, tm + 1), r));
	}
} foo;




int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m >> a >> b;
	cin >> g0 >> x >> y >> z;
	h.assign(n, vector<int>(m, 0));
	h[0][0] = g0;
	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			if (i || j)
			{
				h[i][j] = (g0 * x % z + y) % z;
				g0 = h[i][j];
			}
		}
	}
	mb.assign(m-b+1, vector<int>(n, 0));
	FOR(i, 0, n)
	{
		foo.build(h[i], 1, 0, m - 1);
		FOR(j, 0, m - b+1)
		{
			mb[j][i] = foo.minimum(1, 0, m - 1, j, j + b - 1);
		}
	}

	LL result = 0;
	FOR(j, 0, m - b+1)
	{
		foo.build(mb[j], 1, 0, n - 1);
		FOR(i, 0, n - a + 1)
		{
			result += foo.minimum(1, 0, n - 1, i, i + a - 1);
		//	cout << foo.minimum(1, 0, n - 1, i, i + a - 1) << ' ';
		}
	//	cout << endl;
	}
	cout << result << endl;
	return 0;
}