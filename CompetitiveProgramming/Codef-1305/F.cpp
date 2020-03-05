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
typedef vector<int> VI;

const int INF = 1000 * 1000 * 1000;
const LL LINF = 1LL * INF * INF;
const int MAX = 100010;
const long double PI = acos(-1.);
const double EPS = 1e-6;
const LL MOD = INF + 7;

int n;
LL a[200005];

LL get(LL x, LL y)
{
	if (x == x % y)
	{
		return y - x % y;
	}
	return min(x % y, y - x % y);
}

int lp[2000004+1];
vector<int> pr;
int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int N = 2000004;
	for (int i = 2; i <= N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
			lp[i * pr[j]] = pr[j];
	}
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	LL x = a[n / 2] + a[(n + 1) / 2 - 1];
	x /= 2;
	LL best = n;
	LL cur = 0;
	FOR(i, 0, n)
	{
		cur += get(a[i], x);
	}
	best = min(best, cur);
	auto t = clock();
	FOR(i, 0, SZ(pr))
	{
		if (i % 1000 == 0)
		{
			double cur = (double)(clock() - t) / CLOCKS_PER_SEC;
			if (cur >= 2.2)
			{
				cout << best << endl;
				return 0;
			}
		}
		LL cur = 0;
		FOR(j, 0, n)
		{
			cur += get(a[j], pr[i]);
			if (cur >= best)
				break;
		}
		best = min(best, cur);
	}
	cout << best << endl;


	return 0;
}

