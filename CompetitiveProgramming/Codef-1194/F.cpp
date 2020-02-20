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
#define time timesdsdfsdfsdf
int n;
LL time;
LL t[200005];
LL pref[200005];

LL fact[200005];
LL oberfact[200005];

LL binpow(LL x, LL n)
{
	LL res = 1;
	while (n)
	{
		if (n&1)
		{
			res *= x;
			res %= mod;
		}
		x *= x;
		x %= mod;
		n /= 2;
	}
	return res;
}

LL C(int n, int k)
{
	return fact[n] * oberfact[k] % mod * oberfact[n - k] % mod;
}


int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> time;

	FOR(i, 0, n)
	{
		cin >> t[i];
		pref[i] = t[i];
		if (i)
			pref[i] += pref[i - 1];
	}
	fact[0] = 1;
	FOR(i, 1, 200005)
	{
		fact[i] = fact[i - 1] * i % mod;
	}
	oberfact[200003] = binpow(200004, mod - 2);
	RFOR(i, 200003, 1)
	{
		oberfact[i] = binpow(fact[i], mod - 2);
	}
	oberfact[0] = 1;

	LL answer = 0;

	FOR(eps, 0, n)
	{
		int k = lower_bound(pref, pref + n, time - eps) - pref;
		if (k < eps)
		{
			break;
		}
		cout << k << ' ' << eps << endl;
		cout << C(k, eps) << '+' << binpow(2, k) << endl;
		LL cur = C(k, eps)*binpow(binpow(2, k), mod - 2) % mod*(k+1)%mod;
		answer += cur;
		if (answer >= mod)
			answer -= mod;
	}
	cout << answer << endl;

	return 0;
}