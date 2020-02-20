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
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define RFOR(i,b,a) for(int i=b-1;i>=a;i--)
#define PB push_back
#define MP make_pair
#define SZ(a) (int)a.size()
#define f first
#define s second

typedef pair<int, int> PII;

const int maxn = 100 * 1000 + 7;
const int magic = 350;

int p[maxn];
int u[maxn];
vector<int> g[maxn];
int n;
int head[maxn];
int nxt[maxn];
int cnt = 0;
int e[maxn];
void build()
{
	FOR(I, 0, n + 1)
		u[I] = 0;
	FOR(i, 0, cnt)
	{
		nxt[i] = -1;
	}
	FOR(i, 0, n)
	{
		head[i] = -1;
	}
	cnt = 0;
	
	FOR(i, 0, n)
	{
		int u = p[i]; 
		int v = i;
		if (u == n)
		{
			continue;
		}
		nxt[cnt] = head[u];
		head[u] = cnt;
		e[cnt++] = v;
	}
}
PII to[maxn];
void dfs(int v, int root, int d = 0)
{
	to[v] = MP(root, d);
	int curva = head[v];
	while (curva != -1)
	{
		int to = e[curva];
		if (!u[to])	
			dfs(to, root, d + 1);
		curva = nxt[curva];
	}
}
int good[maxn];
PII query(int v)
{
	int ans = 0;
	while (!good[v])
	{
		ans++;
		v = p[v];
		PII x = to[v];
		ans += x.s;
		if (v > x.first)
		{
			exit(-1);
		}
		v = x.f;
	}
	return MP(v + 1, ans + 1);
}
	set<int> pts;
void prec()
{
	RFOR(i, n, 0)
	{
		if (p[i] != n || to[i].f != i)
			to[i] = MP(to[p[i]].f, to[p[i]].s + 1);
	}
}

int main()
{
	//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int m;
	cin >> n >> m;
	FOR(i, 0, n)
	{
		int a;
		cin >> a;
		p[i] = min(n, i + a);
		if (p[i] == n)
			good[i] = 1;
	}
	vector<pair<int, PII>> q;
	build();
	for (int i = 0; i < m; i += magic)
	{
		q.clear();
		pts.clear();
		FOR(j, i, min(i + magic, m))
		{
			int t;
			cin >> t;
			if (t)
			{
				int x;
				cin >> x;
				x--;
				q.PB(MP(1, MP(x, x)));
			}
			else
			{
				int a, b;
				cin >> a >> b;
				a--;
				pts.insert(a);
				q.PB(MP(0, MP(a, b)));
			}
		}
		FOR(j, 0, n)
			to[j] = MP(n, n);
		FOR(j, 0, n)
			if (good[j])
			{
				to[j] = MP(j, 0);
			}
		for (auto it : pts)
		{
			to[it] = MP(it, 0);
		}
		prec();
		FOR(j, 0, SZ(q))
		{
			if (q[j].f)
			{
				PII x = query(q[j].s.f);
				cout << x.f << " " << x.s << endl;
			}
			else
			{
				p[q[j].s.f] = min(n, q[j].s.f + q[j].s.s);
				if (p[q[j].s.f] == n)
					good[q[j].s.f] = 1;
				else
					good[q[j].s.f] = 0;
			}
		}
		build();
	}



	return 0;
}