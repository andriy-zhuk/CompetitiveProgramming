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
#define y0 sdpfosdpfo
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

LL x0, y0, ax, ay, bx, by;
LL t, xs, ys;

LL calcDist(pair<LL, LL> a, pair<LL, LL> b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

bool valid(LL x, LL a, LL b)
{
	//ax+b;
	double xx = x;
	double xa = xx * a + b;
	if (xa >= 1e17)
		return false;
	return true;
}

vector<pair<LL, LL>> foo;


int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
	pair<LL, LL> cur = MP(x0, y0);

	foo.PB(cur);
	FOR(i, 0, 56)
	{
		if (valid(cur.first, ax, bx) && valid(cur.second, ay, by))
		{
			cur.first = cur.first * ax + bx;
			cur.second = cur.second * ay + by;
			foo.PB(cur);
		}
		else
		{
			break;
		}
	}


	int best = 0;
	FOR(i, 0, foo.size())
	{
		LL dist = 0;
		int ans = 0;
		pair<LL, LL> cur =MP(xs,ys);
		FOR(j, i, foo.size())
		{
			dist += calcDist(cur, foo[j]);
			//cout << dist << ' ' << ans << endl;
			if (dist > t)
				break;
			cur = foo[j];
			ans++;
		}
		best = max(ans, best);
		dist = 0;
		ans = 0;
		cur = MP(xs, ys);
		RFOR(j, i+1, 0)
		{
			dist += calcDist(cur, foo[j]);
			//cout << dist << ' ' << ans << endl;
			if (dist > t)
				break;
			cur = foo[j];
			ans++;
		}
		FOR(j, i+1, foo.size())
		{
			dist += calcDist(cur, foo[j]);
			//cout << dist << ' ' << ans << endl;
			if (dist > t)
				break;
			cur = foo[j];
			ans++;
		}
		best = max(best, ans);
	}
	cout << best << endl;



	return 0;
}

