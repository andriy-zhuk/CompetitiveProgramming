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

int pref[26][200005];
string s;

int get(int l, int r, int x)
{
	int cur = pref[x][r];
	if (l)
		cur -= pref[x][l - 1];
	return cur;
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> s;
	FOR(i, 0, s.size())
	{
		if (i)
		{
			FOR(j, 0, 26)
			{
				pref[j][i] += pref[j][i - 1];
			}
		}
		FOR(j, 0, 26)
		{
			pref[j][i] += (s[i] - 'a') == j;
		}
	}

	int q;
	cin >> q;
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		r--, l--;
		if (l == r)
		{
			cout << "Yes" << endl;
			continue;
		}
		vector<PII> foo;
		foo.clear();
		FOR(i, 0, 26)
		{
			if (get(l, r, i) != 0)
				foo.PB(MP(get(l, r, i),'a'+i));
		}
		sort(ALL(foo));
		if (foo.size() == 1)
		{
			cout << "No" << endl;
			continue;
		}
		if (foo.size() == 2 && foo[1].f >= foo[0].f && s[l] == foo[1].second && s[r] == foo[1].second)
		{
			cout << "No" << endl;
			continue;
		}
		cout << "Yes" << endl;
	}


	return 0;
}

