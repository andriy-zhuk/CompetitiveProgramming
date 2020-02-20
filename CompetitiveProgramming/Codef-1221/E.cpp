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

int a, b;
int cnt[30];
vector<int> foo;
bool ok(int x, int y, int z)
{
	if (x >= b && x < a)
		return 0;
	if (y >= b && y < a)
	{
		return 0;
	}
	if (max(x,y) >= 2 * b)
	{
		return 0;
	}
	z += (x >= a);
	z += (y >= a);
	if (z % 2 == 0)
		return 1;
	return 0;
}
void solve(string s)
{
	foo.clear();
	s += 'X';
	int cur = 0;
	FOR(i, 0, SZ(s))
	{
		if (s[i] == 'X')
		{
			if (cur >= b && cur < a)
			{
				cout << "NO" << endl;
				return;
			}
			if (cur >= 2 * b)
			{
				foo.PB(cur);
			}
			else
			{
				if (cur >= a)
				{
					cnt[0]++;
				}
			}
			cur = 0;
		}
		if (s[i] == '.')
			cur++;
	}
	if (foo.size() >= 2)
	{
		cout << "NO" << endl;
		return;
	}
	if (foo.size() == 0)
	{
		if (cnt[0] % 2 == 0)
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
		}
		return;
	}
	int X = foo.back();
	FOR(i, 0, X - a + 1)
	{
		int l = i;
		int r = X - i - a;
		if (ok(l, r, cnt[0]))
		{
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}
int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> a >> b;
		cin >> s;
		cnt[0] = cnt[1] = cnt[2] = 0;
		solve(s);
	}

	return 0;
}