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
string s;
int used[(1 << 20)];
int cnt[1 << 20];

int dpT[1 << 20];

int dp(int mask)
{
	if (mask == 0)
	{
		return dpT[mask] = 0;
	}
	if (dpT[mask] != -1)
		return dpT[mask];
	if (used[mask])
		return dpT[mask] = cnt[mask];
	int best = 0;
	FOR(i, 0, 20)
	{
		if (mask & (1 << i))
		{
			best = max(best, dp(mask ^ (1 << i)));
		}
	}
	return dpT[mask] = best;
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> s;
	FOR(i, 0, s.size())
	{
		int cur = 0;
		int c = 0;
		FOR(j, i, min(SZ(s), i+20))
		{
			if (cur & (1 << (s[j] - 'a')))
			{
				break;
			}
			else
			{
				c++;
				cur ^= (1 << (s[j] - 'a'));
				used[cur] = true;
				cnt[cur] = c;
			}
		}
	}
	FILL(dpT, -1);
	int best = 0;
	FOR(i, 0, (1 << 20))
	{
		int cur = 0;
		FOR(j, 0, 20)
		{
			if (i & (1 << j)); 
			else
				cur ^= (1 << j);
		}
		if (used[i])
		{
			best = max(best, cnt[i] + dp((1 << 20)-1 - i));
		}
	}
	cout << best << endl;





	return 0;
}

