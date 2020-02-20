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

int n, m;
int s[5003], r[5003];

int f[5003];
int h[5003];

int c[5003][2];
vector<int> foo[5003];
vector<int> typ[5003];

LL prec[5005][4]; // typ, x, 0 = a+b, 1 = b+c, 2 = abc, 3 = equal x;

pair<LL, LL> dpT[5005];

pair<LL, LL> dp(int f)
{
	if (f == -1)
	{
		return MP(0, 1);
	}
	if (dpT[f] != MP(-1LL, -1LL))
		return dpT[f];

	pair<LL, LL> cur = dp(f - 1);
	

	if (prec[f][2] != 0)
	{
		cur.first += 2;
		cur.second = cur.second * prec[f][2] % MOD;
	}
	else
	{
		if (prec[f][0] != 0 || prec[f][1] != 0)
		{
			cur.first++;
			cur.second = cur.second * ((prec[f][0] + prec[f][1])%MOD)%MOD;
		}
	}
	return dpT[f] = cur;
}



int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	FOR(i, 0, n)
	{
		cin >> s[i];
		s[i]--;
		foo[s[i]].PB(i);
	}
	FOR(i, 0, m)
	{
		cin >> f[i] >> h[i];
		f[i]--;
		typ[f[i]].PB(i);
		c[i][0] = -1;
		if (foo[f[i]].size() >= h[i])
		{
			c[i][0] = foo[f[i]][h[i]-1];
		}
		c[i][1] = -1;
		if (foo[f[i]].size() >= h[i])
		{
			c[i][1] = foo[f[i]][(int)foo[f[i]].size() - h[i]];
		}
		//cout << c[i][0] << ' ' << c[i][1] << endl;
	}
	// typ, x, 0 = a+b, 1 = b+c, 2 = abc, 3 = equal x;

	pair<LL, LL> best = MP(0, 1);
	FOR(x, 0, n)
	{
		FILL(prec, 0);
		LL b1 = 0;
		FOR(f, 0, n)
		{
			LL a1 = 0, a2 = 0, a3 = 0, a4 = 0;
			FOR(i, 0, typ[f].size())
			{
				cout << typ[f][i] << '+' << c[typ[f][i]][0] << ' ' << c[typ[f][i]][1]  << endl;
				if (c[typ[f][i]][0] == x || c[typ[f][i]][1] == x)
				{
					a4++;
				}
				if (c[typ[f][i]][0] != -1 && c[typ[f][i]][0] < x)
				{
					a1++;
				}
				if (c[typ[f][i]][1] > x)
				{
					a3++;
				}
				if (c[typ[f][i]][0] && c[typ[f][i]][0] < x && c[typ[f][i]][1] > x)
				{
					a1--, a3--, a2++;
				}
			}
			prec[f][0] = a1 + a2;
			prec[f][1] = a2 + a3;
			prec[f][2] = a1 * (a2 + a3) + a3 * (a1 + a2) + (a2 - 1) * a2;
			prec[f][3] = a4;
			if (a4 != 0)
			{
				cout << f << ' ' << a4 << ' ' << x << endl;
			}
			b1 += a4;
		}
		FILL(dpT, -1);
		if (b1 == 0)
			continue;
		pair<LL, LL> val = dp(n-1);
		val.first++;
		val.second = val.second * b1 % MOD;	
		cout << x << ' ' << b1 << ' ' << val.first << ' ' << val.second << endl;
		best = max(best, val);
	}

	cout << best.first << ' ' << best.second << endl;



	return 0;
}

