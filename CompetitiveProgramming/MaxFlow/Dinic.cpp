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

const int INF = 1000 * 1000 * 1000+47;
const LL LINF = 1LL * INF * INF;
const int MAX = 100010;
const long double PI = acos(-1.);
const double EPS = 1e-6;
const LL mod = INF + 7;

namespace Dinic
{
	int n;
	struct edge
	{
		int u, v, cap, flow;
	};
	vector<edge> e;
	vector<int> g[MAX];
	int d[MAX];
	int ptr[MAX];
	int s, t;
	int q[MAX];
	int power;
	void addEdge(int u, int v, int cap)
	{
		edge e1 = { u, v, cap, 0 };
		edge e2 = { v, u, 0, 0 };
		g[u].PB(e.size());
		e.PB(e1);
		g[v].PB(e.size());
		e.PB(e2);
	}

	bool bfs()
	{
		memset(d, -1, sizeof(int) * n);
		d[s] = 0;
		int qh = 0;
		int qt = 0;
		q[qt++] = s;
		while (qh != qt && d[t] == -1)
		{
			int u = q[qh++];
			int i = SZ(g[u]);
			while(i--)
			{
				int id = g[u][i];
				int v = e[id].v;
				if (e[id].cap - e[id].flow < power)
					continue;
				if (d[v] != -1)
					continue;
				d[v] = d[u] + 1;
				q[qt++] = v;

			}
		}
		return d[t] != -1;
	}

	int dfs(int u, int flow = INF)
	{
		if (!flow || u == t)
			return flow;
		int &j = ptr[u];
		while (j > 0)
		{
			j--;
			int id = g[u][j];
			int v = e[id].v;
			int cap = e[id].cap;
			int f = e[id].flow;
			if (d[v] != d[u] + 1)
				continue;
			if (cap - f < power)
				continue;
			int pushed = dfs(v, min(flow, cap - f));
			if (pushed)
			{
				e[id].flow += pushed;
				e[id ^ 1].flow -= pushed;
				return pushed;
			}
		}
		return 0;
	}

	LL dinic()
	{
		LL answer = 0;
		power = (1 << 30);
		while (power)
		{
			while (bfs())
			{
				LL cur = 0;
				FOR(i, 0, n)
				{
					ptr[i] = SZ(g[i]);
				}
				while (true)
				{
					int f = 0;
					f = dfs(s);
					if (!f)
						break;
					cur += f;
				}
				if (!cur)
					break;
				answer += cur;
			}
			power /= 2;
		}
		return answer;
	}
};



signed main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	Dinic::s = 0;
	FOR(i, 0, m)
	{
		int x, y, z;
		cin >> x >> y >> z;
		x--, y--;
		Dinic::addEdge(x, y, z);
		Dinic::addEdge(y, x, z);
	}
	Dinic::t = n-1;
	Dinic::n = Dinic::t+1;
	cout << Dinic::dinic() << endl;
	return 0;
}

