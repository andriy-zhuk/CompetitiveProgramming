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
#define next nwnwene
int T;
int n;
int a[300005];
int b[300005];
vector<int> next[300005];
int c[300005];
int d[300005];
int pos[300005];

namespace F
{
	int n;
	vector<int> t;
	void init()
	{
		t.clear();
		t.assign(n, 0);
	}
	int sum(int r)
	{
		int result = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1)
			result += t[r];
		return result;
	}

	void inc(int i, int delta)
	{
		for (; i < n; i = (i | (i + 1)))
			t[i] += delta;
	}

}

void check()
{
	sort(c, c + n);
	sort(d, d + n);
	FOR(i, 0, n)
	{
		if (c[i] != d[i])
		{
			cout << "NO" << endl;
			return;
		}
	}
	RFOR(i, n, 0)
	{
		next[a[i]].PB(i);
	}
	FOR(i, 0, n)
	{
		pos[next[b[i]].back()] = i+1;
		next[b[i]].pop_back();
	}
	F::n = n + 1;
	F::init();
	bool ok = true;
	FOR(i, 0, n)
	{
		//cout << F::sum(a[i]) << '-' << pos[i] << endl;
		if (F::sum(a[i]) > pos[i])
		{
			ok = false;
		}
		F::inc(a[i], 1);
	}
	if (!ok)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
}


int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> T;
	while (T--)
	{
		cin >> n;
		FOR(i, 0, n)
		{
			cin >> a[i];
			c[i] = a[i];
		}
		FOR(i, 0, n)
		{
			cin >> b[i];
			d[i] = b[i];
		}
		check();
	}

	return 0;
}