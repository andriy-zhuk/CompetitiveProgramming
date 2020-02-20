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
LL n, m, k;
LL a[300005];
LL mn[30][2];
LL pref[300005];


int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m >> k;
	FOR(i, 0, 2*m)
	{
		mn[i][0] = mn[i][1]= LINF;
	}
	FOR(i, 0, n)
	{
		cin >> a[i];
		pref[i] = a[i];
		if (i)
			pref[i] += pref[i - 1];
	}

	LL best = 0;
	FOR(r, 0, n)
	{
		LL curcha = 0;
		if (r)
			curcha += pref[r - 1];
		curcha += (m - r) / m * k;
		if (m - r < 0)
		{
			mn[(m - r) % m + m][0] = min(mn[(m - r) % m + m][0], curcha);
			mn[(m - r%m) % m + m][1] = min(mn[(m - r%m) % m + m][1], curcha-k);
		}
		else
		{
			mn[(m - r) % m+m][0] = mn[(m - r) % m + m][1] = min(mn[(m - r) % m+m][0], curcha);
		}

		LL cur = pref[r] - r / m * k;
		int j = 0;
		FOR(i, 1, 2*m)
		{
			int x = i - m;
			if (x + r % m < m)
			{
				if (mn[i][j] != LINF)
					best = max(best, cur - mn[i][j]);
			}
			else 
			{
				if (mn[i][j] != LINF)
					best = max(best, cur - (mn[i][j] + k));
			}
		}
		j = 1;
		FOR(i, 1, 2 * m)
		{
			int x = i - m;
			if (x + r % m < m)
			{
				if (mn[i][j] != LINF)
					best = max(best, cur - mn[i][j]);
			}
			else
			{
				if (mn[i][j] != LINF)
					best = max(best, cur - (mn[i][j] + k));
			}
		}

	}
	cout << best << endl;

	return 0;
}