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

int n;
LL dpT[1000 * 1000 + 7][2];
LL dp(int n, int p)
{
	if (dpT[n][p] != -1)
		return dpT[n][p];
	if (n == 1)
		return dpT[n][p] = p == 1;
	if (n == 2)
		return dpT[n][p] = p == 0;
	if (n == 3)
		return dpT[n][p] = 0;
	
	dpT[n][p] = 0;
	if (n % 2)
	{
		if (p%2 == (n/2+1)%2)
			dpT[n][p] = dp(n / 2, 1 - (n / 2 + 1) % 2) * dp(n / 2, 0);
	}
	else
	{
		FOR(i, n / 2, n / 2 + 2)
		{
			if (i%2 == p)
				dpT[n][p] += dp(i - 1, 1 - (i % 2)) * dp(n - i, 0);
		}
	}
	return dpT[n][p];
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	FILL(dpT, -1);
	cout << dp(n, 0) + dp(n, 1) << endl;
	return 0;
}

