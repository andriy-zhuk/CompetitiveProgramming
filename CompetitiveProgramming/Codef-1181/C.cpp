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

int n, m;
LL ans;

string s[1005];


int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	pair<int, string> prev = MP(-1, "---");
	int width = 0;
	cin >> n >> m;
	FOR(i, 0, n)
	{
		cin >> s[i];
	}
	FOR(i, 1, n - 1)
	{
		width = 0;
		FOR(j, 0, m)
		{
			pair<int, string> cur = MP(-2, "   ");
			if (s[i][j] == s[i - 1][j])
			{
				width = 0;
				continue;
			}
			int len = 0;
			while (i + len < n && s[i][j] == s[i + len][j])
				len++;
			bool ok = true;
			if (i - len < 0 || i + 2 * len > n)
			{
				ok = false;
			}
			else
			{
				FOR(k, i - len, i)
				{
					if (s[k][j] != s[i - len][j])
					{
						ok = false;
						break;
					}
				}
				FOR(k, i + len, i + 2 * len)
				{
					if (s[k][j] != s[i + len][j])
					{
						ok = false;
						break;
					}
				}
			}
			if (ok)
			{
				cur.first = len;
				cur.second = ""; cur.second += s[i][j]; cur.second += s[i - len][j]; cur.second += s[i + len][j];
				if (cur == prev)
				{
					width++;
				}
				else
				{
					prev = cur;
					width = 1;
				}
				cerr << i << ' ' << j << ' ' << width << ' ' << prev.first << endl;
				ans += width;
			}
			else
			{
				width = 0;
			}
		}
	}

	cout << ans << endl;



	return 0;
}