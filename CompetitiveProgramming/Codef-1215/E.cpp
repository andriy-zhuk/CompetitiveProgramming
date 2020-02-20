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
int n;
int a[400005];
LL dpT[1 << 20];
LL cost[20][20];
LL val[20][1 << 20];

LL dp(int mask)
{
	if (mask == (1 << 20)-1)
	{
		return dpT[mask] = 0;
	}
	if (dpT[mask] != -1)
		return dpT[mask];

	LL best = LINF;
	FOR(i1, 0, 20)
	{
		if ((mask & (1 << i1)))
			continue;
		best = min(best, dp(mask | (1 << i1)) + val[i1][mask]);
	}
	return dpT[mask] = best;
}
int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	FOR(i, 0, n)
	{
		cin >> a[i];
		a[i]--;
	}
	FILL(dpT, -1);
	FOR(i1, 0, 20)
	{
		FOR(i2, 0, 20)
		{
			if (i1 == i2)
				continue;
			LL ans = 0;
			LL cnt = 0;
			RFOR(i, n, 0)
			{
				if (a[i] == i2)
				{
					cnt++;
				}
				if (a[i] == i1)
				{
					ans	+= cnt;
				}
			}
			cost[i1][i2] = ans;
		}
	}
	FOR(mask, 0, (1 << 20))
	{
		FOR(i1, 0, 20)
		{
			if ((mask & (1 << i1)))
				continue;
			LL cur = 0;
			FOR(i2, 0, 20)
			{
				if (i1 == i2)
					continue;
				if ((mask & (1 << i2)))
					continue;
				cur += cost[i1][i2];
			}
			val[i1][mask] = cur;
		}
	}
	cout << dp(0) << endl;

	return 0;
}