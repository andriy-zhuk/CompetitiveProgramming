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
const int MAX = 200010;
const long double PI = acos(-1.);
const double EPS = 1e-6;
const LL mod = INF + 7;
int n;
int a[200005];
struct ST
{
	int t[MAX];
	void push(int v, int tl, int tr)
	{
		if (tl == tr)
			return;
		if (t[v])
		{
			t[v + v] = t[v + v + 1] = t[v];
			t[v] = 0;
		}
	}

	void upd(int v, int tl, int tr, int l, int r, int val)
	{
		if (tl == l && tr == r)
		{
			t[v] = val;
			return;
		}
		push(v, tl, tr);
		int tm = (tl + tr) / 2;
		if (l >= tm + 1)
		{
			upd(v + v + 1, tm + 1, tr, l, r, val);
			return;
		}
		if (r <= tm)
		{
			upd(v + v, tl, tm, l, r, val);
			return;
		}
		upd(v + v, tl, tm, l, tm, val);
		upd(v + v + 1, tm + 1, tr, tm + 1, tr, val);
	}
	int get(int v, int tl, int tr, int pos)
	{
		if (tl == tr)
		{
			return t[v]; 
		}


	}
};
int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);


	return 0;
}

