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

const int INF = 1000 * 1000 * 1000;
const LL LINF = 1LL * INF * INF;
const int MAX = 100010;
const long double PI = acos(-1.);
const double EPS = 1e-6;
const LL MOD = INF + 7;

LL dp[1005];

LL matr[3][2] = { {1, 0}, {0, 1}, {2, 1} };
void init()
{
	dp[0] = 4;
	dp[1] = 7;
}
void brute(int n)
{
	FOR(i, 2, n + 1)
	{
		dp[i] = dp[i - 1] + 2*dp[i - 2];
		dp[i] %= MOD;
	}
}

struct vec
{
	LL a[2];
	void copy(const vec& v)
	{
		FOR(i, 0, 2)
		{
			a[i] = v.a[i];
		}
	}
};

void mult(vec& a, const vec& b)
{
	LL c[4];
	FILL(c, 0);
	FOR(i, 0, 2)
	{
		FOR(j, 0, 2)
		{
			c[i + j] = (c[i + j] + (a.a[i] * b.a[j]) % MOD) % MOD;
		}
	}
	RFOR(i, 4, 2)
	{
		c[i - 1] += 1 * c[i];
		c[i - 2] += 2 * c[i];
		c[i - 1] %= MOD;
		c[i - 2] %= MOD;
		c[i] = 0;
	}
	a.a[0] = c[0];
	a.a[1] = c[1];
}

vec a, b, c;

void binpow(int n) // in a, out b;
{
	int pw = 1;

	while (n)
	{
		if (pw <= 2)
		{
			FOR(i, 0, 2)
			{
				a.a[i] = matr[pw][i];
			}
		}
		pw *= 2;
		if (n % 2)
		{
			mult(b, a);
		}
		c.copy(a);
		mult(a, c);
		n /= 2;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	brute(100);
	b.a[0] = 1;
	b.a[1] = 0;
	binpow(53);
	LL cur = b.a[1] * dp[1] + b.a[0]*dp[0];
	cur %= MOD;
	FOR(i, 0, 100)
	{
		if (dp[i] == cur)
		{
			cout << i << endl;
		}
	}
	cout << dp[100] << ' ' << cur << endl;

	return 0;
}

