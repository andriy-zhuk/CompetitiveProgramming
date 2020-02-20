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

LL a, b;
int solve(LL a, LL b)
{
	//cout << a << ' ' << b << endl;
	if (a == 0 || b == 0)
		return 1; // 1 == lose
	if (a == 1 || b == 1)
		return 0; // 0 == win
	if (a > b)
		swap(a, b);
	if (b % a == 0)
		return 0;
	LL nxt = b % a;
	//cout << a << ' ' << b << ' ' << nxt << ' ';
	LL count = 0;
	LL cnt1 = 0;
	LL oldB = b;
	b /= a;
	while (b)
	{
		count += b % a;
		b /= a;
		cnt1++;
	}
	if (a % 2 == 1)
		cnt1 = 1;

	//cout << count << endl;
	if ((count*(1+(cnt1>1))) % 2 == 0)
	{
		return solve(nxt, a);
	}
	else
	{
		return 1-solve(nxt, a);
	}
}
string ans[] = { "First","Second" };
int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		cout << ans[solve(a, b)] << endl;
	}
	return 0;
}