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

LL suma(LL l, LL r, LL step)
{
	LL n = (r - l) / step + 1;
	return n * (l + r) / 2;
}

LL find(LL from, LL need)
{
	LL l = from;
	LL r = 17LL* INF/10;
	while (r - l > 1)
	{
		LL m = r + l; m /= 2;
		if (suma(from, m, 1) >= need)
		{
			r = m;
		}
		else
		{
			l = m + 1;
		}
	}
	if (r < l)
		swap(l, r);
	if (suma(from, l, 1) >= need)
		return l;
	return r;
}
LL find2(LL cur, LL L, LL R)
{
	LL l = 0;
	LL r = 17LL * INF / 5;
	while (r - l > 1)
	{
		LL m = (r + l); m /= 2;
		if (suma(cur + 2, cur + 2 + m * 2, 2) > L)
		{
			r = m - 1;
		}
		else
		{
			l = m;
		}
	}
	if (r < l)
		swap(l, r);
	if (suma(cur + 2, cur + 2 + r * 2, 2) <= L)
		return r;
	return l;
}

void solve()
{
	LL l, r;
	cin >> l >> r;
	if (l + r == 0)
	{
		cout << 0 << ' ' << l << ' ' << r << endl;
		return;
	}
	LL cur = 0;
	if (l >= r)
	{
		cur = find(cur+1, l - r + 1);
		cur--;
		l -= suma(0, cur, 1);
		if (l == r)
		{
			if (l >= cur + 1)
			{
				l -= cur + 1;
				cur++;
			}
		}
	}
	else
	{
		cur = find(1, r - l);
		r -= suma(0, cur-1, 1);
		cur--;
		if (r - cur - 1 >= l)
		{
			r -= cur + 1;
			cur++;
		}
		if (l == r && l >= cur+1)
		{
			l -= cur + 1;
			cur++;
		}
	}

	if (l >= cur + 2)
	{
		LL x = find2(cur, l, r);
		l -= suma(cur + 2, cur + 2 + 2 * x, 2);
		r -= suma(cur + 1, cur + 1 + 2 * x, 2);
		cur = cur + 2 + x * 2;
	}
	while (r > cur || l > cur)
	{
		if (r > l)
		{
			r -= (cur + 1);
			cur++;
		}
		else
		{
			l -= cur + 1;
			cur++;
		}
	}
	cout << cur  << ' ' << l << ' ' << r << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	FOR(tt, 1, t + 1)
	{
		cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}

