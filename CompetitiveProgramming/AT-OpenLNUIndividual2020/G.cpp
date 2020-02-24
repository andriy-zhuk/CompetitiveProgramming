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
int n;

int dst(int i, int j)
{
	if (j < i)
		swap(i, j);
	return min(j - i, i + n - j);
}
vector<PII> e;
int cnt[1000006];
int cnt2[1000006];
int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	FOR(i, 0, n-3)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		if (x > y)
			swap(x, y);
		int d = dst(x, y);
		if (d%2 == 1)
		{
			cout << "No" << endl;
			return 0;
		}
		cnt[d]++;
		if (d == n/2)
			e.PB(MP(x, y));
	}
	sort(ALL(e));
	int r = 0;
	FOR(i, 0, e.size())
	{
		if (i && e[i].first != e[i-1].first && e[i].first < r)
		{
			cout << "No" << endl;
			return 0;
		}
		r = e[i].second;
	}
	bool ok = false;
	FOR(i, 0, 21)
	{
		if ((1 << i) == n)
			ok = true;
	}
	int x = 2;
	while (x*2 <= n)
	{
		if (cnt[x] != n / x)
		{
			cout << "No" << endl;
			return 0;
		}
		x *= 2;
	}
	cout << "Yes" << endl;



	return 0;
}

