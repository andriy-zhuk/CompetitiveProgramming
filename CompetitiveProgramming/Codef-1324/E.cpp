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
typedef vector<int> VI;

const int INF = 1000 * 1000 * 1000;
const LL LINF = 1LL * INF * INF;
const int MAX = 100010;
const long double PI = acos(-1.);
const double EPS = 1e-6;
const LL MOD = INF + 7;

int n;
int h;
int l, r;
int dpT[2005][2005];
int a[2005];
int dp(int pos, int tim)
{
	if (pos == n)
	{
		return 0;
	}
	if (dpT[pos][tim] != -1)
	{
		return dpT[pos][tim];
	}
	int best = 0;
	FOR(i, 0, 2)
	{
		int cur = tim + a[pos] - i;
		cur %= h;
		best = max(best, dp(pos + 1, cur) + (cur >= l && cur <= r));
	}
	return dpT[pos][tim] = best;
}


int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> h >> l >> r;
	FOR(i, 0, n)
	{
		cin >> a[i];
	}
	FILL(dpT, -1);
	cout << dp(0, 0) << endl;
	return 0;
}

