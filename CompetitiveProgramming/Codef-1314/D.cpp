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
typedef vector<LL> VI;
typedef pair<LL, LL> PLL;

const unsigned int INF = 2100 * 1000 * 1000;
const LL LINF = 1LL * INF * INF;
const int MAX = 100010;
const long double PI = acos(-1.);
const double EPS = 1e-6;
const LL MOD = INF + 7;
int n, k;
int d[81][81];
vector<PII> path[81][81];

void init()
{
	multiset<pair<int, int> > foo;
	FOR(i, 0, n)
	{
		FOR(j, 0, n)
		{
			FOR(k, 1, n)
			{
				if (i == k || j == k)
					continue;
				path[i][j].PB(MP(d[i][k] + d[k][j], k));
			}
			sort(ALL(path[i][j]));
		}
	}
}
vector<int> a;
LL best = LINF;

void rec()
{	
	if (a.size() == k / 2)
	{
		a.PB(0);
		LL dist = 0;
		int aa = 0;
		FOR(i, 0, a.size() - 1)
		{
			int u = a[i];
			int v = a[i + 1];
			FOR(k, 0, path[u][v].size())
			{
				int w = path[u][v][k].second;
				bool ok = true;
				FOR(i, 0, a.size())
					if (w == a[i])
						ok = false;
				if (ok)
				{
					aa++;
					dist += path[u][v][k].first;
					break;
				}
			}
		}
		if (aa == a.size())
		{
			best = min(best, dist);
		}
		a.pop_back();
		return;
	}
	int last = a.back();
	FOR(i, 0, n)
	{
		a.push_back(i);
		rec();
		a.pop_back();
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> k;
	FOR(i, 0, n)
	{
		FOR(j, 0, n)
		{
			cin >> d[i][j];
		}
	}
	a.PB(0);
	init();
	
	
	rec();
	cout << best << endl;

	return 0;
}

