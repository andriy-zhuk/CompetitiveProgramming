/*
	Let C[i][j] (i < j) is the ammount of money one have to pay if there are 2 consolidation points on ends of range [i, j]. (in point x[i] and point x[j])

	Calculation of C[i][j] can be simple done with O(n^2). I used prefix sums.

	Let's build unoptimal dp:
		dp[i][j] = min for (k < i): (dp[k][j-1] + c[k][i])
			where j is ammount of consolidation points we've used and i means that we've put some consolidation points to left of x[i] and none of them to the right.
			so, dp[i][j] is the minimum achievable value.
			dp[i][k] can be an answer if we move all mines from the right of x[i] to consolidation point x[i].
	To optimize it to O(n*k*logn) I used d&c optimization technique. It is close to TL, but still ACceptable.

	Also I used the following fact.
		Let ans[i][j] is some value k, when dp[i][j]'s minimum value is (dp[k][j-1] + c[k][i]).
		Intuitively it's clear that ans[i][j]<=ans[i][j+1].
		It might give some optimization (maybe yes, maybe not, I can't prove neither of them), though it wouldn't slow down a solution.
	I've used the following papers:
	https://cp-algorithms.com/dynamic_programming/divide-and-conquer-dp.html
	https://core.ac.uk/download/pdf/161439515.pdf
*/

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
int n, k;
LL w[5005];
LL x[5005];

LL prefwx[5005];
LL prefw[5005];
int ccnt = 0;

LL sumwx(int l, int r) // in range [l; r]
{
	LL res = 0;
	res += prefwx[r];
	if (l)
		res -= prefwx[l - 1];
	return res;
}

LL sumw(int l, int r)
{
	LL res = prefw[r];
	if (l)
		res -= prefw[l - 1];
	return res;
}

LL c[5005][5005];

LL dp[2][5005];
int best[2][5005];
int KK;
void dc(int l, int r, int al, int ar)
{
	if (l > r)
		return;
	int m = (l + r) >> 1;
	dp[KK][m] = LINF;
	best[KK][m] = -1;

	FOR(i, max(al, best[1 - KK][m]), min(m, ar) + 1)
	{
		if (dp[KK][m] > dp[1 - KK][i] + c[i][m])
		{
			dp[KK][m] = dp[1 - KK][i] + c[i][m];
			best[KK][m] = i;
		}
	}
	dc(l, m - 1, al, best[KK][m]);
	dc(m + 1, r, best[KK][m], ar);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> k;
	FOR(i, 0, n)
	{
		cin >> x[i] >> w[i];
	}
	FOR(i, 0, n + 1)
	{
		prefwx[i] = w[i] * x[i];
		prefw[i] = w[i];
		if (i)
		{
			prefwx[i] += prefwx[i - 1];
			prefw[i] += prefw[i - 1];
		}
	}

	FOR(i, 0, n)
	{
		int p = i;
		FOR(j, i, n)
		{
			while (p < j && x[p] * 2 <= (x[i] + x[j]))
				p++;
			// i, p-1; p, j;
			c[i][j] = 0;
			c[i][j] = sumwx(i, p - 1) - sumw(i, p - 1) * x[i];
			c[i][j] += sumw(p, j) * x[j] - sumwx(p, j);
		}
	}

	FOR(i, 0, n)
	{
		dp[1][i] = sumw(0, i) * x[i] - sumwx(0, i);
	}

	FOR(i, 2, k + 1)
	{
		KK = i % 2;
		dc(0, n, 0, n);
	}

	LL answer = LINF;
	FOR(i, 0, n)
	{
		answer = min(answer, dp[k % 2][i] + sumwx(i, n - 1) - sumw(i, n - 1) * x[i]);
	}

	cout << answer << endl;
	return 0;
}
