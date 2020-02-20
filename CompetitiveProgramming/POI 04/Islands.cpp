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
const double EPS = 1e-12;
const LL mod = INF + 7;
struct elem;

struct point;

vector<elem> E;
vector<vector<point> > a;
struct point
{
	LL x;
	LL y;
	void turn()
	{
		LL nx, ny;
		nx = y + x;
		ny = y - x;
		x = nx;
		y = ny;
	}
};
double curTime;
struct segment
{
	int up;
	int down;
	int time;
	point A, B;
	segment(int _up, int _down, point _a, point _b, int _time) : up(_up), down(_down), A(_a), B(_b), time(_time) {};
	segment(point p, point q, int _up, int _down, int _time)
	{
		if (p.x > q.x)
			swap(p, q);
		A = p;
		B = q;
		up = _up;
		down = _down;
		time = _time;
	}

	LL get(LL x) const
	{
		if (A.x == B.x)
		{
			return A.y;
		}
		if (A.y < B.y)
		{
			return A.y + (x - A.x);
		}
		else
		{
			return A.y - (x - A.x);
		}
	}

	bool operator<(const segment& s) const
	{
		if (get(curTime) == s.get(curTime))
		{
			return time < s.time;
		}
		return get(curTime) < s.get(curTime);
	}
};


struct elem
{
	int x;
	int y;
	int typ() const
	{
		int yl = ((y - 1) + a[x].size()) % a[x].size();
		int yr = ((y + 1) + a[x].size()) % a[x].size();

		if (a[x][y].x < a[x][yl].x && a[x][y].x < a[x][yr].x)
			return 0; // opening type;

		if (a[x][y].x > a[x][yl].x&& a[x][y].x > a[x][yr].x)
			return 2; // closting type;

		return 1; // semi-open type;
	}

	bool operator<(const elem& e) const
	{
		if (a[x][y].x == a[e.x][e.y].x)
		{
			return a[x][y].y < a[e.x][e.y].y;
		}
		return a[x][y].x < a[e.x][e.y].x;
	}
};

set<int> g[MAX];
int par[MAX];


void read()
{
	int n;
	cin >> n;
	FOR(ii, 0, n)
	{
		vector<int> cur;
		vector<point> foo;
		foo.clear();
		cur.clear();
		int m;
		cin >> m;
		FOR(i, 0, m)
		{
			int x;
			cin >> x;
			cur.PB(x);
		}
		FOR(i, 0, m/2)
		{
			E.PB({ ii+1, (int)foo.size() });
			foo.PB({cur[i * 2], cur[i * 2 + 1] });
			foo.back().turn();
			E.PB({ ii+1, (int)foo.size() });
			foo.PB({ cur[(i * 2 + 2)%m], cur[i * 2 + 1] });
			foo.back().turn();
		}
		a.PB(foo);
	}
}

multiset<segment> st;


int counta = 1;
int used[MAX];
int dfs(int u)
{
	used[u] = 1;
	int best = 0;
	for (auto& v : g[u])
	{
		if (!used[v])
		{
			best = max(best, dfs(v) + 1);
		}
	}
	return best;
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	a.PB(vector<point>());
	read();

	// top edge
	st.insert({ 0, 0, {0, LINF}, {0, LINF}, -2 });
	// bot edge
	st.insert({ 0, 0, {0, -LINF}, {0, -LINF}, -1 });

	sort(ALL(E));
	
	FOR(i, 0, E.size())
	{
		int t = E[i].typ();
		int x = E[i].x;
		int y = E[i].y;
		int yl = (y - 1 + a[x].size()) % a[x].size();
		int yr = (y + 1 + a[x].size()) % a[x].size();
		curTime = a[x][y].x;
		if (t == 0)
		{
			auto it = st.begin();
			it = st.upper_bound({ a[x][y], a[x][y], 0, 0 , 0});
			int up = it->down;
			it--;
			int down = it->up;

			int inside = x;
			if (up == x)
			{
				inside = par[x];
			}
			else
			{
				g[up].insert(x);
				par[x] = up;
			}
			if (a[x][yl].y < a[x][yr].y)
			{
				swap(yl, yr);
			}
			st.insert({ a[x][y], a[x][yl], up, inside, i * 2 + (a[x][yl].y > a[x][yr].y) });
			st.insert({ a[x][y], a[x][yr], inside, down, i * 2 + (a[x][yl].y <= a[x][yr].y) });
		}
		if (t == 1)
		{
			auto it = st.begin();
			it = st.lower_bound({ a[x][y], a[x][y], 0, 0 , 0 });
			int up = it->up;
			int down = it->down;
			int time = it->time;
			st.erase(it);
			if (a[x][yl].x < a[x][yr].x)
				swap(yl, yr);
			st.insert({ a[x][y], a[x][yl], up, down, time });
		}
		if (t == 2)
		{
			auto it = st.begin();
			FOR(i, 0, 2)
			{
				it = st.lower_bound({ a[x][y], a[x][y], 0, 0 , 0 });
				st.erase(it);
			}
		}
	}

	
	cout << dfs(0) << endl;

	return 0;
}


