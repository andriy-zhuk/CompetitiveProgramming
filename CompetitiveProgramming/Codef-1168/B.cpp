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
const LL mod = INF + 6;

bool check(string s)
{
	
	FOR(i, 0, s.size())
	{
		FOR(x, 1, s.size())
		{
			if (i + 2 * x >= s.size())
				continue;
			if (s[i] == s[i + x] && s[i] == s[i + 2 * x])
			{
				return 1;
			}
		}
	}
	return 0;
}
bool good[10][1 << 9];

void prec()
{
	FOR(k, 0, 9)
	{
		FOR(i, 0, (1 << k))
		{
			string ss = "";
			FOR(j, 0, k)
			{
				if (i & (1 << j))
				{
					ss += '1';
				}
				else
				{
					ss += '0';
				}
			}
			if (check(ss))
			{
				good[k][i] = true;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s;
	cin >> s;
	prec();

	LL ans = 1LL * SZ(s) * (1LL*SZ(s)+1)/2;

	FOR(k, 1, min(SZ(s), 8) + 1)
	{
		FOR(i, 0, SZ(s))
		{
			if (i + k > SZ(s))
				continue;
			int cur = 0;
			FOR(j, i, i + k)
			{
				cur *= 2;
				cur += s[j] - '0';
			}
			if (good[k][cur] == 0)
				ans--;
		}
	}
	cout << ans << endl;

	


	return 0;
}