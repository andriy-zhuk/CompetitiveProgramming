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
const LL MOD = 998244353;

LL n;
vector<int> a[1000006];
LL cc[1000006];

LL binpow(LL a, LL x)
{
	LL res = 1;
	while (x)
	{
		if (x & 1)
		{
			res = res * a % MOD;
		}
		a = a * a % MOD;
		x /= 2;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	FOR(i, 0, n)
	{
		int x;
		cin >> x;
		while (x--)
		{
			int y;
			cin >> y;
			y--;
			a[i].PB(y);
			cc[y]++;
		}
	}
	LL answer = 0;
	FOR(i, 0, n)
	{
		FOR(j, 0, a[i].size())
		{
			LL x = a[i][j];
			LL cur = cc[x] * binpow(a[i].size(), MOD-2) % MOD * binpow(n*n%MOD, MOD-2) % MOD;
			answer = answer + cur;
			if (answer >= MOD)
				answer -= MOD;
		}
	}
	cout << answer << endl;


	return 0;
}

