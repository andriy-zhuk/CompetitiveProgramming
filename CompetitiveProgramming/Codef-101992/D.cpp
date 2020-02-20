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
const int MAX = 100002;
const long double PI = acos(-1.);
const double EPS = 1e-6;
const LL MOD = INF + 7;
#define pref petro

int n;
LL a[100005];
LL pref[100005];
LL mob[100005];
int lp[100005];
vector<int> pr;
void prec()
{
	for (int i = 2; i < 100005; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < 100005; ++j)
			lp[i * pr[j]] = pr[j];
	}

	mob[1] = 1;
	FOR(i, 2, MAX+1)
	{
		if (lp[i / lp[i]] == lp[i])
			mob[i] = 0;
		else
			mob[i] = -mob[i/lp[i]];
	}
}


void solve()
{
	FILL(a, 0);
	cin >> n;
	FOR(i, 0, n)
	{
		int x;
		cin >> x;
		a[x]++;
	}
	LL ans = 0;
	FOR(d, 1, MAX + 1)
	{
		LL curva = 0;
		FOR(x, 1, MAX / d + 1)
		{
			LL cur = mob[x];
			if (cur < 0)
				cur += MOD;
			cur *= x;
			cur %= MOD;
			cur *= x;
			cur %= MOD;
			LL suma = 0;
			for (LL i = 1; i <= MAX / d / x; ++i)
			{
				suma = (suma + i * a[i * d * x] % MOD) % MOD;
			}
			cur *= suma;
			cur %= MOD;
			cur *= suma;
			cur %= MOD;
			curva += cur;
			if (curva >= MOD)
				curva -= MOD;
		}
		curva = (curva * d) % MOD;
		ans += curva;
		if (ans >= MOD)
			ans -= MOD;
	}
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	freopen("lcm.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	prec();
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}


	
	return 0;
}

