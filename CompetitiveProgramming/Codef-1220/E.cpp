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
int n, m,s;
vector<int> g[200005];
int w[200005];
int is[200005];
vector<pair<vector<int>, LL> > tail;
int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	FOR(i, 0, n)
	{
		cin >> w[i];
	}
	FOR(i, 0, m)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].PB(y);
		g[y].PB(x);
	}
	cin >> s;
	s--;
	vector<int> q;
	FOR(i, 0, n)
	{
		if (g[i].size() == 1)
			q.PB(i);
	}
	while (q.size())
	{
		vector<int> cur;
		cur.clear();
		int u = q.back();
		q.pop_back();
		int p = -1;
		int nxt = -1;
		while (is[u] == 0 && SZ(g[u]) <= 2)
		{
			cur.PB(u);
			is[u] = 1;
			FOR(i, 0, g[u].size())
			{
				int v = g[u][i];
				if (v == p)
					continue;
				nxt = v;
			}
			p = u;
			u = nxt;
		}
		LL suma = 0;
		FOR(i, 0, cur.size())
		{
			suma += w[cur[i]];
		}
		if (cur.size())
			tail.PB(MP(cur, suma));
	}
	LL sumaAll = 0;
	LL cntcnt = 0;
	FOR(i, 0, n)
	{
		if (is[i] == 0)
		{
			sumaAll += w[i];
			cntcnt++;
		}
	}
	LL answer = sumaAll;
	vector<LL> tails;
	FOR(i, 0, tail.size())
	{
		tails.PB(tail[i].s);
	}
	sort(ALL(tails));
	reverse(ALL(tails));

	if (is[s] == 0)
	{
		LL curv = 0;
		FOR(i, 0, min(1, SZ(tails)))
			curv += tails[i];
		curv += sumaAll;
		cout << curv << endl;
		return 0;
	}
	tails.clear();
	int index = -1;
	LL important = 0;
	LL rest = 0;
	FOR(i, 0, SZ(tail))
	{
		LL sum1 = 0;
		LL sum2 = 0;
		bool ok = false;
		FOR(j, 0, tail[i].first.size() )
		{
			int u = tail[i].first[j];
			sum1 += w[u];
			if (u == s)
			{
				ok = true;
				answer = max(answer, sum1);
			}
			if (ok)
			{
				sum2 += w[u];
			}
		}
		if (!ok)
		{
			tails.PB(sum1);
		}
		else
		{
			answer = max(answer, sum2);
			rest = sum2;
			important = sum1;
		}
	}
	sort(ALL(tails));
	reverse(ALL(tails));
	LL curv = 0;
	FOR(i, 0, min(1, SZ(tails)))
		curv += tails[i];

	answer = max(answer, rest + sumaAll + curv);
	if (cntcnt)
		answer = max(answer, important + sumaAll);
	//answer = max(answer, important);
	cout << answer << endl;


	return 0;
}



