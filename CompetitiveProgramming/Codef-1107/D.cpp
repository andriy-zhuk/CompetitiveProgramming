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
int a[5205][5205];
int cur[5205][5205];

bool ok(int x)
{
	FOR(i, 0, n / x)
	{
		FOR(j, 0, n / x)
		{
			cur[i][j] = a[i * x][j * x];;
			FOR(i1, 0, x)
			{
				FOR(j1, 0, x)
				{
					if (cur[i][j] != a[i * x + i1][j * x + j1])
						return 0;
				}
			}
		}
	}
	return 1;
}
bool b[5205];
bool was[5205];
int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	FOR(i, 0, n)
	{
		FOR(j, 0, n/4)
		{
			char s;
			cin >> s;
			int x = s-'0';
			if (s >= 'A' && s <= 'Z')
				x = s - 'A' + 10;
			FOR(k, 0, 4)
			{
				if ((1 << k) & x)
				{
					a[i][j * 4 + (3 - k)] = 1;
				}
				else
				{
					a[i][j * 4 + (3 - k)] = 0;
				}
			}
		}
	}
	set<int> divs;
	int best = 1;
	was[1] = 1;
	b[1] = 1;
	for (int i = 1; i * i <= n; ++i)
	{
		if (n % i)
			continue;
		if (!was[i])
		{
			bool tok = false;
			FOR(j, 1, 5202)
			{
				if (i % j == 0 && was[i / j] == 1 && b[i / j] == 0)
				{
					tok = true;
					was[i] = true;
					break;
				}
			}
			if (!tok)
			{
				if (ok(i))
				{
					best = max(best, i);
					b[i] = true;
				}
			}
			was[i] = true;
		}
		i = n / i;
		if (!was[i])
		{
			bool tok = false;
			FOR(j, 1, 5202)
			{
				if (i % j == 0 && was[i / j] == 1 && b[i / j] == 0)
				{
					tok = true;
					was[i] = true;
					break;
				}
			}
			if (!tok)
			{
				if (ok(i))
				{
					best = max(best, i);
					b[i] = true;
				}
			}
			was[i] = true;
		}
		i = n / i;
	}
	
	cout << best << endl;
	return 0;
}