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

LL a, b;

LL mu[33] = {0, 1, -1, -1, 0, -1, 1, -1, 0, 0, 1, -1, 0, -1, 1, 1, 0, -1, 0, -1, 0, 1, 1, -1, 0, 0, 1, 0, 0, -1, -1, -1, 0 };

LL p2(int a, int b)
{
	LL cur = 1;
	FOR(i, 0, b)
	{
		cur *= a;
	}
	return cur;
}

LL sol1(int x)
{
	LL cnt = 0;
	FOR(i, 2, a+1)
	{
		if (pow(1.0*i, x) >= 1e12)
		{
			break;
		}
		if (p2(i, x) > a)
		{
			break;
		}
		cnt++;
	}
	return cnt;

}

LL sol2(int x)
{
	return b / x;
}

LL brute()
{
	set<LL> foo;
	FOR(i, 1, a+1)
		FOR(j, 1, b + 1)
	{
		foo.insert(p2(i, j));
	}
	return foo.size();
}


LL solve()
{
	LL ans = (a - 1) * b + 1;

	FOR(i, 2, 5)
	{
		cout << mu[i] << ' ' << sol1(i) << ' ' << sol2(i) << endl;
		ans += mu[i] * sol1(i) * sol2(i);
	}
	return ans;
}


int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t = 100;
	FOR(iii, 0, t)
	{
		cin >> a >> b;
		cout << brute() << ' ' << solve() << endl;
	}
	






	return 0;
}

