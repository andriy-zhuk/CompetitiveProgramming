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

const int INF = 1000 * 1000 * 1000;
const LL LINF = 1LL * INF * INF;
const int MAX = 100010;
const long double PI = acos(-1.);
const double EPS = 1e-6;
const LL MOD = INF + 7;
int n, m, q;
int a[303][303];
int ans[2000006];

struct ev
{
	int time;
	int typ; // typ == 1 -> close, 0 == open
	int x;
	int y;
	int susidy[4];
	bool operator<(const ev& e) const
	{
		return MP(time, typ) < MP(e.time, e.typ);
	}
};
vector<ev> e[2000006];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int make(int x, int y)
{
	return x * m + y;
}

namespace DSU
{
	int parent[303 * 303];
	int rank[303 * 303];
	void make_set(int v) {
		parent[v] = v;
		rank[v] = 0;
	}
	void init()
	{
		FOR(i, 0, n * m)
			make_set(i);
	}

	int find_set(int v) {
		if (v == parent[v])
			return v;
		return parent[v] = find_set(parent[v]);
	}

	void union_sets(int a, int b) {
		a = find_set(a);
		b = find_set(b);
		if (a != b) {
			if (rank[a] < rank[b])
				swap(a, b);
			parent[b] = a;
			if (rank[a] == rank[b])
				++rank[a];
		}
	}

	bool equal(int u, int v)
	{
		return find_set(u) == find_set(v);
	}

}

bool ok(int x, int y)
{
	return min(x, y) >= 0 && x < n && y < m;
}
vector<pair<PII, int> > zap;
int old[2000006];
int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m >> q;

	FOR(i, 0, q)
	{
		int x, y, c;
		cin >> x >> y >> c;
		x--, y--;
		zap.PB(MP(MP(x, y), c));
	}
	FOR(ii,0,2)
	{
		FOR(i, 0, zap.size())
		{
			int x = zap[i].first.first;
			int y = zap[i].first.second;
			int c = zap[i].second;
			if (a[x][y] == c)
			{
				continue;
			}
			if (!i)// || c != zap[i - 1].second)
			{
				DSU::init();
				FOR(x, 0, n)
				{
					FOR(y, 0, m)
					{
						int u = make(x, y);
						FOR(k, 0, 4)
						{
							int nx = x + dx[k];
							int ny = y + dy[k];
							int v = make(nx, ny);
							if (!ok(nx, ny))
								continue;
							if (a[x][y] == a[nx][ny] && DSU::equal(u, v) == false)
							{
								DSU::union_sets(u, v);
							}
						}
					}
				}
			}
			int curva = 1;
			int u = make(x, y);
			FOR(k, 0, 4)
			{
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (!ok(nx, ny))
					continue;
				int v = make(nx, ny);
				int c2 = a[nx][ny];
				if (c != c2)
				{
					continue;
				}
				if (!DSU::equal(u, v))
				{
					DSU::union_sets(u, v);
					curva--;
				}
			}
			if (ii == 0)
			{
				ans[i] += curva;
				zap[i].second = a[x][y];
			}
			else
			{
				ans[SZ(zap) - 1 - i] -= curva;
			}
			a[x][y] = c;
		}
		reverse(ALL(zap));
	}

	int cur = 1;
	FOR(i, 0, q)
	{
		cur += ans[i];
		cout << cur << endl;
	}

	return 0;
}

