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

int n, m;
int a[13][2005];
vector<pair<int, PII > > els;
int b[13][13];
int prec[(1 << 12)][13];
int cols;
int dpT[13][(1 << 12)];

void solve()
{
	FILL(b, 0);
	FILL(prec, 0);
	FILL(dpT, 0);
	els.clear();

	cin >> n >> m;
	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			cin >> a[i][j];
			els.PB(MP(a[i][j], MP(i, j)));
		}
	}
	sort(ALL(els));
	reverse(ALL(els));
	set<int> bohdan;
	FOR(i, 0, els.size())
	{
		if (bohdan.size() == n)
			break;
		bohdan.insert(els[i].second.second);
	}
	cols = 0;
	for (auto& iter : bohdan)
	{
		FOR(i, 0, n)
		{
			b[i][cols] = a[i][iter];
		}
		cols++;
	}
	FOR(j, 0, cols)
	{
		FOR(mask, 0, (1 << n))
		{
			int best = -INF;
			FOR(zdvyg, 0, n)
			{
				int cur = 0;
				FOR(i, 0, n)
				{
					int x = (i + zdvyg);
					if (x >= n)
						x -= n;
					if (mask & (1 << x))
					{
						cur += b[i][j];
					}
				}
				best = max(best, cur);
			}
			prec[mask][j] = best;
		}
	}


	FOR(i, 0, cols)
	{
		FOR(m1, 0, (1 << n))
		{
			dpT[i + 1][m1] = dpT[i][m1];
			for (int s = m1; s; s = (s - 1) & m1)
			{
				dpT[i + 1][m1 ^ s] = max(dpT[i + 1][m1 ^ s], dpT[i][m1] + prec[s][i]);
			}
		}
	}
	cout << dpT[cols][0] << endl;;
}


int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}

