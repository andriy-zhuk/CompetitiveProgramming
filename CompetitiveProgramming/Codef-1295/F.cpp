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
const LL MOD = 998244353;
int n;
LL l[51];
LL r[51];

PII segm[51];

LL siz[202];

LL binpow(LL x, int n)
{
	LL res = 1;
	while (n)
	{
		if (n % 2)
		{
			res = res * x % MOD;
		}
		x = x * x % MOD;
		n /= 2;
	}
	return res;
}

LL ober(LL x)
{
	return binpow(x, MOD- 2);
}

LL fact[200];
LL oberfact[200];
int k;

LL C(int n, int k)
{
	if (n == 0)
		return 1;
	LL res = 1;
	FOR(i, 0, k)
	{
		res = res * (n - i) % MOD;
	}
	res = res * oberfact[k] % MOD;
	return res;
}

LL dpT[102][102];

LL dp(int pos, int segment)
{
	//cout << pos << ' ' << segment << endl;
	if (pos == n)
		return 1;
	if (segment < 0)
		return 0;
	if (dpT[pos][segment] != -1)
		return dpT[pos][segment];
	
	LL res = dp(pos, segment -1);
	FOR(d, pos+1, n+1)
	{
		//cout << segm[d - 1].first << ' ' << segment << ' ' << segm[d - 1].second << endl;
		if (not(segm[d-1].first <= segment && segment <= segm[d-1].second))
			break;
		
		LL cur = dp(d, segment - 1);
		//cout << d << ' ' << segment - 1 << ' ' << cur << '*' << C(siz[segment] - 1 + d - pos, d - pos) << endl;
		cur = cur * C(siz[segment]-1+d-pos, d - pos)%MOD;
		res = res + cur;
		if (res >= MOD)
			res -= MOD;
	}
	return dpT[pos][segment] = res;
}




int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	fact[0] = 1;
	oberfact[0] = 1;
	FOR(i, 1, 100)
	{
		fact[i] = fact[i - 1] * i % MOD;
		oberfact[i] = ober(fact[i]);
	}
	LL lower = 1;
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> l[i] >> r[i];
		r[i]++;
		lower = lower * 1LL*(r[i] - l[i]) % MOD;
	}
	FILL(dpT, -1);
	set<LL> foo;
	RFOR(i, n-1, 0)
	{
		l[i] = max(l[i], l[i + 1]);
	}

	FOR(i, 1, n)
	{
		r[i] = min(r[i], r[i - 1]);
	}
	FOR(i, 0, n)
	{
		foo.insert(l[i]);
		foo.insert(r[i]);
	}

	vector<LL> pos;
	for (auto& it : foo)
		pos.PB(it);

	k = foo.size() - 1;
	FOR(i, 0, pos.size()-1)
	{
		siz[i] = pos[i + 1] - pos[i];
	}

	FOR(i, 0, n)
	{
		int id1 = lower_bound(ALL(pos), l[i]) - pos.begin();
		int id2 = lower_bound(ALL(pos), r[i]) - pos.begin();
		segm[i] = MP(id1, id2 - 1);
	}
	LL ans = dp(0, k-1);
	ans = ans * ober(lower) % MOD;
	cout << ans << endl;
	
	return 0;
}

